#include "Controller.h"

Controller::Controller(Model& model, MainWindow& view) : model(model),
                                                         view(view),
                                                         sensorCreator(*view.GetManagmentWindow()->GetAddPanel()),
                                                         editorInjector(view.GetSensorWindow()->GetEditPanel()),
                                                         infoViewSelector(view.GetSensorWindow()->GetSensorViewer()) {
    // assign observers
    model.AddUserObserver(&view);
    model.AddUserObserver(view.GetHomeWindow());
    model.AddUserObserver(view.GetSensorWindow());
    model.AddUserObserver(view.GetNotificationWindow());
    model.AddUserObserver(view.GetManagmentWindow());

    model.AddNotificationObserver(view.GetNotificationWindow());

    model.AddSensorObserver(view.GetSensorWindow());

    // connects
    connect(&view, &MainWindow::OnUpdateSettings, this, &Controller::UpdateUserInfo);

    connect(view.GetManagmentWindow()->GetAddPanel(), &AddPanel::OnCreateSensor, this, &Controller::CreateSensor);

    connect(view.GetSensorWindow()->GetListPanel(), &ListPanel::OnDelete, this, &Controller::DeleteSensor);
    connect(view.GetSensorWindow()->GetListPanel(), &ListPanel::OnSearch, this, &Controller::SearchSensor);
    connect(view.GetSensorWindow()->GetListPanel(), &ListPanel::OnEdit, this, &Controller::UpdateSensor);
    connect(view.GetSensorWindow()->GetEditPanel(), &EditPanel::OnEditComplete, this, &Controller::UpdateItemSensor);

    connect(view.GetSensorWindow()->GetListPanel(), &ListPanel::OnInspect, this, &Controller::InspectSensor);

    connect(view.GetSensorWindow()->GetSensorViewer(), &SensorViewer::OnSimulationStart, this, &Controller::StartSimulation);
    connect(view.GetSensorWindow()->GetSensorViewer(), &SensorViewer::OnSimulationReset, this, &Controller::ResetSimulation);

    connect(view.GetManagmentWindow()->GetManagmentPanel(), &ManagmentPanel::OnSave, this, &Controller::SaveSensors);
    connect(view.GetManagmentWindow()->GetManagmentPanel(), &ManagmentPanel::OnLoad, this, &Controller::LoadSensors);

    model.InitUser();
}

void Controller::Init() const {
    if (!model.UserExist()) {
        view.OpenUserSettings(true);
    }
    view.show();
}

void Controller::UpdateUserInfo(const QString& name, const QString& mail, int palette) {
    model.UpdateUser(name.toStdString(), mail.toStdString(), palette);
}

void Controller::CreateSensor() {
    model.CreateSensor(sensorCreator);
}

void Controller::UpdateSensor(unsigned int idx) {
    AbstractSensor* sensor = model.GetSensor(idx);
    sensor->accept(editorInjector);
}

void Controller::UpdateItemSensor(unsigned int idx) const {
    model.SendUpdatedSensor(idx);
}

void Controller::DeleteSensor(unsigned int idx) {
    model.DeleteSensor(idx);
}

void Controller::SearchSensor(const QString& queryText, const QString& queryFilter, bool match) const {
    Query query(queryText.toStdString(), queryFilter.toStdString(), match);
    model.Search(query);
}

void Controller::InspectSensor(unsigned int idx) {
    AbstractSensor* sensor = model.GetSensor(idx);
    sensor->accept(infoViewSelector);
    model.SendSimulationValues(idx);
}

void Controller::StartSimulation(unsigned int idx) {
    model.StartSimulation(idx);
}

void Controller::ResetSimulation(unsigned int idx) {
    model.ResetSimulation(idx);
}

void Controller::SaveSensors(const QString& path) {
    view.SaveMsg(model.StoreSensors(path.toStdString()));
}

void Controller::LoadSensors(const QString& path) {
    if (model.LoadSensors(path.toStdString())) {
        view.GetSensorWindow()->GetListPanel()->ClearAllItems();
        model.SendAllSensors();
        view.LoadMsg(true);
    } else {
        view.LoadMsg(false);
    }
}
