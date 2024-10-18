#ifndef QWidgetFix_H
#define QWidgetFix_H

#include <QPainter>
#include <QStyleOption>
#include <QWidget>

class QWidgetFix : public QWidget {
    Q_OBJECT
   public:
    explicit QWidgetFix(QWidget* parent = 0);
    void paintEvent(QPaintEvent*);  // for implementing css for custom widgets
};

#endif  // !QWidgetFix_H