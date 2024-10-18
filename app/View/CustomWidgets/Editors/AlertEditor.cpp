#include "AlertEditor.h"

AlertEditor::AlertEditor(const QString& name, const QString& brand, const QString& moreInfo, int danger, QWidget* parent) : SimpleEditor(name, brand, moreInfo, parent) {
    dangerInput = new QSpinBox();
    dangerInput->setValue(danger);
    connect(dangerInput, &QSpinBox::textChanged, this, [&]() -> void { isChanged = true; });

    AddFormRow("Danger Lv.", dangerInput);
}

int AlertEditor::GetDanger() const {
    return dangerInput->value();
}
