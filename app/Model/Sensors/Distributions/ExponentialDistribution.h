#ifndef ExponentialDistribuition_H
#define ExponentialDistribuition_H

#include "AbstractDistribution.h"

class ExponentialDistribution : public AbstractDistribution {
   private:
    double lamda;
    std::exponential_distribution<double> distribution;

   public:
    ExponentialDistribution(unsigned int amount, double lamda);
    std::vector<double> generate() override;

    void SetDanger(double danger);
    void accept(IDistributionTypeVisitor& visitor) override;
    void accept(IDistributionTypeVisitorConst& visitor) override;
};

#endif  // !ExponentialDistribuition_H