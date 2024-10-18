#include "TemperatureSensor.h"

#include "../../Utils/RandomGenerator.h"
#include "../../Utils/TypeHelper.h"

TemperatureSensor::TemperatureSensor(const std::string& name,
                                     const std::string& brand,
                                     const std::string& moreInfo,
                                     unsigned int batteries,
                                     unsigned int intitialCharge,
                                     int id)
    : InfoSensor(name, brand, moreInfo,
                 TypeHelper::ToSensorName(SensorType::Temperature),
                 "This is a sensor that tracks the temperature in your kitchen",
                 ":assets/icons/temperature.svg",
                 "C°", id),

      batteries(batteries) {
    if (batteries > 0) {
        if (intitialCharge > 100) {  // 101 is the default
            currentCharge = RandomGenerator<int>::Generate(static_cast<int>(batteries) * 2 % 100, 100);
        } else {
            currentCharge = intitialCharge;
        }
    } else {
        currentCharge = 100;
    }
}

bool TemperatureSensor::IsPortable() const {
    return batteries > 0;
}

unsigned int TemperatureSensor::GetBatteries() const {
    return batteries;
}

void TemperatureSensor::SetBatteries(unsigned int batteries) {
    if (batteries == 0) {
        currentCharge = 100;
        return;
    }

    this->batteries = batteries;
    currentCharge = RandomGenerator<int>::Generate(static_cast<int>(batteries) * 2 % 100, 100);
}

unsigned int TemperatureSensor::GetCurrentCharge() const {
    return currentCharge;
}

void TemperatureSensor::accept(ISensorClassVisitor& visitor) {
    visitor.visit(*this);
}

void TemperatureSensor::accept(ISensorClassVisitorConst& visitor) const {
    visitor.visit(*this);
}

void TemperatureSensor::accept(ISensorTypeVisitor& visitor) {
    visitor.visit(*this);
}

void TemperatureSensor::accept(ISensorTypeVisitorConst& visitor) const {
    visitor.visit(*this);
}
