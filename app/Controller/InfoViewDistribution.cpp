#include "InfoViewDistribution.h"

#include "../Model/Sensors/Distributions/ExponentialDistribution.h"
#include "../Model/Sensors/Distributions/NormalDistribuition.h"
#include "../Model/Sensors/Distributions/RandomDistribution.h"
#include "../Model/Sensors/Distributions/UniformDistribution.h"
#include "../View/CustomWidgets/InfoView/InfoLabel.h"

InfoViewDistributionVisitor::InfoViewDistributionVisitor(SimpleInfoView* infoView) : infoView(infoView) {
}

void InfoViewDistributionVisitor::visit(const UniformDistribution& dist) {
    QLabel* maxLabel = CreateInfoLabel("Uniform Min\n" + QString::number(dist.GetMin()), "card-list-name");
    QLabel* minLabel = CreateInfoLabel("Uniform Max\n" + QString::number(dist.GetMax()), "card-list-name");

    infoView->AddInfo(maxLabel, 4, 0);
    infoView->AddInfo(minLabel, 4, 1);
}

void InfoViewDistributionVisitor::visit(const NormalDistribuition& dist) {
    QLabel* meanLabel = CreateInfoLabel("Normal Mean\n" + QString::number(dist.GetMean()), "card-list-name");
    QLabel* noiseLabel = CreateInfoLabel("Normal Noise\n" + QString::number(dist.GetNoise()), "card-list-name");
    infoView->AddInfo(meanLabel, 3, 0);
    infoView->AddInfo(noiseLabel, 3, 1);
}

void InfoViewDistributionVisitor::visit(const ExponentialDistribution&) {
}

void InfoViewDistributionVisitor::visit(const RandomDistribution& dist) {
    QLabel* maxLabel = CreateInfoLabel("Random Min\n" + QString::number(dist.GetMin()), "card-list-name");
    QLabel* minLabel = CreateInfoLabel("Random Max\n" + QString::number(dist.GetMax()), "card-list-name");
    infoView->AddInfo(maxLabel, 3, 0);
    infoView->AddInfo(minLabel, 3, 1);
}
