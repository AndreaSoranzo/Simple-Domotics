#include "WidgetsEffects.h"

#include <QGraphicsEffect>

void WidgetsEffects::ApplyShadow(QWidget* widget, int radius, int Xoffset, int Yoffset, const QColor& color) {
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(radius);
    effect->setXOffset(Xoffset);
    effect->setYOffset(Yoffset);
    effect->setColor(color);
    widget->setGraphicsEffect(effect);
}