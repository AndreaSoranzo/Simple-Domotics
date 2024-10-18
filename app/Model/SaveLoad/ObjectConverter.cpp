#include "ObjectConverter.h"

#include "JsonDistributionVisitor.h"
#include "JsonSensorVisitor.h"

QJsonObject ObjectConverter::ToJson(const AbstractSensor& sensor) const {
    JsonSensorVisitor svisitor;
    JsonDistributionVisitor dvisitor;
    sensor.accept(svisitor);
    sensor.GetDistribution().accept(dvisitor);
    QJsonObject obj = svisitor.GetJsonObject();
    obj.insert("distribution", dvisitor.GetJsonObject());
    return obj;
}

AbstractSensor* ObjectConverter::ToObj(const QJsonObject& json) {
    return reader.Read(json);
}