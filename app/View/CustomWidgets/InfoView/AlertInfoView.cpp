#include "AlertInfoView.h"

#include <QGridLayout>

#include "InfoLabel.h"

AlertInfoView::AlertInfoView(int danger, QWidget* parent) : AbstractInfoView(parent) {
    QGridLayout* sensorValuesLay = new QGridLayout(this);
    sensorValuesLay->setVerticalSpacing(50);
    sensorValuesLay->setHorizontalSpacing(60);

    QLabel* dangerLabel = CreateInfoLabel("Danger\n" + QString::number(danger), "card-list-name");
    lastTriggerLabel = CreateInfoLabel("Last Trigger\nUndef.", "card-list-name");

    sensorValuesLay->addWidget(dangerLabel, 0, 0);
    sensorValuesLay->addWidget(lastTriggerLabel, 1, 0);
}

void AlertInfoView::UpdateLastTrigger(const QString& time) {
    lastTriggerLabel->setText("Last Trigger\n" + time);
}
