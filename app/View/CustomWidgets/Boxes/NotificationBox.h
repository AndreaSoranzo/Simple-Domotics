#ifndef NotificationBox_H
#define NotificationBox_H

#include <QLabel>
#include <QMouseEvent>
#include <QString>

#include "../../Utils/QWidgetFix.h"

class NotificationBox : public QWidgetFix {
    Q_OBJECT
   private:
    const QString title;
    const QString text;

    QLabel* icon;

   protected:
    void
    mousePressEvent(QMouseEvent* event) override;

   public:
    NotificationBox(const QString& title,
                    const QString& text,
                    const QString& time,
                    QWidget* parent = 0);
   signals:
    void pressed(const QString& title, const QString& text);
};

#endif  // !NotificationBox_H