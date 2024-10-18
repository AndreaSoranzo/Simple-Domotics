#ifndef TemperatureEditor_H
#define TemperatureEditor_H

#include <QSpinBox>

#include "SimpleEditor.h"

class TemperatureEditor : public SimpleEditor {
    Q_OBJECT
   private:
    QSpinBox* batteriesInput;

   public:
    TemperatureEditor(const QString& name, const QString& brand, const QString& moreInfo, int batteries, QWidget* parent = 0);

    unsigned int GetBatteries() const;
};

#endif  // !TemperatureEditor_H