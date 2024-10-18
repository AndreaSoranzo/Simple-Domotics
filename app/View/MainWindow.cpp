#include "MainWindow.h"

#include <QFile>
#include <QMessageBox>
#include <QShortcut>
#include <QStatusBar>
#include <QVBoxLayout>

#include "CustomWidgets/UserSettingDialog.h"
#include "Utils/PaletteParser.h"
#include "Utils/WidgetsEffects.h"

void MainWindow::ShowHelpBox() const {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Help");
    QString text =
        "- Ctrl + 1 go to panel 1\n- Ctrl + 2 go to panel 2\n- Ctrl + 3 go to panel 3\n- Ctrl + 4 go to panel 4\n- Ctrl + 0 ???";
    msgBox.setText(text);
    msgBox.exec();
}

void MainWindow::ShowSecret() const {
    QMessageBox msgBox;
    msgBox.setText("This GUI was a pain to make.");
    msgBox.exec();
}

QPushButton* MainWindow::CreatePanelButton(const std::string& toolTip, const std::string& path) const {
    QPushButton* btn = new QPushButton();
    btn->setObjectName("panelBtn");
    btn->setFixedSize(70, 50);
    btn->setIcon(QIcon(path.c_str()));
    btn->setIconSize(QSize(30, 30));
    btn->setToolTip(toolTip.c_str());

    WidgetsEffects::ApplyShadow(btn, 5, 0, 2);
    return btn;
}

MainWindow::MainWindow(QApplication* app, QWidget* parent) : QMainWindow(parent), changeWithoutSave(false), app(*app) {
    QWidget* infoView = new QWidget();
    infoView->setObjectName("infoView");
    WidgetsEffects::ApplyShadow(infoView, 10, 0, 2);

    QVBoxLayout* windowLayout = new QVBoxLayout(infoView);

    stackLayout = new QStackedLayout();
    home = new HomeWindow;
    sensors = new SensorsWindow;
    notifications = new NotificationWindow;
    managment = new ManagmentWindow;

    stackLayout->addWidget(home);
    stackLayout->addWidget(sensors);
    stackLayout->addWidget(notifications);
    stackLayout->addWidget(managment);

    stackLayout->setCurrentIndex(0);

    windowLayout->addLayout(stackLayout);

    QShortcut* help = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_H), this);
    QShortcut* panel1 = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_1), this);
    QShortcut* panel2 = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_2), this);
    QShortcut* panel3 = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_3), this);
    QShortcut* panel4 = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_4), this);
    QShortcut* secret = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_0), this);

    homeBtn = CreatePanelButton("home", ":/assets/icons/home.svg");
    listButton = CreatePanelButton("list panel", ":/assets/icons/list.svg");
    notificationButton = CreatePanelButton("notification panel", ":/assets/icons/notification.svg");
    notificationButton->setText("0");
    addButton = CreatePanelButton("configure panel", ":/assets/icons/add.svg");

    QWidget* btnContainer = new QWidget();
    QHBoxLayout* selectPanelLayout = new QHBoxLayout(btnContainer);
    selectPanelLayout->setSpacing(80);
    selectPanelLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    selectPanelLayout->addWidget(homeBtn);
    selectPanelLayout->addWidget(listButton);
    selectPanelLayout->addWidget(notificationButton);
    selectPanelLayout->addWidget(addButton);

    QWidget* statusContainer = new QWidget();
    QHBoxLayout* statusLayout = new QHBoxLayout(statusContainer);

    statusLabel = new QLabel("Ready.");
    statusLabel->setObjectName("status");
    statusLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    statusLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QLabel* helpLabel = new QLabel("Crtl+H for help");
    helpLabel->setObjectName("status");

    statusLayout->addStretch(1);
    statusLayout->addWidget(statusLabel, 0, Qt::AlignCenter);
    statusLayout->addWidget(helpLabel, 1, Qt::AlignRight);

    statusBar()->addPermanentWidget(statusContainer, 1);

    QWidget* mainView = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(mainView);
    mainLayout->addWidget(infoView, 30);
    mainLayout->addWidget(btnContainer, 1);

    dialog = new UserSettingDialog(this);

    ChangePalette(0);
    setCentralWidget(mainView);

    connect(panel1, &QShortcut::activated, this, [&]() -> void { homeBtn->setFocus(); emit homeBtn->pressed(); });
    connect(panel2, &QShortcut::activated, this, [&]() -> void { listButton->setFocus(); emit listButton->pressed(); });
    connect(panel3, &QShortcut::activated, this, [&]() -> void { notificationButton->setFocus(); emit notificationButton->pressed(); });
    connect(panel4, &QShortcut::activated, this, [&]() -> void { addButton->setFocus(); emit addButton->pressed(); });

    connect(home, &HomeWindow::OnOpenUserSettings, this, &MainWindow::OpenUserSettings);
    connect(notifications, &NotificationWindow::OnAddNotification, this, [&](unsigned int number) -> void { notificationButton->setText(QString::number(number)); });
    connect(help, &QShortcut::activated, this, &MainWindow::ShowHelpBox);
    connect(secret, &QShortcut::activated, this, &MainWindow::ShowSecret);

    connect(sensors->GetListPanel(), &ListPanel::OnDelete, this, [&](unsigned int) -> void { changeWithoutSave = true; });
    connect(sensors->GetEditPanel(), &EditPanel::OnEditComplete, this, [&](unsigned int) -> void { changeWithoutSave = true; });
    connect(managment->GetAddPanel(), &AddPanel::OnCreateSensor, this, [&]() -> void { changeWithoutSave = true; });
    connect(managment->GetManagmentPanel(), &ManagmentPanel::OnSave, this, [&]() -> void { changeWithoutSave = false; });

    connect(homeBtn, &QPushButton::pressed, this, [&]() -> void { statusLabel->setText("Home sweet home."); ChangePanel(0); });
    connect(listButton, &QPushButton::pressed, this, [&]() -> void { statusLabel->setText("Browsing sensors."); ChangePanel(1); });
    connect(notificationButton, &QPushButton::pressed, this, [&]() -> void { statusLabel->setText("Browsing notifications."); ChangePanel(2); });
    connect(addButton, &QPushButton::pressed, this, [&]() -> void { statusLabel->setText("Add/Save or load your sensors."); ChangePanel(3); });
}

void MainWindow::Notify(const std::string& name, const std::string& email, int palette) {
    dialog->SetNameInputText(QString::fromStdString(name));
    dialog->SetMailInputText(QString::fromStdString(email));
    dialog->SetPaletteInput(palette);
    ChangePalette(palette);
}

void MainWindow::LoadMsg(bool ok) const {
    if (ok) {
        QMessageBox msgBox;
        msgBox.setText("Sensors loaded correctly");
        msgBox.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setText("Cannot load sensors");
        msgBox.exec();
    }
}

void MainWindow::SaveMsg(bool ok) const {
    if (ok) {
        QMessageBox msgBox;
        msgBox.setText("sensor saved correctly");
        msgBox.exec();
        /* code */
    } else {
        QMessageBox msgBox;
        msgBox.setText("Cannot save sensors");
        msgBox.exec();
    }
}

void MainWindow::OpenUserSettings(bool isAtStart) {
    bool ok = false;
    UserSettingDialog::NewValues values = dialog->GetValues(ok);

    if (ok) {
        emit OnUpdateSettings(values.name, values.mail, values.palette);
    } else if (isAtStart) {
        emit OnUpdateSettings("User", "example@example.com", 0);
    }
}

void MainWindow::ChangePanel(int idx) {
    AbstractWindow* current = dynamic_cast<AbstractWindow*>(stackLayout->currentWidget());
    if (current) {
        current->RevertToDefaultState();
    }
    stackLayout->setCurrentIndex(idx);
}

void MainWindow::closeEvent(QCloseEvent* event) {
    if (changeWithoutSave) {
        QMessageBox msgBox;
        msgBox.setText("You have unsaved changes, are you sure tou want to exit?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int choise = msgBox.exec();
        if (choise == QMessageBox::Ok) {
            event->accept();
        } else {
            event->ignore();
        }
    } else {
        event->accept();
    }
}

void MainWindow::ChangePalette(int idx) {
    QFile stylesheet(":/assets/qss/default_style.qss");
    stylesheet.open(QFile::ReadOnly);
    QByteArray restiledCss = stylesheet.readAll();
    app.setStyleSheet(QLatin1String(ParseToPalette(restiledCss, idx)));
}

HomeWindow* MainWindow::GetHomeWindow() const {
    return home;
}

SensorsWindow* MainWindow::GetSensorWindow() const {
    return sensors;
}

NotificationWindow* MainWindow::GetNotificationWindow() const {
    return notifications;
}

ManagmentWindow* MainWindow::GetManagmentWindow() const {
    return managment;
}