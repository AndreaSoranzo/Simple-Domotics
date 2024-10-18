#include "TypeHelper.h"

#include <algorithm>
#include <stdexcept>

const std::map<std::string, SensorType> TypeHelper::sensors = {
    {"Ground_Sensor", SensorType::Ground},
    {"Humidity_Sensor", SensorType::Humidity},
    {"Smoke_Sensor", SensorType::Smoke},
    {"Solar_Sensor", SensorType::Solar},
    {"Temperature_Sensor", SensorType::Temperature},
    {"Wind_Sensor", SensorType::Wind},

};

const std::map<std::string, DistributionType> TypeHelper::distributions = {
    {"Uniform", DistributionType::Uniform},
    {"Exponential", DistributionType::Exponential},
    {"Normal", DistributionType::Normal},
    {"Random", DistributionType::Random},

};
const std::map<std::string, SolarCertification> TypeHelper::certificaions = {
    {"A1", SolarCertification::A1},
    {"A2", SolarCertification::A2},
    {"B1", SolarCertification::B1},
    {"B2", SolarCertification::B2},
    {"Unclassified", SolarCertification::Unclassified}

};

SensorType TypeHelper::ToSensorType(const std::string& s) {
    try {
        return sensors.at(s);  // need to use at beacause operator[] isnt const
    } catch (std::out_of_range&) {
        return SensorType::None;
    }
}

DistributionType TypeHelper::ToDistributionType(const std::string& s) {
    try {
        return distributions.at(s);  // need to use at beacause operator[] isnt const
    } catch (std::out_of_range&) {
        return DistributionType::None;
    }
}

std::string TypeHelper::ToSensorName(const SensorType& st) {
    auto it = std::find_if(std::begin(sensors), std::end(sensors),
                           [&st](const auto& p) {
                               return p.second == st;
                           });

    if (it != std::end(sensors)) {
        return (*it).first;
    }
    return "";
}

std::string TypeHelper::ToDistributionName(const DistributionType& dt) {
    auto it = std::find_if(std::begin(distributions), std::end(distributions),
                           [&dt](const auto& p) {
                               return p.second == dt;
                           });

    if (it != std::end(distributions)) {
        return (*it).first;
    }
    return "";
}

std::vector<std::string> TypeHelper::GetAllSolarCertification() {
    std::vector<std::string> types;
    for (const auto& type : certificaions) {
        types.push_back(type.first);
    }
    return types;
}

std::vector<std::string> TypeHelper::GetAllSensorNames() {
    std::vector<std::string> types;
    for (const auto& type : sensors) {
        types.push_back(type.first);
    }
    return types;
}

std::vector<std::string> TypeHelper::GetAllDistributionNames() {
    std::vector<std::string> types;
    for (const auto& type : distributions) {
        types.push_back(type.first);
    }
    return types;
}
