#include "WindSensor.h"

#include "../../Utils/TypeHelper.h"

WindSensor::WindSensor(const std::string& name, const std::string& brand, const std::string& moreInfo, int id)
    : InfoSensor(name, brand, moreInfo,
                 TypeHelper::ToSensorName(SensorType::Wind),
                 "This is a sensor that tracks the wind every day",
                 ":assets/icons/wind.svg",
                 "Km/h",
                 id) {
}

void WindSensor::accept(ISensorClassVisitor &visitor){
    visitor.visit(*this);
}

void WindSensor::accept(ISensorClassVisitorConst &visitor) const {
    visitor.visit(*this);
}

void WindSensor::accept(ISensorTypeVisitor& visitor) {
    visitor.visit(*this);
}

void WindSensor::accept(ISensorTypeVisitorConst& visitor) const {
    visitor.visit(*this);
}
