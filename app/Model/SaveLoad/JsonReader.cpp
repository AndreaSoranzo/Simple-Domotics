#include "JsonReader.h"

#include <QJsonArray>

#include "../../Utils/TypeHelper.h"
#include "../Sensors/Distributions/ExponentialDistribution.h"
#include "../Sensors/Distributions/NormalDistribuition.h"
#include "../Sensors/Distributions/RandomDistribution.h"
#include "../Sensors/Distributions/UniformDistribution.h"
#include "../Sensors/GroundSensor.h"
#include "../Sensors/HumiditySensor.h"
#include "../Sensors/SmokeSensor.h"
#include "../Sensors/SolarSensor.h"
#include "../Sensors/TemperatureSensor.h"
#include "../Sensors/WindSensor.h"

// return nullptr if something goes wrong
AbstractSensor* JsonReader::Read(const QJsonObject& json) {
    // first read the generic info and create a sensor based on that
    AbstractSensor* sensor = nullptr;
    QJsonValue typeSensor = json.value("type");
    if (typeSensor.isUndefined()) {
        return nullptr;
    }

    switch (TypeHelper::ToSensorType(typeSensor.toString().toStdString())) {
        case SensorType::Ground:
            sensor = CreateGroundSensor(json);
            cache.clear();
            return sensor;
            break;
        case SensorType::Humidity:
            sensor = CreateHumiditySensor(json);
            break;
        case SensorType::Smoke:
            sensor = CreateSmokeSensor(json);
            break;
        case SensorType::Solar:
            sensor = CreateSolarSensor(json);
            break;
        case SensorType::Temperature:
            sensor = CreateGroundSensor(json);
            break;
        case SensorType::Wind:
            sensor = CreateWindSensor(json);
            break;
        default:
            return sensor;
    }
    if (cache.count(sensor->GetSensorId()) > 0) {
        delete cache[sensor->GetSensorId()];
    }
    cache[sensor->GetSensorId()] = sensor;

    //  read the distribution and create the distribution
    AbstractDistribution* distribution = nullptr;
    QJsonObject distributioninfo = json.value("distribution").toObject();
    QJsonValue typedistribution = distributioninfo.value("type");
    if (typedistribution.isUndefined()) {
        delete sensor;
        return nullptr;
    }
    switch (TypeHelper::ToDistributionType(typedistribution.toString().toStdString())) {
        case DistributionType::Uniform:
            distribution = CreateUniformDistribution(distributioninfo);
            break;
        case DistributionType::Exponential:
            cache.clear();
            return sensor;
        case DistributionType::Normal:
            distribution = CreateNormalDistribuition(distributioninfo);
            break;
        case DistributionType::Random:
            distribution = CreateRandomDistribution(distributioninfo);
            break;
        default:
            delete sensor;
            return nullptr;
    }
    for (const QJsonValue& value : json["genericInfo"].toObject()["values"].toArray()) {
        sensor->GetInfo().values.push_back(value.toDouble());
    }

    // link sensor and distribution and return it
    sensor->SetDistribution(distribution);
    cache.clear();
    return sensor;
}

JsonReader::~JsonReader() {
    cache.clear();
}

AbstractSensor* JsonReader::CreateHumiditySensor(const QJsonObject& json) const {
    QJsonObject genericinfo = json["genericInfo"].toObject();
    return new HumiditySensor(genericinfo["name"].toString().toStdString(),
                              genericinfo["brand"].toString().toStdString(),
                              genericinfo["moreinfo"].toString().toStdString(),
                              genericinfo["id"].toInt());
}

AbstractSensor* JsonReader::CreateTemperatureSensor(const QJsonObject& json) const {
    QJsonObject genericinfo = json["genericInfo"].toObject();
    if (genericinfo.value("batteries").isUndefined()) {  // if a sensor has batteries
        return new TemperatureSensor(genericinfo["name"].toString().toStdString(),
                                     genericinfo["brand"].toString().toStdString(),
                                     genericinfo["moreinfo"].toString().toStdString(),
                                     genericinfo["id"].toInt());
    }
    return new TemperatureSensor(genericinfo["name"].toString().toStdString(),
                                 genericinfo["brand"].toString().toStdString(),
                                 genericinfo["moreinfo"].toString().toStdString(),
                                 genericinfo["batteries"].toInt(),
                                 genericinfo["batterycharge"].toInt(),
                                 genericinfo["id"].toInt());
}

AbstractSensor* JsonReader::CreateWindSensor(const QJsonObject& json) const {
    QJsonObject genericinfo = json["genericInfo"].toObject();
    return new WindSensor(genericinfo["name"].toString().toStdString(),
                          genericinfo["brand"].toString().toStdString(),
                          genericinfo["moreinfo"].toString().toStdString(),
                          genericinfo["id"].toInt());
}

AbstractSensor* JsonReader::CreateSolarSensor(const QJsonObject& json) const {
    QJsonObject genericinfo = json["genericInfo"].toObject();
    return new SolarSensor(genericinfo["name"].toString().toStdString(),
                           genericinfo["brand"].toString().toStdString(),
                           genericinfo["cerification"].toString().toStdString(),
                           genericinfo["moreinfo"].toString().toStdString(),
                           genericinfo["id"].toInt());
}

AbstractSensor* JsonReader::CreateSmokeSensor(const QJsonObject& json) const {
    QJsonObject genericinfo = json["genericInfo"].toObject();
    return new SmokeSensor(genericinfo["name"].toString().toStdString(),
                           genericinfo["brand"].toString().toStdString(),
                           json["danger"].toInt(),
                           genericinfo["moreinfo"].toString().toStdString(),
                           genericinfo["id"].toInt());
}

AbstractSensor* JsonReader::CreateGroundSensor(const QJsonObject& json) const {
    QJsonObject genericinfo = json["genericInfo"].toObject();
    return new GroundSensor(genericinfo["name"].toString().toStdString(),
                            genericinfo["brand"].toString().toStdString(),
                            json["danger"].toInt(),
                            genericinfo["moreinfo"].toString().toStdString(),
                            genericinfo["id"].toInt());
}

AbstractDistribution* JsonReader::CreateNormalDistribuition(const QJsonObject& json) const {
    return new NormalDistribuition(json["amount"].toInt(),
                                   json["mean"].toInt(),
                                   json["noise"].toInt());
}

AbstractDistribution* JsonReader::CreateRandomDistribution(const QJsonObject& json) const {
    return new RandomDistribution(json["amount"].toInt(),
                                  json["min"].toInt(),
                                  json["max"].toInt());
}

AbstractDistribution* JsonReader::CreateUniformDistribution(const QJsonObject& json) const {
    return new UniformDistribution(json["amount"].toInt(),
                                   json["min"].toInt(),
                                   json["max"].toInt());
}