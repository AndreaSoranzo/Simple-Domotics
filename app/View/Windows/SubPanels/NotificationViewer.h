#ifndef NotificationViewer_H
#define NotificationViewer_H

#include <QLabel>
#include <QString>
#include <QWidget>

class NotificationViewer : public QWidget {
    Q_OBJECT
   private:
    QLabel* titleLabel;
    QLabel* textLabel;

   public:
    explicit NotificationViewer(QWidget* parent = 0);
    void SetTitle(const QString& title);
    void SetText(const QString& text);
   signals:
    void ReturnToList();
};

#endif  // !NotificationViewer_H