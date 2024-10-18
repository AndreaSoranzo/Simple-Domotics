#ifndef WidgetsEffects_H
#define WidgetsEffects_H

#include <QWidget>

class WidgetsEffects {
   private:
    WidgetsEffects();

   public:
    static void ApplyShadow(QWidget* widget, int radius = 5, int Xoffset = 0, int Yoffset = 0, const QColor& color = Qt::black);
};

#endif  // !WidgetsEffects_H