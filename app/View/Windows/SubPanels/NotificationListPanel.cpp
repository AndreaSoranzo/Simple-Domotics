#include "NotificationListPanel.h"

#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>

#include "../../CustomWidgets/Boxes/NotificationBox.h"

NotificationListPanel::NotificationListPanel(QWidget* parent) : QWidget(parent), unreadNotifiactions(0) {
    QVBoxLayout* contentLayout = new QVBoxLayout(this);
    QLabel* subtitle = new QLabel("Notifications");
    subtitle->setObjectName("subtitle");
    contentLayout->addWidget(subtitle);

    QWidget* container = new QWidget();
    notificationLayout = new QVBoxLayout(container);
    notificationLayout->setSpacing(15);
    notificationLayout->setAlignment(Qt::AlignTop);

    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setFocusPolicy(Qt::NoFocus);
    scroll_area->verticalScrollBar()->setSingleStep(5);
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);

    contentLayout->addWidget(scroll_area);
}

void NotificationListPanel::AddNotification(const QString& title, const QString& text, const QString& time) {
    NotificationBox* notification = new NotificationBox(title, text, time);
    notificationLayout->insertWidget(0, notification);
    unreadNotifiactions++;
    connect(notification, &NotificationBox::pressed, this, [&](const QString& title, const QString& text) -> void {
        unreadNotifiactions = (unreadNotifiactions != 0) ? unreadNotifiactions - 1 : 0;
        emit OpenNotification(title, text);
    });
}

unsigned int NotificationListPanel::GetUnreadNotifications() const {
    return unreadNotifiactions;
}
