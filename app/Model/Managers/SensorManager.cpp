#include "SensorManager.h"

#include <algorithm>
#include <stdexcept>

#include "../Query/QueryRunner.h"
#include "../Query/Strategy/TextQueryStrategy.h"
#include "../Query/Strategy/TypeQueryStrategy.h"

SensorManager::~SensorManager() {
    Clear();
}

bool SensorManager::AddSensor(AbstractSensor* newSensor) {
    if (std::find_if(sensors.begin(), sensors.end(), [&newSensor](const auto& s) -> bool { return s.second->GetInfo().name == newSensor->GetInfo().name; }) != sensors.end()) {
        delete newSensor;
        return 0;
    }
    sensors[newSensor->GetSensorId()] = newSensor;
    return 1;
}

void SensorManager::RemoveSensor(unsigned int id) {
    std::map<unsigned int, AbstractSensor*>::const_iterator it = sensors.find(id);
    if (it != sensors.end()) {
        delete it->second;
        sensors.erase(it);
    }
}

unsigned int SensorManager::GetSize() const {
    return sensors.size();
}

bool SensorManager::IsEmpty() const {
    return sensors.empty();
}

const QueryResults SensorManager::Search(const Query& query) const {
    if (query.GetQueryText().empty() && query.GetTypeChoise().empty()) {
        QueryResults results;
        for (auto& sensor : sensors) {
            results.AddResult(sensor.second, 0);
        }
        return results;
    }

    QueryRunner qr;
    if (!query.GetQueryText().empty()) {
        qr.AddStrategy(new TextQueryStrategy(query));
    }
    if (!query.GetTypeChoise().empty()) {
        qr.AddStrategy(new TypeQueryStrategy(query));
    }

    for (auto& sensor : sensors) {
        qr.Run(sensor.second);
    }
    return qr.GetResults();
}

AbstractSensor* SensorManager::GetSensor(unsigned int id) const {
    std::map<unsigned int, AbstractSensor*>::const_iterator it = sensors.find(id);
    if (it == sensors.end()) {
        throw std::out_of_range("Trying to read an undefined id.");
    }
    return it->second;
}

const std::vector<AbstractSensor*> SensorManager::GetAll() const {
    std::vector<AbstractSensor*> items;
    for (
        std::map<unsigned int, AbstractSensor*>::const_iterator it = sensors.begin();
        it != sensors.end();
        it++) {
        items.push_back(it->second);
    }
    return items;
}

void SensorManager::Clear() {
    for (auto& sensor : sensors) {
        delete sensor.second;
    }
    sensors.clear();
}

void SensorManager::Inizialize(std::vector<AbstractSensor*>& newSensors) {
    Clear();
    unsigned int maxId = 0;
    for (AbstractSensor* sensor : newSensors) {
        if (maxId < sensor->GetSensorId()) {
            maxId = sensor->GetSensorId();
        }
        AddSensor(sensor);
    }
    AbstractSensor::products = maxId + 1;
}
