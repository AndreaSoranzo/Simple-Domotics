#include "../../../Utils/TypeHelper.h"
#include "UniformDistribution.h"

UniformDistribution::UniformDistribution(unsigned int amount, unsigned int min, unsigned int max) : AbstractDistribution(amount, TypeHelper::ToDistributionName(DistributionType::Uniform)) {
    if (min > max) {
        // swapping using XOR algorithm
        min = max ^ min;
        max = min ^ max;
        min = max ^ min;
    }
    this->min = min;
    this->max = max;
    distribution = std::uniform_real_distribution<double>(min, max);
}

std::vector<double> UniformDistribution::generate() {
    std::vector<double> data;
    generator.seed(rng());
    for (unsigned int i = 0; i < GetAmount(); i++) {
        data.push_back(distribution(generator));
    }

    return data;
}

unsigned int UniformDistribution::GetMax() const {
    return max;
}
unsigned int UniformDistribution::GetMin() const {
    return min;
}

void UniformDistribution::accept(IDistributionTypeVisitor &visitor) {
    visitor.visit(*this);
}

void UniformDistribution::accept(IDistributionTypeVisitorConst &visitor) {
    visitor.visit(*this);
}
