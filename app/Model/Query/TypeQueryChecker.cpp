#include "TypeQueryChecker.h"

TypeQueryChecker::TypeQueryChecker(const std::string& choises) {
    allowed[choises] = true;
}

bool TypeQueryChecker::IsMatch(AbstractSensor* sens) {
    return allowed[sens->ToString()];
}
