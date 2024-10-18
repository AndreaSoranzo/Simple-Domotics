#ifndef SensorGridBox_H
#define SensorGridBox_H

#include "AbstractSensorBox.h"

class SensorGridBox : public AbstractSensorBox {
    Q_OBJECT

   public:
    SensorGridBox(unsigned int id,
                  const QString& iconPath,
                  const QString& name,
                  const QString& brand,
                  QWidget* parent = 0);
};

#endif  // !SensorGridBox_H