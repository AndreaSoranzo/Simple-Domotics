#ifndef NormalDistribuition_H
#define NormalDistribuition_H

#include "AbstractDistribution.h"

class NormalDistribuition : public AbstractDistribution {
   private:
    unsigned int mean;
    unsigned int noise;
    std::normal_distribution<double> distribution;

   public:
    NormalDistribuition(unsigned int amount, unsigned int mean, unsigned int noise);

    unsigned int GetMean() const;
    unsigned int GetNoise() const;

    std::vector<double> generate() override;

    void accept(IDistributionTypeVisitor& visitor) override;
    void accept(IDistributionTypeVisitorConst& visitor) override;
};

#endif  // !NormalDistribuition_H