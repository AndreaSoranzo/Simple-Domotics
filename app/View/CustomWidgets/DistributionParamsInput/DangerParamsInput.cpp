#include "DangerParamsInput.h"

DangerParamsInput::DangerParamsInput(QWidget* parent) : AbstractParamsInput(parent) {
    QLabel* dangerLabel = new QLabel("Danger");
    dangerLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    danger = new QSpinBox();
    params[Param::Danger] = danger->value();

    layout->addWidget(dangerLabel);
    layout->addWidget(danger);

    connect(danger, QOverload<int>::of(&QSpinBox::valueChanged), this, [&](int value) -> void {
        params[Param::Danger] = value;
    });
}

void DangerParamsInput::ClearInput() {
    danger->setValue(0);
}
