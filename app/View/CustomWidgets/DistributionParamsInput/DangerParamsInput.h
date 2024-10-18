#ifndef DangerParamsInput_H
#define DangerParamsInput_H

#include <QSpinBox>

#include "AbstractParamsInput.h"

class DangerParamsInput : public AbstractParamsInput {
    Q_OBJECT
   private:
    QSpinBox* danger;

   public:
    explicit DangerParamsInput(QWidget* parent = 0);
    void ClearInput() override;
};

#endif  // !DangerParamsInput_H