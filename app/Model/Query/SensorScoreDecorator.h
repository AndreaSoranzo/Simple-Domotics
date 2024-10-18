#ifndef SensorScoreDecorator_H
#define SensorScoreDecorator_H

#include "../Sensors/Core/AbstractSensor.h"

class SensorScoreDecorator {
   private:
    const AbstractSensor* sensor;
    unsigned int score;

   public:
    SensorScoreDecorator(const AbstractSensor* sensor, unsigned int score);

    const AbstractSensor* GetSensor() const;
    unsigned int GetScore() const;
    bool operator<(const SensorScoreDecorator& sensor) const;
};

#endif  // !SensorScoreDecorator_H