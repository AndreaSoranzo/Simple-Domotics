#include "AbstractSensorBox.h"

#include "../../Utils/WidgetsEffects.h"

AbstractSensorBox::AbstractSensorBox(unsigned int id, QWidget* parent) : QWidgetFix(parent), id(id) {
    WidgetsEffects::ApplyShadow(this, 10, 1, 1);

    editBtn = new QPushButton();
    editBtn->setFocusPolicy(Qt::NoFocus);
    editBtn->setIcon(QIcon(":assets/icons/edit.svg"));
    editBtn->setIconSize(QSize(30, 30));

    deleteBtn = new QPushButton();
    deleteBtn->setFocusPolicy(Qt::NoFocus);
    deleteBtn->setIcon(QIcon(":assets/icons/delete.svg"));
    deleteBtn->setIconSize(QSize(30, 30));

    deleteBtn->hide();
    editBtn->hide();

    connect(deleteBtn, &QPushButton::pressed, this, &QWidget::deleteLater);  // delete later will delete this widget when the control passes to the appLoop and deletes all his children
}

void AbstractSensorBox::mousePressEvent(QMouseEvent* event) {
    QWidget::mousePressEvent(event);
    if (event->button() == Qt::LeftButton) {
        emit pressed();
    }
}
void AbstractSensorBox::enterEvent(QEnterEvent* event) {
    QWidget::enterEvent(event);
    deleteBtn->show();
    editBtn->show();
}
void AbstractSensorBox::leaveEvent(QEvent* event) {
    QWidget::leaveEvent(event);
    deleteBtn->hide();
    editBtn->hide();
}
const QPushButton* AbstractSensorBox::GetEditButton() const {
    return editBtn;
}

const QPushButton* AbstractSensorBox::GetDeleteButton() const {
    return deleteBtn;
}
