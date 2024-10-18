#include "MinMaxParams.h"

#include <QHBoxLayout>

MinMaxParams::MinMaxParams(QWidget* parent) : AbstractParamsInput(parent) {
    QHBoxLayout* labelLay = new QHBoxLayout();

    QLabel* maxLabel = new QLabel("Max");
    QLabel* minLabel = new QLabel("Min");
    maxLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    minLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    labelLay->addWidget(maxLabel);
    labelLay->addWidget(minLabel);

    QHBoxLayout* paramsLay = new QHBoxLayout();

    max = new QSpinBox();
    min = new QSpinBox();

    params[Param::Max] = max->value();
    params[Param::Min] = min->value();

    paramsLay->addWidget(max);
    paramsLay->addWidget(min);

    layout->addLayout(labelLay);
    layout->addLayout(paramsLay);

    connect(max, QOverload<int>::of(&QSpinBox::valueChanged), this, [&](int value) -> void {
        params[Param::Max] = value;
    });
    connect(min, QOverload<int>::of(&QSpinBox::valueChanged), this, [&](int value) -> void {
        params[Param::Min] = value;
    });
}

void MinMaxParams::ClearInput() {
    max->setValue(0);
    min->setValue(0);
}
