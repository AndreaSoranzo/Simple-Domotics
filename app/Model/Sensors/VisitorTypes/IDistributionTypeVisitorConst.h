#ifndef IDistributionTypeVisitorConst_H
#define IDistributionTypeVisitorConst_H

class ExponentialDistribution;
class NormalDistribuition;
class RandomDistribution;
class UniformDistribution;

class IDistributionTypeVisitorConst {
   public:
    virtual ~IDistributionTypeVisitorConst() = default;

    virtual void visit(const UniformDistribution& dist) = 0;
    virtual void visit(const NormalDistribuition& dist) = 0;
    virtual void visit(const ExponentialDistribution& dist) = 0;
    virtual void visit(const RandomDistribution& dist) = 0;
};

#endif  // !IDistributionTypeVisitorConst_H