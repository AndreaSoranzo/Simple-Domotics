#include "Model.h"

#include <algorithm>

#include "../Utils/TimeHelper.h"
#include "NotificationSystem/NotificationCreator.h"
#include "Sensors/Distributions/NormalDistribuition.h"
#include "Sensors/HumiditySensor.h"

void Model::NotifyUser() const {
    for (IUserInfoObserver* observer : userObservers) {
        observer->Notify(user.GetName(), user.GetMail(), user.GetScheme());
    }
}

void Model::NotifyAddSensor(const std::vector<const SensorItem*>& list) const {
    for (ISensorListObserver* observer : sensorObservers) {
        observer->NotifyAdd(list);
    }
}

void Model::NotifySearch(const std::vector<unsigned int>& list) const {
    for (ISensorListObserver* observer : sensorObservers) {
        observer->NotifySearch(list);
    }
}

void Model::NotifySimulation(const std::vector<double>& list) const {
    for (ISensorListObserver* observer : sensorObservers) {
        observer->NotifySimulation(list);
    }
}

void Model::NotifyNotification(const Notification& notification) const {
    for (INotificationObserver* observer : notificationObservers) {
        observer->Notify(notification.title, notification.text, notification.time);
    }
}

Model::Model(): userError(false) {
}

Model::~Model()
{
    userObservers.clear();
    notificationObservers.clear();
    sensorObservers.clear();
}

void Model::InitUser() {
    try {
        user = LoadUser("user.qam");
        NotifyUser();
    } catch (std::runtime_error&) {
        userError = true;
    }
}

void Model::CreateSensor(const SensorCreator& sensorCreator) {
    AbstractSensor* sensor = sensorCreator.Instantiate();
    bool ok = sm.AddSensor(sensor);
    if (ok) {
        NotifyNotification(NotificationCreator::OnSensorCreate(*sensor));
        NotifyAddSensor({new SensorItem{sensor->GetSensorId(), sensor->GetIcon(), sensor->GetInfo().name, sensor->GetInfo().brand}});
    } else {
        NotifyNotification(NotificationCreator::OnAddError());
    }
}

void Model::DeleteSensor(unsigned int idx) {
    sm.RemoveSensor(idx);
}

void Model::SendAllSensors() const {
    std::vector<const SensorItem*> itemList;
    for (AbstractSensor* sensor : sm.GetAll()) {
        itemList.push_back(new SensorItem{sensor->GetSensorId(), sensor->GetIcon(), sensor->GetInfo().name, sensor->GetInfo().brand});
    }
    NotifyAddSensor(itemList);
}

void Model::SendUpdatedSensor(unsigned int idx) const {
    AbstractSensor* sensor = sm.GetSensor(idx);
    NotifyAddSensor({new SensorItem{sensor->GetSensorId(), sensor->GetIcon(), sensor->GetInfo().name, sensor->GetInfo().brand}});
    NotifyNotification(NotificationCreator::OnEdit(*sensor));
}

AbstractSensor* Model::GetSensor(unsigned int idx) const {
    return sm.GetSensor(idx);
}

void Model::SendSimulationValues(unsigned int idx) const {
    if (!sm.GetSensor(idx)->GetInfo().values.empty()) {
        NotifySimulation(sm.GetSensor(idx)->GetInfo().values);
    }
}

void Model::StartSimulation(unsigned int idx) {
    AbstractSensor* sensor = sm.GetSensor(idx);
    sensor->Generate();
    AlertSensor* aSensor = dynamic_cast<AlertSensor*>(sensor);
    if (aSensor) {
        std::vector<double> values = aSensor->GetInfo().values;
        auto it = find_if(values.rbegin(), values.rend(), [](int val) -> bool { return val >= 1; });
        if (it != values.rend()) {
            double position = static_cast<double>(std::distance(it, values.rend()) - 1);
            std::string time = TimeHelper::ConvertToHourOfDay(position / values.size() * 23);
            aSensor->SetLastTrigger(time);
            NotifyNotification(NotificationCreator::OnAlert(*aSensor));
        } else {
            aSensor->SetLastTrigger("Never");
        }
    }

    NotifySimulation(sensor->GetInfo().values);
}

void Model::ResetSimulation(unsigned int idx) {
    sm.GetSensor(idx)->GetInfo().values.clear();
}

void Model::Search(const Query& query) const {
    QueryResults qr = sm.Search(query);
    NotifySearch(qr.ToSensorId());
}

bool Model::StoreSensors(const std::string& path) {
    return slm.Save(sm.GetAll(), path);
}

bool Model::LoadSensors(const std::string& path) {
    try {
        std::vector<AbstractSensor*> sensors = slm.Load(path);
        sm.Inizialize(sensors);
        return true;
    } catch (const std::runtime_error& e) {
        return false;
    }
}

void Model::UpdateUser(const std::string& name, const std::string& mail, int palette) {
    user.SetName(name);
    user.SetMail(mail);
    user.SetScheme(palette);
    bool ok = SaveUser(user, "user.qam");
    if (!ok) {
        user.Revert();
    }
    NotifyUser();
}

bool Model::UserExist() const {
    return !userError;
}

void Model::AddUserObserver(IUserInfoObserver* observer) {
    userObservers.push_back(observer);
}

void Model::AddNotificationObserver(INotificationObserver* observer) {
    notificationObservers.push_back(observer);
}

void Model::AddSensorObserver(ISensorListObserver* observer) {
    sensorObservers.push_back(observer);
}
