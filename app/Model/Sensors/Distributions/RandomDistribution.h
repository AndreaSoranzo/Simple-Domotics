#ifndef RandomDistribution_H
#define RandomDistribution_H

#include "AbstractDistribution.h"

class RandomDistribution : public AbstractDistribution {
   private:
    unsigned int min;
    unsigned int max;

   public:
    RandomDistribution(unsigned int amount, unsigned int min, unsigned int max);

    unsigned int GetMax() const;
    unsigned int GetMin() const;

    std::vector<double> generate() override;

    void accept(IDistributionTypeVisitor& visitor) override;
    void accept(IDistributionTypeVisitorConst& visitor) override;
};

#endif  // !RandomDistribution_H