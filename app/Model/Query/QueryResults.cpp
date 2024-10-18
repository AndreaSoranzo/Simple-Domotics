#include "QueryResults.h"

#include <algorithm>

QueryResults::QueryResults() {
}

void QueryResults::AddResult(const AbstractSensor* sensor, unsigned int score) {
    results.push_back(SensorScoreDecorator(sensor, score));
}

const std::vector<unsigned int> QueryResults::ToSensorId() const {
    std::vector<unsigned int> originalSensors;
    for (SensorScoreDecorator decorator : results) {
        originalSensors.push_back(decorator.GetSensor()->GetSensorId());
    }
    return originalSensors;
}

void QueryResults::Sort() {
    std::sort(results.begin(), results.end());
}
