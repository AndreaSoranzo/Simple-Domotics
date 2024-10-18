#ifndef InfoViewSelector_H
#define InfoViewSelector_H

#include <QObject>

#include "../Model/Sensors/Core/AbstractSensor.h"
#include "../Model/Sensors/VisitorTypes/ISensorTypeVisitorConst.h"
#include "../View/Windows/SubPanels/SensorViewer.h"

class InfoViewSelector : public QObject, public ISensorTypeVisitorConst {
    Q_OBJECT
   private:
    SensorViewer* sensorViewer;

    void InitViewer(const AbstractSensor& sens);

   public:
    explicit InfoViewSelector(SensorViewer* sensorViewer);
    void visit(const HumiditySensor& sens) override;
    void visit(const WindSensor& sens) override;
    void visit(const TemperatureSensor& sens) override;
    void visit(const SolarSensor& sens) override;
    void visit(const GroundSensor& sens) override;
    void visit(const SmokeSensor& sens) override;
};

#endif  // !InfoViewSelector_H