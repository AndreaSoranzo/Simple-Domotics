#ifndef MeanNoiseParams_H
#define MeanNoiseParams_H

#include <QSpinBox>

#include "AbstractParamsInput.h"

class MeanNoiseParams : public AbstractParamsInput {
    Q_OBJECT
   private:
    QSpinBox* mean;
    QSpinBox* noise;

   public:
    explicit MeanNoiseParams(QWidget* parent = 0);
    void ClearInput() override;
};

#endif  // !MeanNoiseParams_H