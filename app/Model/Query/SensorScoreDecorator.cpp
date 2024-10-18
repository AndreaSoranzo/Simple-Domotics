#include "SensorScoreDecorator.h"

SensorScoreDecorator::SensorScoreDecorator(const AbstractSensor* sensor, unsigned int score) : sensor(sensor), score(score) {
}

const AbstractSensor* SensorScoreDecorator::GetSensor() const {
    return sensor;
}

unsigned int SensorScoreDecorator::GetScore() const {
    return score;
}

bool SensorScoreDecorator::operator<(const SensorScoreDecorator& sensor) const {
    return score > sensor.score;
}
