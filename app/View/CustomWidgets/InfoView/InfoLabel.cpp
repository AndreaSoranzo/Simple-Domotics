#include "InfoLabel.h"

QLabel* CreateInfoLabel(const QString& text, const QString& qss) {
    QLabel* label = new QLabel(text);
    label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label->setAlignment(Qt::AlignCenter);
    label->setObjectName(qss);
    return label;
}