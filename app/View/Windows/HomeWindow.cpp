#include "HomeWindow.h"

#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>

#include "../CustomWidgets/UserSettingDialog.h"
#include "../Utils/WelcomeStatus.h"

void HomeWindow::UpdateScreen(const QString& user) {
    QString greatingsText = "Hello, <b>" + user + "!</b>";
    greatingsLabel->setText(greatingsText);
}

HomeWindow::HomeWindow(QWidget* parent) : AbstractWindow(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QWidget* mainContainter = new QWidget();
    QHBoxLayout* contentLayout = new QHBoxLayout(mainContainter);
    contentLayout->setSpacing(100);

    // Creatin label
    QVBoxLayout* labelLayout = new QVBoxLayout();
    labelLayout->setSpacing(0);

    greatingsLabel = new QLabel();
    greatingsLabel->setWordWrap(true);
    greatingsLabel->setObjectName("greatings");

    QLabel* statusLabel = new QLabel(WelcomeStatus::GetStatus());
    statusLabel->setObjectName("phrase");

    labelLayout->addWidget(greatingsLabel, 1);
    labelLayout->addWidget(statusLabel);

    // creating user and info button
    QWidget* infoContainer = new QWidget();
    infoContainer->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    QHBoxLayout* optionSubLayout = new QHBoxLayout(infoContainer);
    optionSubLayout->setContentsMargins(0, 0, 0, 0);

    QLabel* profileIcon = new QLabel();
    profileIcon->setPixmap(QPixmap(":assets/images/user.png").scaled(110, 110, Qt::KeepAspectRatio));
    profileIcon->setFixedSize(110, 110);
    profileIcon->setObjectName("profile");
    QPushButton* settingsBtn = new QPushButton();
    settingsBtn->setIcon(QIcon(QPixmap(":assets/icons/settings.svg")));
    settingsBtn->setFixedSize(40, 40);
    settingsBtn->setFocusPolicy(Qt::NoFocus);
    settingsBtn->setObjectName("settings");

    optionSubLayout->addWidget(profileIcon, 0, Qt::AlignCenter);
    optionSubLayout->addWidget(settingsBtn, 0, Qt::AlignBottom);

    contentLayout->addLayout(labelLayout);
    contentLayout->addWidget(infoContainer);

    // creating footer label
    QLabel* description = new QLabel("App made by Andrea Soranzo");
    description->setObjectName("thin");
    description->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    mainLayout->addWidget(mainContainter, 3, Qt::AlignCenter);
    mainLayout->addWidget(description, 0);

    connect(settingsBtn, &QPushButton::clicked, this, &HomeWindow::OnOpenUserSettings);
}

void HomeWindow::Notify(const std::string& name, const std::string&, int) {
    UpdateScreen(QString::fromStdString(name));
}

void HomeWindow::RevertToDefaultState() {
    // do nothing
}