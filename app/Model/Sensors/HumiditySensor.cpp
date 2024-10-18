#include "HumiditySensor.h"

#include "../../Utils/TypeHelper.h"

HumiditySensor::HumiditySensor(const std::string& name, const std::string& brand, const std::string& moreInfo, int id)
    : InfoSensor(name, brand, moreInfo,
                 TypeHelper::ToSensorName(SensorType::Humidity),
                 "This is a sensor that tracks the humidity in your bathroom every day",
                 ":assets/icons/humid.svg",
                 "%",
                 id) {
}

void HumiditySensor::accept(ISensorClassVisitor &visitor) {
    visitor.visit(*this);
}

void HumiditySensor::accept(ISensorClassVisitorConst &visitor) const {
    visitor.visit(*this);
}

void HumiditySensor::accept(ISensorTypeVisitor& visitor) {
    visitor.visit(*this);
}

void HumiditySensor::accept(ISensorTypeVisitorConst& visitor) const {
    visitor.visit(*this);
}
