#ifndef SensorCreator_H
#define SensorCreator_H

#include "../Model/Sensors/Core/AbstractSensor.h"

class AddPanel;

class SensorCreator {
   private:
    const AddPanel& addPanel;

   public:
    explicit SensorCreator(const AddPanel& addPanel);
    AbstractSensor* Instantiate() const;
};

#endif  // !SensorCreator_H