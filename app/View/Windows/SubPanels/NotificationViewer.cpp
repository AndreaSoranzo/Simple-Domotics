#include "NotificationViewer.h"

#include <QPushButton>
#include <QVBoxLayout>

NotificationViewer::NotificationViewer(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(60);

    titleLabel = new QLabel();
    titleLabel->setObjectName("title");

    textLabel = new QLabel();
    textLabel->setContentsMargins(50, 0, 50, 0);
    textLabel->setObjectName("notificaion-content");
    textLabel->setWordWrap(true);

    QPushButton* okBtn = new QPushButton("Ok");
    okBtn->setObjectName("okBtn");
    okBtn->setFixedSize(100, 40);
    okBtn->setFocusPolicy(Qt::NoFocus);

    mainLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
    mainLayout->addWidget(textLabel, 2, Qt::AlignTop);
    mainLayout->addWidget(okBtn, 0, Qt::AlignRight | Qt::AlignBottom);

    connect(okBtn, &QPushButton::pressed, this, &NotificationViewer::ReturnToList);
}

void NotificationViewer::SetTitle(const QString& title) {
    titleLabel->setText(title);
}

void NotificationViewer::SetText(const QString& text) {
    this->textLabel->setText(text);
}
