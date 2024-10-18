#ifndef UniformDistribution_H
#define UniformDistribution_H

#include "AbstractDistribution.h"

class UniformDistribution : public AbstractDistribution {
   private:
    unsigned int min;
    unsigned int max;
    std::uniform_real_distribution<double> distribution;

   public:
    UniformDistribution(unsigned int amount, unsigned int min, unsigned int max);

    unsigned int GetMax() const;
    unsigned int GetMin() const;

    std::vector<double> generate() override;

    void accept(IDistributionTypeVisitor& visitor) override;
    void accept(IDistributionTypeVisitorConst& visitor) override;
};

#endif  // !UniformDistribution_H