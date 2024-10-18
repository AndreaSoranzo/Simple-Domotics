#include "QWidgetFix.h"

QWidgetFix::QWidgetFix(QWidget *parent) : QWidget(parent) {
}

void QWidgetFix::paintEvent(QPaintEvent *) {  // for implementing css for custom widgets
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}