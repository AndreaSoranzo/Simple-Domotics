#include "NotificationCreator.h"

#include "../../Utils/TimeHelper.h"

Notification NotificationCreator::OnSensorCreate(const AbstractSensor& sens) {
    std::ostringstream text;
    text << "A sensor named " << sens.GetInfo().name << " of type " << sens.ToString()
         << " has been added to the list of sensor.\n"
         << sens.GetDescription() << "\n"
         << "If you want to modify it or delete it head to the list view and hover on the sensor, than click one of the 2 options.";
    return Notification{"New sensor added", text.str(), TimeHelper::GetCurrentTime()};
}

Notification NotificationCreator::OnAlert(const AlertSensor& sens) {
    std::ostringstream text;
    text << "A sensor named " << sens.GetInfo().name << " of type " << sens.ToString() << " with danger : " << sens.GetDangerLV()
         << " has triggered an alert at" << sens.GetLastTrigger() << ".\n"
         << sens.GetAlertText();
    return Notification{"Sensor alert", text.str(), TimeHelper::GetCurrentTime()};
}

Notification NotificationCreator::OnEdit(const AbstractSensor& sens) {
    std::ostringstream text;
    text << "A sensor named " << sens.GetInfo().name << " of type " << sens.ToString()
         << " has been modified.\n";
    return Notification{"Sensor modified", text.str(), TimeHelper::GetCurrentTime()};
}

Notification NotificationCreator::OnAddError() {
    std::ostringstream text;
    text << "Cannot add a sensor with the same name in the same list\n";
    return Notification{"Add error", text.str(), TimeHelper::GetCurrentTime()};
}
