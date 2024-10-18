#ifndef Model_H
#define Model_H

#include <string>
#include <vector>

#include "../Controller/SensorCreator.h"
#include "../Observers/INotificationObserver.h"
#include "../Observers/ISensorListObserver.h"
#include "../Observers/IUserInfoObserver.h"
#include "Managers/SaveLoadManager.h"
#include "Managers/SensorManager.h"
#include "NotificationSystem/Notification.h"
#include "User/UserData.h"
#include "User/UserDataLoader.h"

class Model {
   private:
    SensorManager sm;
    SaveLoadManager slm;

    UserData user;
    bool userError;

    std::vector<IUserInfoObserver*> userObservers;
    std::vector<INotificationObserver*> notificationObservers;
    std::vector<ISensorListObserver*> sensorObservers;

    void NotifyUser() const;
    void NotifyAddSensor(const std::vector<const SensorItem*>& list) const;
    void NotifySearch(const std::vector<unsigned int>& list) const;
    void NotifySimulation(const std::vector<double>& list) const;
    void NotifyNotification(const Notification& notification) const;

   public:
    Model();
    ~Model();

    void InitUser();

    void CreateSensor(const SensorCreator& sensorCreator);
    void DeleteSensor(unsigned int idx);
    void SendAllSensors() const;
    void SendUpdatedSensor(unsigned int idx) const;
    AbstractSensor* GetSensor(unsigned int idx) const;
    void SendSimulationValues(unsigned int idx) const;
    void StartSimulation(unsigned int idx);
    void ResetSimulation(unsigned int idx);

    void Search(const Query& query) const;

    bool StoreSensors(const std::string& path);
    bool LoadSensors(const std::string& path);

    void UpdateUser(const std::string& name, const std::string& mail, int palette);
    bool UserExist() const;

    void AddUserObserver(IUserInfoObserver* observer);
    void AddNotificationObserver(INotificationObserver* observer);
    void AddSensorObserver(ISensorListObserver* observer);
};

#endif  // !Model_H