#ifndef SensorListBox_H
#define SensorListBox_H

#include "AbstractSensorBox.h"

class SensorListBox : public AbstractSensorBox {
    Q_OBJECT

   public:
    SensorListBox(unsigned int id,
                  const QString& iconPath,
                  const QString& name,
                  const QString& type,
                  QWidget* parent = 0);
};

#endif  // !SensorListBox_H