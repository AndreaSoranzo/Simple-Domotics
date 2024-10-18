#include "RandomDistribution.h"

#include "../../../Utils/TypeHelper.h"

RandomDistribution::RandomDistribution(unsigned int amount, unsigned int min, unsigned int max) : AbstractDistribution(amount, TypeHelper::ToDistributionName(DistributionType::Random)) {
    if (min > max) {
        // swapping using XOR algorithm
        min = max ^ min;
        max = min ^ max;
        min = max ^ min;
    }
    this->min = min;
    this->max = max;
}

std::vector<double> RandomDistribution::generate() {
    std::vector<double> data;
    generator.seed(rng());
    for (unsigned int i = 0; i < GetAmount(); i++) {
        data.push_back(generator() % (max - min + 1) + min);
    }
    return data;
}

unsigned int RandomDistribution::GetMax() const {
    return max;
}

unsigned int RandomDistribution::GetMin() const {
    return min;
}

void RandomDistribution::accept(IDistributionTypeVisitor &visitor) {
    visitor.visit(*this);
}

void RandomDistribution::accept(IDistributionTypeVisitorConst &visitor) {
    visitor.visit(*this);
}
