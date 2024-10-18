#include "AbstractDistribution.h"

AbstractDistribution::AbstractDistribution(unsigned int amount, const std::string& type) : amount(amount), type(type) {
    // std::random_device rng;
    generator.seed(rng());
}

const std::string& AbstractDistribution::ToString() const {
    return type;
}

unsigned int AbstractDistribution::GetAmount() const {
    return amount;
}
