#include "SimpleInfoView.h"

#include "InfoLabel.h"

SimpleInfoView::SimpleInfoView(QWidget* parent) : AbstractInfoView(parent) {
    sensorValuesLay = new QGridLayout(this);
    sensorValuesLay->setVerticalSpacing(50);
    sensorValuesLay->setHorizontalSpacing(60);

    minLabel = CreateInfoLabel("Min\nUndef.", "card-list-name");
    maxLabel = CreateInfoLabel("Max\nUndef.", "card-list-name");
    avgLabel = CreateInfoLabel("Total Avg\nUndef.", "card-list-name");

    sensorValuesLay->addWidget(minLabel, 0, 0);
    sensorValuesLay->addWidget(maxLabel, 0, 1);
    sensorValuesLay->addWidget(avgLabel, 1, 0, 1, 2);
}

void SimpleInfoView::UpdateMin(const QString& value) {
    minLabel->setText("Min\n" + value);
}

void SimpleInfoView::UpdateMax(const QString& value) {
    maxLabel->setText("Max\n" + value);
}

void SimpleInfoView::UpdateAvg(const QString& value) {
    avgLabel->setText("Total Avg\n" + value);
}

void SimpleInfoView::AddInfo(QLabel* info, int row, int column, int rowStretch, int columnStretch) {
    sensorValuesLay->addWidget(info, row, column, rowStretch, columnStretch);
}