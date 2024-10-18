#ifndef IDistributionTypeVisitor_H
#define IDistributionTypeVisitor_H

class ExponentialDistribution;
class NormalDistribuition;
class RandomDistribution;
class UniformDistribution;

class IDistributionTypeVisitor {
   public:
    virtual ~IDistributionTypeVisitor() = default;

    virtual void visit(UniformDistribution& dist) = 0;
    virtual void visit(NormalDistribuition& dist) = 0;
    virtual void visit(ExponentialDistribution& dist) = 0;
    virtual void visit(RandomDistribution& dist) = 0;
};

#endif  // !IDistributionTypeVisitor_H