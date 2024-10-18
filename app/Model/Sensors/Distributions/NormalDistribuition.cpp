#include "NormalDistribuition.h"

#include "../../../Utils/TypeHelper.h"

NormalDistribuition::NormalDistribuition(unsigned int amount, unsigned int mean, unsigned int noise) : AbstractDistribution(amount, TypeHelper::ToDistributionName(DistributionType::Normal)), mean(mean), noise(noise), distribution(mean, noise) {
}

std::vector<double> NormalDistribuition::generate() {
    std::vector<double> data;
    generator.seed(rng());
    for (unsigned int i = 0; i < GetAmount(); i++) {
        data.push_back(distribution(generator));
    }

    return data;
}

unsigned int NormalDistribuition::GetMean() const {
    return mean;
}

unsigned int NormalDistribuition::GetNoise() const {
    return noise;
}

void NormalDistribuition::accept(IDistributionTypeVisitor &visitor) {
    visitor.visit(*this);
}

void NormalDistribuition::accept(IDistributionTypeVisitorConst &visitor) {
    visitor.visit(*this);
}
