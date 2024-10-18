#ifndef NotificationManager_H
#define NotificationManager_H

#include <sstream>
#include <vector>

#include "../Sensors//Core/AbstractSensor.h"
#include "../Sensors/Core/AlertSensor.h"
#include "Notification.h"

class NotificationCreator {
   public:
    static Notification OnSensorCreate(const AbstractSensor& sens);
    static Notification OnEdit(const AbstractSensor& sens);
    static Notification OnAlert(const AlertSensor& sens);
    static Notification OnAddError();
};

#endif  // !NotificationManager_H