#ifndef AlertEditor_H
#define AlertEditor_H

#include <QSpinBox>

#include "SimpleEditor.h"

class AlertEditor : public SimpleEditor {
    Q_OBJECT
   private:
    QSpinBox* dangerInput;

   public:
    AlertEditor(const QString& name, const QString& brand, const QString& moreInfo, int danger, QWidget* parent = 0);

    int GetDanger() const;
};

#endif  // !AlertEditor_H