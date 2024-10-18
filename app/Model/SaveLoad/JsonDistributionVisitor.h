#ifndef JsonDistributionVisitor_H
#define JsonDistributionVisitor_H

#include <QJsonObject>

#include "../Sensors/Distributions/ExponentialDistribution.h"
#include "../Sensors/Distributions/NormalDistribuition.h"
#include "../Sensors/Distributions/RandomDistribution.h"
#include "../Sensors/Distributions/UniformDistribution.h"
#include "../Sensors/VisitorTypes/IDistributionTypeVisitorConst.h"

class JsonDistributionVisitor : public IDistributionTypeVisitorConst {
   private:
    QJsonObject json;

   public:
    void visit(const UniformDistribution& dist) override;
    void visit(const NormalDistribuition& dist) override;
    void visit(const ExponentialDistribution& dist) override;
    void visit(const RandomDistribution& dist) override;
    QJsonObject GetJsonObject() const;
};

#endif  // !JsonDistributionVisitor_H