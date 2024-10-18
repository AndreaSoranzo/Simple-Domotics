#include "SimpleEditor.h"

#include <QPushButton>
#include <QVBoxLayout>

SimpleEditor::SimpleEditor(const QString& name, const QString& brand, const QString& moreInfo, QWidget* parent) : QWidget(parent) {
    nameInput = new QLineEdit(name);
    brandInput = new QLineEdit(brand);
    infoInput = new QTextEdit(moreInfo);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);

    formLayout = new QFormLayout();
    formLayout->setSpacing(30);

    formLayout->addRow("Sensor name:", nameInput);
    formLayout->addRow("Sensor brand:", brandInput);
    formLayout->addRow("More info:", infoInput);

    connect(nameInput, &QLineEdit::textChanged, this, [&]() -> void { isChanged = true; });
    connect(brandInput, &QLineEdit::textChanged, this, [&]() -> void { isChanged = true; });
    connect(infoInput, &QTextEdit::textChanged, this, [&]() -> void { isChanged = true; });

    mainLayout->addLayout(formLayout, 1);
}

void SimpleEditor::AddFormRow(const QString& name, QWidget* widget) {
    while (QLayoutItem* item = formLayout->takeAt(0)) {
        if (item->widget()) {
            formLayout->removeWidget(item->widget());
            item->widget()->setParent(nullptr);  // detach widget form layout
        }
        // delete the LayoutItem but not the widget, widgets are not children of the layout but of the parent of the layout (QLayout class CANNOT have children)
        delete item;
    }

    formLayout->addRow("Sensor name:", nameInput);
    formLayout->addRow("Sensor brand:", brandInput);
    formLayout->addRow(name, widget);
    formLayout->addRow("More info:", infoInput);
}

const QString SimpleEditor::GetName() const {
    return nameInput->text();
}

const QString SimpleEditor::GetBrand() const {
    return brandInput->text();
}

const QString SimpleEditor::GetInfo() const {
    return infoInput->toPlainText();
}

bool SimpleEditor::IsChanged() const {
    return isChanged;
}
