#ifndef IQueryStrategy_H
#define IQueryStrategy_H

#include "../../Sensors/Core/AbstractSensor.h"

class IQueryStrategy {
   public:
    virtual bool IsMatch(AbstractSensor* sensor) = 0;
    virtual unsigned int GetScore() const = 0;
    virtual ~IQueryStrategy() = default;
};

#endif  // !IQueryStrategy_H