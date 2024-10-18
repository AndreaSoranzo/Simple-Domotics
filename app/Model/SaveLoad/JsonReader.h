#ifndef JsonReader_H
#define JsonReader_H

#include <QJsonObject>
#include <map>

#include "../Sensors/Core/AbstractSensor.h"

class JsonReader {
   private:
    std::map<unsigned int, AbstractSensor*> cache;

    AbstractSensor* CreateHumiditySensor(const QJsonObject& json) const;
    AbstractSensor* CreateTemperatureSensor(const QJsonObject& json) const;
    AbstractSensor* CreateWindSensor(const QJsonObject& json) const;
    AbstractSensor* CreateSolarSensor(const QJsonObject& json) const;
    AbstractSensor* CreateSmokeSensor(const QJsonObject& json) const;
    AbstractSensor* CreateGroundSensor(const QJsonObject& json) const;
    AbstractDistribution* CreateNormalDistribuition(const QJsonObject& json) const;
    AbstractDistribution* CreateRandomDistribution(const QJsonObject& json) const;
    AbstractDistribution* CreateUniformDistribution(const QJsonObject& json) const;

   public:
    AbstractSensor* Read(const QJsonObject& json);
    ~JsonReader();
};

#endif  // !JsonReader_H