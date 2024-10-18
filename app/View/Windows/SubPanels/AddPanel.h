#ifndef AddViewer_H
#define AddViewer_H

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QStackedLayout>
#include <QString>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "../../CustomWidgets/DistributionParamsInput/AbstractParamsInput.h"

class AddPanel : public QWidget {
    Q_OBJECT
   private:
    QLineEdit* nameInput;
    QLineEdit* brandInput;
    QTextEdit* infoInput;
    QComboBox* typeSensor;
    QComboBox* typeDistribution;

    QStackedLayout* extraSensorEntries;
    QStackedLayout* extraDistributionEntries;

    QWidget* extraContainter;
    QWidget* dx;
    QWidget* sx;

    // temp sens
    QWidget* batteryEntry;
    QSpinBox* batteries;

    // solar sens
    QWidget* certificationEntry;
    QComboBox* certification;

    AbstractParamsInput* currentParamInput;

    QWidget* CreateInputWidget(const QString& labelText) const;
    void SetComboBoxItemEnabled(QComboBox* comboBox, int index, bool enabled);
    bool ValidateInput() const;

   public:
    explicit AddPanel(QWidget* parent = 0);

    const QString GetName() const;
    const QString GetBrand() const;
    const QString GetMoreInfo() const;
    const QString GetSensorType() const;
    const QString GetDistributionType() const;

    const AbstractParamsInput* GetParamInput() const;
    int GetBatteries() const;
    const QString GetCertification() const;

    void ClearInput();

   private slots:
    void ReadInput() const;
    void UpdateSensorInputs(const QString& s);
    void UpdateDestributionInputs(const QString& s);

   signals:
    void OnCreateSensor() const;
    void ReturnToList() const;
};

#endif  // !AddView_H