#ifndef AbstractParamsInput_H
#define AbstractParamsInput_H

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <map>

#include "ParamsEnum.h"

class AbstractParamsInput : public QWidget {
    Q_OBJECT
   protected:
    std::map<const Param, unsigned int> params;

    QVBoxLayout* layout;

   public:
    explicit AbstractParamsInput(QWidget* parent = 0);

    unsigned int GetParam(const Param& param) const;
    virtual void ClearInput() = 0;
};

#endif  // !AbstractParamsInput_H