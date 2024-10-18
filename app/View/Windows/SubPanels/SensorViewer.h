#ifndef SensorViewer_H
#define SensorViewer_H

#include <QHBoxLayout>
#include <QLabel>
#include <QTextDocument>
#include <QWidget>
#include <vector>

#include "../../CustomWidgets/ChartTypes/AbstractChart.h"

class SensorViewer : public QWidget {
    Q_OBJECT
   private:
    unsigned int id;
    QLabel* sensorNameLabel;
    QLabel* sensorTypeLabel;
    QLabel* distributionTypeLabel;
    QLabel* sensorIcon;
    QTextEdit* moreInfoBox;

    QVBoxLayout* sensorInfoLay;
    QVBoxLayout* scollLay;

    AbstractChart* chart;

   public:
    explicit SensorViewer(QWidget* parent = 0);

    void SetId(unsigned int id);
    void SetNameSensor(const QString& name);
    void SetTypeSensor(const QString& type);
    void SetTypeDistribution(const QString& type);
    void SetIconSensor(const QString& path);
    void SetMoreInfoText(const QString& text);
    void SetChartType(AbstractChart* newChart);

    void UpdateValues(const std::vector<double>& values);
    void SetInfoPanel(QWidget* panel);

   signals:
    void OnSimulationStart(unsigned int id) const;
    void OnSimulationReset(unsigned int id) const;
    void OnValuesUpdated() const;
    void OnReturnList();
};

#endif  // !SensorView_H