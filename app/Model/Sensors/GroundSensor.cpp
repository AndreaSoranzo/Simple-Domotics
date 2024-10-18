#include "GroundSensor.h"

#include "../../Utils/TypeHelper.h"

GroundSensor::GroundSensor(const std::string& name, const std::string& brand, double dangerLV, const std::string& moreInfo, int id)
    : AlertSensor(name, brand, moreInfo, dangerLV,
                  "The sensor has detected that a earthquake is about to come, consider finding shelter, if not present or not available go under a desk or something solid.",
                  TypeHelper::ToSensorName(SensorType::Ground),
                  "This is a sensor that tracks the movement of tectonic plates",
                  ":assets/icons/ground.svg",
                  id) {
}

void GroundSensor::accept(ISensorClassVisitor &visitor) {
    visitor.visit(*this);
}

void GroundSensor::accept(ISensorClassVisitorConst &visitor) const {
    visitor.visit(*this);
}

void GroundSensor::accept(ISensorTypeVisitor& visitor) {
    visitor.visit(*this);
}

void GroundSensor::accept(ISensorTypeVisitorConst& visitor) const {
    visitor.visit(*this);
}
