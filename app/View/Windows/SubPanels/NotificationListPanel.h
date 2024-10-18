#ifndef NotificationListPanel_H
#define NotificationListPanel_H

#include <QString>
#include <QVBoxLayout>
#include <QWidget>

class NotificationListPanel : public QWidget {
    Q_OBJECT
   private:
    QVBoxLayout* notificationLayout;
    unsigned int unreadNotifiactions;

   public:
    explicit NotificationListPanel(QWidget* parent = 0);
    void AddNotification(const QString& title, const QString& text, const QString& time);
    unsigned int GetUnreadNotifications() const;
   signals:
    void OpenNotification(const QString& title, const QString& text);
};

#endif  // !NotificationListPanel_H