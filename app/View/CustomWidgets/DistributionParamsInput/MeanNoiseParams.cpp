#include "MeanNoiseParams.h"

#include <QHBoxLayout>

MeanNoiseParams::MeanNoiseParams(QWidget* parent) : AbstractParamsInput(parent) {
    QHBoxLayout* labelLay = new QHBoxLayout();

    QLabel* maxLabel = new QLabel("Mean");
    QLabel* minLabel = new QLabel("Noise");
    maxLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    minLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    labelLay->addWidget(maxLabel);
    labelLay->addWidget(minLabel);

    QHBoxLayout* paramsLay = new QHBoxLayout();

    mean = new QSpinBox();
    noise = new QSpinBox();

    params[Param::Mean] = mean->value();
    params[Param::Noise] = noise->value();

    paramsLay->addWidget(mean);
    paramsLay->addWidget(noise);

    layout->addLayout(labelLay);
    layout->addLayout(paramsLay);

    connect(mean, QOverload<int>::of(&QSpinBox::valueChanged), this, [&](int value) -> void {
        params[Param::Mean] = value;
    });
    connect(noise, QOverload<int>::of(&QSpinBox::valueChanged), this, [&](int value) -> void {
        params[Param::Noise] = value;
    });
}

void MeanNoiseParams::ClearInput() {
    mean->setValue(0);
    noise->setValue(0);
}
