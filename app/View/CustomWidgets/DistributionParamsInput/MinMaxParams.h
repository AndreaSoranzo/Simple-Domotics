#ifndef MinMaxParams_H
#define MinMaxParams_H

#include <QSpinBox>

#include "AbstractParamsInput.h"

class MinMaxParams : public AbstractParamsInput {
    Q_OBJECT
   private:
    QSpinBox* max;
    QSpinBox* min;

   public:
    explicit MinMaxParams(QWidget* parent = 0);
    void ClearInput() override;
};

#endif  // !MinMaxParams_H