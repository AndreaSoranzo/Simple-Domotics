#include "EditPanel.h"

#include <QPushButton>

EditPanel::EditPanel(QWidget* parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    okBtn = new QPushButton("Ok");
    okBtn->setObjectName("okBtn");
    okBtn->setFixedSize(100, 40);
    okBtn->setFocusPolicy(Qt::NoFocus);

    layout->addWidget(okBtn, 0, Qt::AlignRight);
    connect(okBtn, &QPushButton::pressed, this, &EditPanel::OnApply);
}

SimpleEditor* EditPanel::GetCurrentEditor() const {
    return currentEditor;
}

void EditPanel::SetEditor(SimpleEditor* newEditor) {
    if (layout->itemAt(0)->widget() && dynamic_cast<SimpleEditor*>(layout->itemAt(0)->widget())) {
        QLayoutItem* item = layout->takeAt(0);
        item->widget()->setParent(nullptr);
        delete item->widget();
        delete item;
    }
    layout->insertWidget(0, newEditor);
}
