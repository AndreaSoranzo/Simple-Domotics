#include "AddPanel.h"

#include <QMessageBox>
#include <QStandardItemModel>

#include "../../../Utils/TypeHelper.h"
#include "../../CustomWidgets/DistributionParamsInput/DangerParamsInput.h"
#include "../../CustomWidgets/DistributionParamsInput/MeanNoiseParams.h"
#include "../../CustomWidgets/DistributionParamsInput/MinMaxParams.h"

QWidget* AddPanel::CreateInputWidget(const QString& labelText1) const {
    QWidget* container = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(container);
    QLabel* label = new QLabel(labelText1);
    label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    layout->addWidget(label);
    return container;
}

void AddPanel::SetComboBoxItemEnabled(QComboBox* comboBox, int index, bool enabled) {
    auto* model = qobject_cast<QStandardItemModel*>(comboBox->model());
    assert(model);
    if (!model) {
        return;
    }
    auto* item = model->item(index);
    assert(item);
    if (!item) {
        return;
    }
    item->setEnabled(enabled);
}

bool AddPanel::ValidateInput() const {
    if (typeSensor->currentText().isEmpty() || typeDistribution->currentText().isEmpty()) {
        return false;
    }
    return true;
}

AddPanel::AddPanel(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);

    QLabel* subtitle = new QLabel("New Sensor");
    subtitle->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    subtitle->setObjectName("subtitle");

    QWidget* formContainer = new QWidget();

    QGridLayout* form = new QGridLayout(formContainer);
    form->setSpacing(5);

    QWidget* nameEntry = CreateInputWidget("Name (cannot add sensor with the same name)");
    nameInput = new QLineEdit();
    nameInput->setMaxLength(10);
    nameInput->setPlaceholderText("max 10 characters");
    nameEntry->layout()->addWidget(nameInput);

    QWidget* brandEntry = CreateInputWidget("Brand");
    brandInput = new QLineEdit();
    brandInput->setMaxLength(10);
    brandInput->setPlaceholderText("max 10 characters");
    brandEntry->layout()->addWidget(brandInput);

    QWidget* infoEntry = CreateInputWidget("More info");
    infoInput = new QTextEdit();
    infoEntry->layout()->addWidget(infoInput);

    QWidget* typeSensorEntry = CreateInputWidget("Sensor Type");
    typeSensor = new QComboBox();

    typeSensor->addItem("");
    for (const std::string& sensorName : TypeHelper::GetAllSensorNames()) {
        typeSensor->addItem(QString::fromStdString(sensorName));
    }

    typeSensorEntry->layout()->addWidget(typeSensor);

    QWidget* typeDistEntry = CreateInputWidget("Distribution Type");
    typeDistribution = new QComboBox();

    typeDistribution->addItem("");
    for (const std::string& distributionName : TypeHelper::GetAllDistributionNames()) {
        typeDistribution->addItem(QString::fromStdString(distributionName));
    }
    SetComboBoxItemEnabled(typeDistribution, 1, false);

    typeDistEntry->layout()->addWidget(typeDistribution);

    QPushButton* okBtn = new QPushButton("Ok");
    okBtn->setObjectName("okBtn");
    okBtn->setFixedSize(100, 40);
    okBtn->setFocusPolicy(Qt::NoFocus);

    // extra entries
    extraContainter = new QWidget();
    extraContainter->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    QHBoxLayout* extraLayout = new QHBoxLayout(extraContainter);
    extraLayout->setContentsMargins(0, 0, 0, 0);

    dx = new QWidget();
    dx->setVisible(false);
    sx = new QWidget();
    sx->setVisible(false);
    extraSensorEntries = new QStackedLayout(sx);
    extraDistributionEntries = new QStackedLayout(dx);

    extraLayout->addWidget(sx);
    extraLayout->addWidget(dx);

    batteryEntry = CreateInputWidget("Batteries");
    batteries = new QSpinBox();
    batteryEntry->layout()->addWidget(batteries);

    certificationEntry = CreateInputWidget("Certification");
    certification = new QComboBox();

    for (std::string& cert : TypeHelper::GetAllSolarCertification()) {
        certification->addItem(QString::fromStdString(cert));
    }

    certificationEntry->layout()->addWidget(certification);

    DangerParamsInput* danger = new DangerParamsInput();
    currentParamInput = danger;

    MeanNoiseParams* meanNoise = new MeanNoiseParams();
    MinMaxParams* minMax = new MinMaxParams();

    extraSensorEntries->addWidget(batteryEntry);
    extraSensorEntries->addWidget(certificationEntry);

    extraDistributionEntries->addWidget(danger);
    extraDistributionEntries->addWidget(minMax);
    extraDistributionEntries->addWidget(meanNoise);

    form->addWidget(nameEntry, 0, 0);
    form->addWidget(brandEntry, 0, 1);
    form->addWidget(typeSensorEntry, 1, 0);
    form->addWidget(typeDistEntry, 1, 1);
    form->addWidget(extraContainter, 2, 0, 1, 2);
    form->addWidget(infoEntry, 3, 0, 1, 2);

    extraSensorEntries->setCurrentIndex(0);
    extraDistributionEntries->setCurrentIndex(0);

    mainLayout->addWidget(subtitle);
    mainLayout->addWidget(formContainer);
    mainLayout->addWidget(okBtn, 0, Qt::AlignRight);

    connect(okBtn, &QPushButton::pressed, this, &AddPanel::ReadInput);

    connect(typeSensor, &QComboBox::currentTextChanged, this, &AddPanel::UpdateSensorInputs);
    connect(typeDistribution, &QComboBox::currentTextChanged, this, &AddPanel::UpdateDestributionInputs);
}

void AddPanel::ReadInput() const {
    if (!ValidateInput()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("You need to specify a sensor and a distribution type");
        msgBox.exec();
        return;
    }
    QMessageBox msgBox;
    msgBox.setWindowTitle("Sensor added");
    msgBox.setText("Check your notificaion for more info");
    msgBox.exec();
    emit OnCreateSensor();
    emit ReturnToList();
}

void AddPanel::ClearInput() {
    nameInput->setText("");
    brandInput->setText("");
    infoInput->setText("");
    typeSensor->setCurrentIndex(0);
    typeDistribution->setCurrentIndex(0);

    currentParamInput->ClearInput();
}

const QString AddPanel::GetName() const {
    return nameInput->text();
}

const QString AddPanel::GetBrand() const {
    return brandInput->text();
}

const QString AddPanel::GetMoreInfo() const {
    return infoInput->toPlainText();
}

const QString AddPanel::GetSensorType() const {
    return typeSensor->currentText();
}

const QString AddPanel::GetDistributionType() const {
    return typeDistribution->currentText();
}

const AbstractParamsInput* AddPanel::GetParamInput() const {
    return currentParamInput;
}

int AddPanel::GetBatteries() const {
    return batteries->value();
}

const QString AddPanel::GetCertification() const {
    return certification->currentText();
}

void AddPanel::UpdateSensorInputs(const QString& s) {
    if (!typeDistribution->isEnabled()) {
        typeDistribution->setEnabled(true);
    }
    switch (TypeHelper::ToSensorType(s.toStdString())) {
        case SensorType::Ground:
        case SensorType::Smoke:
            if (sx->isVisible()) {
                sx->setVisible(false);
            }
            typeDistribution->setCurrentIndex(1);
            emit typeDistribution->currentTextChanged(typeDistribution->currentText());
            break;
        case SensorType::Humidity:
        case SensorType::Wind:
            sx->setVisible(false);
            typeDistribution->setCurrentIndex(0);
            break;
        case SensorType::Solar:
            sx->setVisible(true);
            extraSensorEntries->setCurrentIndex(1);
            typeDistribution->setCurrentIndex(0);
            break;
        case SensorType::Temperature:
            sx->setVisible(true);
            extraSensorEntries->setCurrentIndex(0);
            typeDistribution->setCurrentIndex(0);
            break;
        default:
            sx->setVisible(false);
            typeDistribution->setCurrentIndex(0);
            break;
    }
}

void AddPanel::UpdateDestributionInputs(const QString& s) {
    AbstractParamsInput* input;
    switch (TypeHelper::ToDistributionType(s.toStdString())) {
        case DistributionType::Exponential:
            typeDistribution->setEnabled(false);
            dx->setVisible(true);
            extraDistributionEntries->setCurrentIndex(0);
            // casting widget to my type
            input = dynamic_cast<AbstractParamsInput*>(extraDistributionEntries->currentWidget());
            if (input) {
                currentParamInput = input;
            }

            break;
        case DistributionType::Normal:
            dx->setVisible(true);
            extraDistributionEntries->setCurrentIndex(2);
            input = dynamic_cast<AbstractParamsInput*>(extraDistributionEntries->currentWidget());
            if (input) {
                currentParamInput = input;
            }
            break;
        case DistributionType::Uniform:
        case DistributionType::Random:
            dx->setVisible(true);
            extraDistributionEntries->setCurrentIndex(1);
            input = dynamic_cast<AbstractParamsInput*>(extraDistributionEntries->currentWidget());
            if (input) {
                currentParamInput = input;
            }
            break;
        default:
            dx->setVisible(false);
            break;
    }
}
