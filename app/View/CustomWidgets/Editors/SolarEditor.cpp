#include "SolarEditor.h"

#include "../../../Utils/TypeHelper.h"

SolarEditor::SolarEditor(const QString& name, const QString& brand, const QString& moreInfo, const QString& type, QWidget* parent) : SimpleEditor(name, brand, moreInfo, parent) {
    certificationType = new QComboBox();

    int i = 0;
    int idx = 0;
    for (std::string& certification : TypeHelper::GetAllSolarCertification()) {
        if (certification.compare(type.toStdString()) == 0) {
            idx = i;
        }
        certificationType->addItem(QString::fromStdString(certification));
        i++;
    }
    certificationType->setCurrentIndex(idx);

    connect(certificationType, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [&]() -> void { isChanged = true; });
    AddFormRow("Certification:", certificationType);
}

const QString SolarEditor::GetCertificaion() const {
    return certificationType->currentText();
}
