#include "NotificationWindow.h"

#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>

#include "../CustomWidgets/Header.h"

NotificationWindow::NotificationWindow(QWidget* parent) :  GenericWindow("Here some new notifications",parent) {
    viewerPanel = new NotificationViewer();
    listPanel = new NotificationListPanel();

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);

    panels = new QStackedWidget();
    panels->addWidget(listPanel);
    panels->addWidget(viewerPanel);

    mainLayout->addWidget(GetHeader());
    mainLayout->addWidget(panels, 3);

    panels->setCurrentIndex(0);

    connect(listPanel, &NotificationListPanel::OpenNotification, this, [&](const QString& title, const QString& text) -> void {
        emit OnAddNotification(listPanel->GetUnreadNotifications());
        ShowNotification(title, text);
    });
    connect(viewerPanel, &NotificationViewer::ReturnToList, this, &NotificationWindow::RevertToDefaultState);
}

void NotificationWindow::Notify(const std::string& title, const std::string& text, const std::string& time) {
    listPanel->AddNotification(QString::fromStdString(title), QString::fromStdString(text), QString::fromStdString(time));
    emit OnAddNotification(listPanel->GetUnreadNotifications());
}

void NotificationWindow::RevertToDefaultState() {
    panels->setCurrentIndex(0);
}

void NotificationWindow::ShowNotification(const QString& title, const QString& text) {
    viewerPanel->SetTitle(title);
    viewerPanel->SetText(text);
    panels->setCurrentIndex(1);
}