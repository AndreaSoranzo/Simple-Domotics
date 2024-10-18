#include "SolarSensor.h"

#include "../../Utils/TypeHelper.h"

SolarSensor::SolarSensor(const std::string& name,
                         const std::string& brand,
                         const std::string& certification,
                         const std::string& moreInfo,
                         int id)
    : InfoSensor(name, brand, moreInfo,
                 TypeHelper::ToSensorName(SensorType::Solar),
                 "This is a sensor that tracks the sun lights",
                 ":assets/icons/solar.svg",
                 "V",
                 id),
      certification(certification) {
}

const std::string& SolarSensor::GetCertification() const {
    return certification;
}

void SolarSensor::SetCertificaion(const std::string& certificaion) {
    this->certification = certificaion;
}

void SolarSensor::accept(ISensorClassVisitor &visitor) {
    visitor.visit(*this);
}

void SolarSensor::accept(ISensorClassVisitorConst &visitor) const {
    visitor.visit(*this);
}

void SolarSensor::accept(ISensorTypeVisitor& visitor) {
    visitor.visit(*this);
}

void SolarSensor::accept(ISensorTypeVisitorConst& visitor) const {
    visitor.visit(*this);
}
