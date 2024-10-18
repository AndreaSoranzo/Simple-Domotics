#include "AbstractSensor.h"

unsigned int AbstractSensor::products = 0;

AbstractSensor::AbstractSensor(const std::string& name,
                               const std::string& brand,
                               const std::string& moreInfo,
                               const std::string& label,
                               const std::string& description,
                               const std::string& iconPath,
                               int id) : label(label), description(description), iconPath(iconPath), currentDistribution(nullptr) {
    info.name = name;
    info.brand = brand;
    info.moreInfo = moreInfo;
    if (id > -1) {
        this->id = id;
    } else {
        this->id = AbstractSensor::products++;
    }
}

AbstractSensor::~AbstractSensor() {
    delete currentDistribution;
}

void AbstractSensor::SetDistribution(AbstractDistribution* newDistribution) {
    delete currentDistribution;
    currentDistribution = newDistribution;
}

AbstractDistribution& AbstractSensor::GetDistribution() const {
    return *currentDistribution;
}

const AbstractSensor::GenericSensorInfo& AbstractSensor::GetInfo() const {
    return info;
}

AbstractSensor::GenericSensorInfo& AbstractSensor::GetInfo() {
    return info;
}

unsigned int AbstractSensor::GetSensorId() const {
    return id;
}

const std::string& AbstractSensor::ToString() const {
    return label;
}

const std::string& AbstractSensor::GetDescription() const {
    return description;
}

const std::string& AbstractSensor::GetIcon() const {
    return iconPath;
}

void AbstractSensor::Generate() {
    if (currentDistribution == nullptr) {
        return;
    }
    if (!info.values.empty()) {
        info.values.clear();
    }

    info.values = currentDistribution->generate();
}
