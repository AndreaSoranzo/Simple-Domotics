#ifndef SolarEditor_H
#define SolarEditor_H

#include <QComboBox>

#include "SimpleEditor.h"

class SolarEditor : public SimpleEditor {
    Q_OBJECT
   private:
    QComboBox* certificationType;

   public:
    SolarEditor(const QString& name, const QString& brand, const QString& moreInfo, const QString& type, QWidget* parent = 0);

    const QString GetCertificaion() const;
};

#endif  // !SolarEditor_H