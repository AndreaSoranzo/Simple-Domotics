#include "TypeQueryStrategy.h"

TypeQueryStrategy::TypeQueryStrategy(const Query& query) : checker(query.GetTypeChoise()) {
}

bool TypeQueryStrategy::IsMatch(AbstractSensor* sensor) {
    return checker.IsMatch(sensor);
}

unsigned int TypeQueryStrategy::GetScore() const {
    return 0;  // place holder
}
