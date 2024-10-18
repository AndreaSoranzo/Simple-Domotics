#ifndef NotificationWindow_H
#define NotificationWindow_H

#include <QStackedWidget>
#include <QString>
#include <QWidget>

#include "../../Observers/INotificationObserver.h"
#include "GenericWindow/GenericWindow.h"
#include "SubPanels/NotificationListPanel.h"
#include "SubPanels/NotificationViewer.h"

class NotificationWindow : public GenericWindow, public INotificationObserver {
    Q_OBJECT
   private:
    QStackedWidget* panels;

    NotificationListPanel* listPanel;
    NotificationViewer* viewerPanel;

   public:
    explicit NotificationWindow(QWidget* parent = 0);
    void Notify(const std::string& title, const std::string& text, const std::string& time) override;

    void RevertToDefaultState() override;

   signals:
    void OnAddNotification(unsigned int unreadNotifications);

   public slots:
    void ShowNotification(const QString& title, const QString& text);
};

#endif  // !NotificationWindow_H