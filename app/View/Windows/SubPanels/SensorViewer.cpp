#include "SensorViewer.h"

#include <QPlainTextEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>

#include "../../CustomWidgets/InfoView/AbstractInfoView.h"
#include "../../Utils/RenderSvg.h"

SensorViewer::SensorViewer(QWidget* parent) : QWidget(parent), id(0) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(8);

    QLabel* title = new QLabel("Sensor");
    title->setObjectName("subtitle");

    QHBoxLayout* sensorNameLay = new QHBoxLayout();
    sensorNameLay->setContentsMargins(0, 0, 20, 0);
    sensorNameLay->setSpacing(20);

    sensorIcon = new QLabel();
    sensorIcon->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sensorIcon->setAlignment(Qt::AlignHCenter);
    sensorIcon->setFixedSize(70, 70);
    sensorNameLabel = new QLabel();  // name
    sensorNameLabel->setAlignment(Qt::AlignVCenter);
    sensorNameLabel->setObjectName("card-list-type");
    sensorTypeLabel = new QLabel();  // type
    sensorTypeLabel->setAlignment(Qt::AlignVCenter);
    sensorTypeLabel->setObjectName("card-list-name");
    QLabel* divLabel = new QLabel("|");  // type
    divLabel->setAlignment(Qt::AlignVCenter);
    distributionTypeLabel = new QLabel();  // type
    distributionTypeLabel->setAlignment(Qt::AlignVCenter);
    distributionTypeLabel->setObjectName("card-list-name");

    sensorNameLay->addWidget(sensorIcon);
    sensorNameLay->addWidget(sensorNameLabel);
    sensorNameLay->addStretch();
    sensorNameLay->addWidget(sensorTypeLabel);
    sensorNameLay->addWidget(divLabel);
    sensorNameLay->addWidget(distributionTypeLabel);

    QHBoxLayout* infoLay = new QHBoxLayout();

    QWidget* scollContainner = new QWidget();
    scollLay = new QVBoxLayout(scollContainner);
    scollLay->setContentsMargins(0, 0, 10, 10);
    scollLay->setSpacing(50);
    scollLay->setAlignment(Qt::AlignTop);

    QVBoxLayout* moreInfoLay = new QVBoxLayout();
    moreInfoLay->setSpacing(5);

    QLabel* moreInfoLabel = new QLabel("> About this sensor");
    moreInfoLabel->setObjectName("card-grid-name");

    moreInfoBox = new QTextEdit();  // more info
    moreInfoBox->setObjectName("moreInfoBox");
    moreInfoBox->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    moreInfoBox->setReadOnly(true);

    moreInfoLay->addWidget(moreInfoLabel);
    moreInfoLay->addWidget(moreInfoBox);

    scollLay->addLayout(moreInfoLay);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setFocusPolicy(Qt::NoFocus);
    scrollArea->verticalScrollBar()->setSingleStep(5);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scollContainner);

    sensorInfoLay = new QVBoxLayout();

    QWidget* btnContainter = new QWidget();
    QVBoxLayout* btnLay = new QVBoxLayout(btnContainter);

    QPushButton* startBtn = new QPushButton("Start Simulation");
    startBtn->setObjectName("simBtn");
    startBtn->setFixedHeight(30);
    startBtn->setFocusPolicy(Qt::NoFocus);
    QPushButton* resetBtn = new QPushButton("Reset Data");
    resetBtn->setObjectName("simBtn");
    resetBtn->setFixedHeight(30);
    resetBtn->setFocusPolicy(Qt::NoFocus);
    QPushButton* backBtn = new QPushButton("Back");
    backBtn->setObjectName("simBtn");
    backBtn->setFixedHeight(30);
    backBtn->setFocusPolicy(Qt::NoFocus);

    btnLay->addWidget(startBtn);
    btnLay->addWidget(resetBtn);
    btnLay->addSpacing(30);
    btnLay->addWidget(backBtn);

    sensorInfoLay->addWidget(btnContainter, 0, Qt::AlignBottom);

    infoLay->addWidget(scrollArea, 3);
    infoLay->addLayout(sensorInfoLay, 1);

    mainLayout->addWidget(title);
    mainLayout->addLayout(sensorNameLay);
    mainLayout->addLayout(infoLay);

    connect(startBtn, &QPushButton::pressed, this, [&]() -> void { emit OnSimulationStart(id); });
    connect(resetBtn, &QPushButton::pressed, this, [&]() -> void { chart->Clear(); emit OnSimulationReset(id); });
    connect(backBtn, &QPushButton::pressed, this, &SensorViewer::OnReturnList);
}

void SensorViewer::SetNameSensor(const QString& name) {
    sensorNameLabel->setText(name);
}

void SensorViewer::SetTypeSensor(const QString& type) {
    sensorTypeLabel->setText(type);
}

void SensorViewer::SetTypeDistribution(const QString& type) {
    distributionTypeLabel->setText(type);
}

void SensorViewer::SetIconSensor(const QString& path) {
    sensorIcon->setPixmap(renderSVG(path, QSize(70, 70)));
}

void SensorViewer::SetMoreInfoText(const QString& text) {
    moreInfoBox->setPlainText(text);
    QMargins margins = moreInfoBox->contentsMargins();
    QSizeF documentSize = moreInfoBox->document()->documentLayout()->documentSize();
    int height = documentSize.height() + margins.top() + margins.bottom() + 20;
    moreInfoBox->setFixedHeight(height);
}

void SensorViewer::SetChartType(AbstractChart* newChart) {
    if (scollLay->itemAt(0)->widget() && dynamic_cast<AbstractChart*>(scollLay->itemAt(0)->widget())) {
        QLayoutItem* item = scollLay->takeAt(0);
        delete item->widget();
        delete item;
    }
    chart = newChart;
    scollLay->insertWidget(0, chart);
}

void SensorViewer::SetId(unsigned int id) {
    this->id = id;
}

void SensorViewer::UpdateValues(const std::vector<double>& values) {
    chart->AddData(values);
    emit OnValuesUpdated();
}

void SensorViewer::SetInfoPanel(QWidget* panel) {
    if (sensorInfoLay->itemAt(0)->widget() && dynamic_cast<AbstractInfoView*>(sensorInfoLay->itemAt(0)->widget())) {
        QLayoutItem* item = sensorInfoLay->takeAt(0);
        item->widget()->setParent(nullptr);
        delete item->widget();
        delete item;
    }
    sensorInfoLay->insertWidget(0, panel, 1, Qt::AlignVCenter);
}
