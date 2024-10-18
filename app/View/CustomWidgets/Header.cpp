#include "Header.h"

#include <QLabel>
#include <QVBoxLayout>

Header::Header(const QString& description, QWidget* parent) : QWidget(parent) {
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QVBoxLayout* labelLayout = new QVBoxLayout(this);
    labelLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    labelLayout->setSpacing(0);

    greatingsLabel = new QLabel();
    greatingsLabel->setObjectName("header-greatings");

    QLabel* descriptionLabel = new QLabel("  " + description);
    descriptionLabel->setObjectName("header-phrase");

    labelLayout->addWidget(greatingsLabel, 1);
    labelLayout->addWidget(descriptionLabel);
}

void Header::UpdateUser(const QString& user) {
    QString greatingsText = "Hello, <b>" + user + "!</b>";
    greatingsLabel->setText(greatingsText);
}
