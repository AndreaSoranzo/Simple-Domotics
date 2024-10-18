#ifndef JsonSensorVisitor_H
#define JsonSensorVisitor_H

#include <QJsonArray>
#include <QJsonObject>
#include <vector>

#include "../Sensors/GroundSensor.h"
#include "../Sensors/HumiditySensor.h"
#include "../Sensors/SmokeSensor.h"
#include "../Sensors/SolarSensor.h"
#include "../Sensors/TemperatureSensor.h"
#include "../Sensors/VisitorTypes/ISensorTypeVisitorConst.h"
#include "../Sensors/WindSensor.h"

class JsonSensorVisitor : public ISensorTypeVisitorConst {
   private:
    QJsonObject json;
    QJsonArray ConvertSimulationValues(const std::vector<double>& list) const;
    QJsonObject ConvertGenericInfo(const AbstractSensor& sens) const;

   public:
    void visit(const HumiditySensor& sens) override;
    void visit(const WindSensor& sens) override;
    void visit(const TemperatureSensor& sens) override;
    void visit(const SolarSensor& sens) override;
    void visit(const GroundSensor& sens) override;
    void visit(const SmokeSensor& sens) override;

    QJsonObject GetJsonObject() const;
};

#endif  // !JsonTypeVisitor_H