#ifndef InfoViewDistributionVisitor_H
#define InfoViewDistributionVisitor_H

#include "../Model/Sensors/VisitorTypes/IDistributionTypeVisitorConst.h"
#include "../View/CustomWidgets/InfoView/SimpleInfoView.h"

class InfoViewDistributionVisitor : public IDistributionTypeVisitorConst {
   private:
    SimpleInfoView* infoView;

   public:
    explicit InfoViewDistributionVisitor(SimpleInfoView* infoView);
    void visit(const UniformDistribution& dist) override;
    void visit(const NormalDistribuition& dist) override;
    void visit(const ExponentialDistribution& dist) override;
    void visit(const RandomDistribution& dist) override;
};
#endif  // !InfoViewDistributionVisitor