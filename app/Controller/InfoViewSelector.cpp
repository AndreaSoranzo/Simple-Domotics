#include "InfoViewSelector.h"

#include "../Model/Sensors/GroundSensor.h"
#include "../Model/Sensors/HumiditySensor.h"
#include "../Model/Sensors/SmokeSensor.h"
#include "../Model/Sensors/SolarSensor.h"
#include "../Model/Sensors/TemperatureSensor.h"
#include "../Model/Sensors/WindSensor.h"
#include "../View/CustomWidgets/ChartTypes/BarChart.h"
#include "../View/CustomWidgets/ChartTypes/LineChart.h"
#include "../View/CustomWidgets/InfoView/AlertInfoView.h"
#include "../View/CustomWidgets/InfoView/InfoLabel.h"
#include "../View/CustomWidgets/InfoView/SimpleInfoView.h"
#include "InfoViewDistribution.h"

void InfoViewSelector::InitViewer(const AbstractSensor& sens) {
    sensorViewer->SetId(sens.GetSensorId());
    sensorViewer->SetNameSensor(QString::fromStdString(sens.GetInfo().name));
    sensorViewer->SetTypeSensor(QString::fromStdString(sens.ToString()));
    sensorViewer->SetTypeDistribution(QString::fromStdString(sens.GetDistribution().ToString()));
    sensorViewer->SetIconSensor(QString::fromStdString(sens.GetIcon()));
    sensorViewer->SetMoreInfoText(QString::fromStdString(sens.GetInfo().moreInfo));
}

InfoViewSelector::InfoViewSelector(SensorViewer* sensorViewer) : sensorViewer(sensorViewer) {
}

void InfoViewSelector::visit(const HumiditySensor& sens) {
    InitViewer(sens);
    sensorViewer->SetChartType(new LineChart());
    SimpleInfoView* infoView = new SimpleInfoView();

    InfoViewDistributionVisitor visitor(infoView);
    sens.GetDistribution().accept(visitor);

    sensorViewer->SetInfoPanel(infoView);

    // connect OnSimulationStart update info values on the views
    connect(sensorViewer, &SensorViewer::OnValuesUpdated, this, [&, infoView]() -> void {
        infoView->UpdateMin(QString::number(sens.GetMin()) + " " + QString::fromStdString(sens.GetUnit()));
        infoView->UpdateMax(QString::number(sens.GetMax()) + " " + QString::fromStdString(sens.GetUnit()));
        infoView->UpdateAvg(QString::number(sens.GetAvg()) + " " + QString::fromStdString(sens.GetUnit()));
    });
    connect(sensorViewer, &SensorViewer::OnSimulationReset, this, [&, infoView]() -> void {
        infoView->UpdateMin("Undef");
        infoView->UpdateMax("Undef");
        infoView->UpdateAvg("Undef");
    });
    connect(infoView, &SimpleInfoView::destroyed, this, [&]() -> void {
        sensorViewer->disconnect(this);
    });
}

void InfoViewSelector::visit(const WindSensor& sens) {
    InitViewer(sens);
    sensorViewer->SetChartType(new BarChart());
    SimpleInfoView* infoView = new SimpleInfoView();

    InfoViewDistributionVisitor visitor(infoView);
    sens.GetDistribution().accept(visitor);

    sensorViewer->SetInfoPanel(infoView);

    connect(sensorViewer, &SensorViewer::OnValuesUpdated, this, [&, infoView]() -> void {
        infoView->UpdateMin(QString::number(sens.GetMin()) + " " + QString::fromStdString(sens.GetUnit()));
        infoView->UpdateMax(QString::number(sens.GetMax()) + " " + QString::fromStdString(sens.GetUnit()));
        infoView->UpdateAvg(QString::number(sens.GetAvg()) + " " + QString::fromStdString(sens.GetUnit()));
    });
    connect(sensorViewer, &SensorViewer::OnSimulationReset, this, [&, infoView]() -> void {
        infoView->UpdateMin("Undef");
        infoView->UpdateMax("Undef");
        infoView->UpdateAvg("Undef");
    });
    connect(infoView, &SimpleInfoView::destroyed, this, [&]() -> void {
        sensorViewer->disconnect(this);
    });
}

void InfoViewSelector::visit(const TemperatureSensor& sens) {
    InitViewer(sens);
    sensorViewer->SetChartType(new BarChart());
    SimpleInfoView* infoView = new SimpleInfoView();

    InfoViewDistributionVisitor visitor(infoView);
    sens.GetDistribution().accept(visitor);

    QLabel* chargeLabel = CreateInfoLabel("Current Charge\n" + QString::number(sens.GetCurrentCharge()), "card-list-name");
    infoView->AddInfo(chargeLabel, 2, 0, 1, 2);

    sensorViewer->SetInfoPanel(infoView);

    connect(sensorViewer, &SensorViewer::OnValuesUpdated, this, [&, infoView]() -> void {
        infoView->UpdateMin(QString::number(sens.GetMin()) + " " + QString::fromStdString(sens.GetUnit()));
        infoView->UpdateMax(QString::number(sens.GetMax()) + " " + QString::fromStdString(sens.GetUnit()));
        infoView->UpdateAvg(QString::number(sens.GetAvg()) + " " + QString::fromStdString(sens.GetUnit()));
    });
    connect(sensorViewer, &SensorViewer::OnSimulationReset, this, [&, infoView]() -> void {
        infoView->UpdateMin("Undef");
        infoView->UpdateMax("Undef");
        infoView->UpdateAvg("Undef");
    });

    connect(infoView, &SimpleInfoView::destroyed, this, [&]() -> void {
        sensorViewer->disconnect(this);
    });
}

void InfoViewSelector::visit(const SolarSensor& sens) {
    InitViewer(sens);
    sensorViewer->SetChartType(new LineChart());
    SimpleInfoView* infoView = new SimpleInfoView();

    InfoViewDistributionVisitor visitor(infoView);
    sens.GetDistribution().accept(visitor);

    QLabel* certificationLabel = CreateInfoLabel("Certification\n" + QString::fromStdString(sens.GetCertification()), "card-list-name");
    infoView->AddInfo(certificationLabel, 2, 0, 1, 2);

    sensorViewer->SetInfoPanel(infoView);

    connect(sensorViewer, &SensorViewer::OnValuesUpdated, this, [&, infoView]() -> void {
        infoView->UpdateMin(QString::number(sens.GetMin()) + " " + QString::fromStdString(sens.GetUnit()));
        infoView->UpdateMax(QString::number(sens.GetMax()) + " " + QString::fromStdString(sens.GetUnit()));
        infoView->UpdateAvg(QString::number(sens.GetAvg()) + " " + QString::fromStdString(sens.GetUnit()));
    });
    connect(sensorViewer, &SensorViewer::OnSimulationReset, this, [&, infoView]() -> void {
        infoView->UpdateMin("Undef");
        infoView->UpdateMax("Undef");
        infoView->UpdateAvg("Undef");
    });
    connect(infoView, &SimpleInfoView::destroyed, this, [&]() -> void {
        sensorViewer->disconnect(this);
    });
}

void InfoViewSelector::visit(const GroundSensor& sens) {
    InitViewer(sens);
    sensorViewer->SetChartType(new LineChart());
    AlertInfoView* infoView = new AlertInfoView(sens.GetDangerLV());

    sensorViewer->SetInfoPanel(infoView);

    connect(sensorViewer, &SensorViewer::OnValuesUpdated, this, [&, infoView]() -> void {
        infoView->UpdateLastTrigger(QString::fromStdString(sens.GetLastTrigger()));
    });
    connect(sensorViewer, &SensorViewer::OnSimulationReset, this, [&, infoView]() -> void {
        infoView->UpdateLastTrigger("Undef.");
    });
    connect(infoView, &SimpleInfoView::destroyed, this, [&]() -> void {
        sensorViewer->disconnect(this);
    });
}

void InfoViewSelector::visit(const SmokeSensor& sens) {
    InitViewer(sens);
    sensorViewer->SetChartType(new LineChart());
    AlertInfoView* infoView = new AlertInfoView(sens.GetDangerLV());

    sensorViewer->SetInfoPanel(infoView);

    connect(sensorViewer, &SensorViewer::OnValuesUpdated, this, [&, infoView]() -> void {
        infoView->UpdateLastTrigger(QString::fromStdString(sens.GetLastTrigger()));
    });
    connect(sensorViewer, &SensorViewer::OnSimulationReset, this, [&, infoView]() -> void {
        infoView->UpdateLastTrigger("Undef.");
    });
    connect(infoView, &SimpleInfoView::destroyed, this, [&]() -> void {
        sensorViewer->disconnect(this);
    });
}
