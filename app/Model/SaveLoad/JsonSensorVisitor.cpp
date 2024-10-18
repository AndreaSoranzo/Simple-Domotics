#include "JsonSensorVisitor.h"

void JsonSensorVisitor::visit(const HumiditySensor& sens) {
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant(sens.ToString().c_str()));
    obj.insert("genericInfo", ConvertGenericInfo(sens));
    json = obj;
}

void JsonSensorVisitor::visit(const WindSensor& sens) {
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant(sens.ToString().c_str()));
    obj.insert("genericInfo", ConvertGenericInfo(sens));
    json = obj;
}

void JsonSensorVisitor::visit(const TemperatureSensor& sens) {
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant(sens.ToString().c_str()));
    obj.insert("genericInfo", ConvertGenericInfo(sens));
    // EXTRA
    if (sens.IsPortable()) {
        obj.insert("batteries", QJsonValue::fromVariant(sens.GetBatteries()));
        obj.insert("batterycharge", QJsonValue::fromVariant(sens.GetCurrentCharge()));
    }

    json = obj;
}

void JsonSensorVisitor::visit(const SolarSensor& sens) {
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant(sens.ToString().c_str()));
    obj.insert("genericInfo", ConvertGenericInfo(sens));
    // EXTRA
    obj.insert("cerification", QJsonValue::fromVariant(sens.GetCertification().c_str()));
    json = obj;
}

void JsonSensorVisitor::visit(const GroundSensor& sens) {
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant(sens.ToString().c_str()));
    obj.insert("genericInfo", ConvertGenericInfo(sens));
    obj.insert("danger", QJsonValue::fromVariant(sens.GetDangerLV()));
    json = obj;
}

void JsonSensorVisitor::visit(const SmokeSensor& sens) {
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant(sens.ToString().c_str()));
    obj.insert("genericInfo", ConvertGenericInfo(sens));
    obj.insert("danger", QJsonValue::fromVariant(sens.GetDangerLV()));
    json = obj;
}

QJsonObject JsonSensorVisitor::GetJsonObject() const {
    return json;
};

QJsonArray JsonSensorVisitor::ConvertSimulationValues(const std::vector<double>& list) const {
    QJsonArray simulationValues;
    for (double val : list) {
        simulationValues.push_back(val);
    }
    return simulationValues;
}

QJsonObject JsonSensorVisitor::ConvertGenericInfo(const AbstractSensor& sens) const {
    QJsonObject genericInfoObj;
    genericInfoObj.insert("id", QJsonValue::fromVariant(sens.GetSensorId()));
    genericInfoObj.insert("name", QJsonValue::fromVariant(sens.GetInfo().name.c_str()));
    genericInfoObj.insert("brand", QJsonValue::fromVariant(sens.GetInfo().brand.c_str()));
    genericInfoObj.insert("moreinfo", QJsonValue::fromVariant(sens.GetInfo().moreInfo.c_str()));
    genericInfoObj.insert("values", ConvertSimulationValues(sens.GetInfo().values));
    return genericInfoObj;
}
