#include "TemperatureEditor.h"

TemperatureEditor::TemperatureEditor(const QString& name, const QString& brand, const QString& moreInfo, int batteries, QWidget* parent) : SimpleEditor(name, brand, moreInfo, parent) {
    batteriesInput = new QSpinBox();
    batteriesInput->setValue(batteries);

    connect(batteriesInput, &QSpinBox::textChanged, this, [&]() -> void { isChanged = true; });
    AddFormRow("Batteries:", batteriesInput);
}

unsigned int TemperatureEditor::GetBatteries() const {
    return batteriesInput->value();
}
