#include "AbstractParamsInput.h"

AbstractParamsInput::AbstractParamsInput(QWidget* parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
}

unsigned int AbstractParamsInput::GetParam(const Param& param) const {
    return params.at(param);
}