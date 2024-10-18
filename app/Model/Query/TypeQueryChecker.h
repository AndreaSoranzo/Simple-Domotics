#ifndef TypeQueryVisitor_H
#define TypeQueryVisitor_H

#include <map>
#include <string>
#include <vector>

#include "../Sensors/Core/AbstractSensor.h"

class TypeQueryChecker {
   private:
    std::map<std::string, bool> allowed;

   public:
    TypeQueryChecker(const std::string& choises);
    bool IsMatch(AbstractSensor* sens);
};

#endif  // !SensorTypeFilterVisitor