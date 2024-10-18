#include "SmokeSensor.h"

#include "../../Utils/TypeHelper.h"

SmokeSensor::SmokeSensor(const std::string& name, const std::string& brand, double dangerLV, const std::string& moreInfo, int id)
    : AlertSensor(name, brand, moreInfo, dangerLV,
                  "The sensor has detected that there is a leak of smoke/toxic fumes around, grab an antigas mask or exit the building immediately",
                  TypeHelper::ToSensorName(SensorType::Smoke),
                  "This is a sensor that tracks how much smoke there is in your house",
                  ":assets/icons/smoke.svg",
                  id) {
}

void SmokeSensor::accept(ISensorClassVisitor &visitor) {
    visitor.visit(*this);
}

void SmokeSensor::accept(ISensorClassVisitorConst &visitor) const {
    visitor.visit(*this);
}

void SmokeSensor::accept(ISensorTypeVisitor& visitor) {
    visitor.visit(*this);
}

void SmokeSensor::accept(ISensorTypeVisitorConst& visitor) const {
    visitor.visit(*this);
}
