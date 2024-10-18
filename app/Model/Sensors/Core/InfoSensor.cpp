#include "InfoSensor.h"

#include <algorithm>

InfoSensor::InfoSensor(const std::string& name,
                       const std::string& brand,
                       const std::string& moreInfo,
                       const std::string& label,
                       const std::string& description,
                       const std::string& iconPath,
                       const std::string& unit,
                       int id) : AbstractSensor(name, brand, moreInfo, label, description, iconPath, id), unit(unit) {
}

double InfoSensor::GetAvg() const {
    double sum = std::accumulate(GetInfo().values.begin(), GetInfo().values.end(), 0.0);
    return sum / GetInfo().values.size();
}

double InfoSensor::GetMax() const {
    return *std::max_element(GetInfo().values.begin(), GetInfo().values.end());
}

double InfoSensor::GetMin() const {
    return *std::min_element(GetInfo().values.begin(), GetInfo().values.end());
}

const std::string& InfoSensor::GetUnit() const {
    return unit;
}

