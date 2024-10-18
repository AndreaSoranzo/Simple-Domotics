#ifndef ObjectConverter_H
#define ObjectConverter_H

#include <QJsonObject>

#include "../Sensors/Core/AbstractSensor.h"
#include "JsonReader.h"

class ObjectConverter {
   private:
    JsonReader reader;

   public:
    QJsonObject ToJson(const AbstractSensor& sensor) const;
    AbstractSensor* ToObj(const QJsonObject& json);
};

#endif  // !ObjectConverter_H