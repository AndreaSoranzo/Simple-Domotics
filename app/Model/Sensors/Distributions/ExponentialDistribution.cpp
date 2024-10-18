#include "ExponentialDistribution.h"

#include "../../../Utils/TypeHelper.h"

ExponentialDistribution::ExponentialDistribution(unsigned int amount, double lamda) : AbstractDistribution(amount, TypeHelper::ToDistributionName(DistributionType::Exponential)) {
    SetDanger(lamda);
}

std::vector<double> ExponentialDistribution::generate() {
    std::vector<double> data;
    generator.seed(rng());
    for (unsigned int i = 0; i < GetAmount(); i++) {
        data.push_back((int)distribution(generator) >= 10);
    }
    return data;
}

void ExponentialDistribution::SetDanger(double danger) {
    double lv = 1 - (danger * 1.50);
    if (lv < 0) {
        lamda = 0.01;
    } else {
        lamda = lv;
    }

    distribution.param(std::exponential_distribution<double>::param_type(lamda));
}

void ExponentialDistribution::accept(IDistributionTypeVisitor &visitor) {
    visitor.visit(*this);
}

void ExponentialDistribution::accept(IDistributionTypeVisitorConst &visitor) {
    visitor.visit(*this);
}
