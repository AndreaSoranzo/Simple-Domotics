#ifndef IDistribution_H
#define IDistribution_H

#include <random>
#include <string>
#include <vector>

#include "../VisitorTypes/IDistributionTypeVisitorConst.h"
#include "../VisitorTypes/IDistributionTypeVisitor.h"

class AbstractDistribution {
   private:
    unsigned int amount;
    const std::string type;

   protected:
    std::mt19937 generator;
    std::random_device rng;

   public:
    AbstractDistribution(unsigned int amount, const std::string& type);
    const std::string& ToString() const;
    unsigned int GetAmount() const;

    virtual std::vector<double> generate() = 0;

    virtual void accept(IDistributionTypeVisitor& visitor) = 0;
    virtual void accept(IDistributionTypeVisitorConst& visitor) = 0;
    virtual ~AbstractDistribution() = default;
};

#endif  // !IDistribution_H