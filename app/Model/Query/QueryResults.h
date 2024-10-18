#ifndef QueryResults_H
#define QueryResults_H

#include <vector>

#include "SensorScoreDecorator.h"

class QueryResults {
   private:
    std::vector<SensorScoreDecorator> results;

   public:
    QueryResults();
    void AddResult(const AbstractSensor* sensor, unsigned int score);
    const std::vector<unsigned int> ToSensorId() const;
    void Sort();
};

#endif  // !QueryResults_H