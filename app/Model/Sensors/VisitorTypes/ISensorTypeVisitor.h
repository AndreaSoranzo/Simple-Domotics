#ifndef ISensorTypeVisitor_H
#define ISensorTypeVisitor_H

class GroundSensor;
class HumiditySensor;
class SmokeSensor;
class SolarSensor;
class TemperatureSensor;
class WindSensor;

class ISensorTypeVisitor {
   public:
    virtual ~ISensorTypeVisitor() = default;

    virtual void visit(HumiditySensor& sens) = 0;
    virtual void visit(WindSensor& sens) = 0;
    virtual void visit(TemperatureSensor& sens) = 0;
    virtual void visit(SolarSensor& sens) = 0;
    virtual void visit(GroundSensor& sens) = 0;
    virtual void visit(SmokeSensor& sens) = 0;
};

#endif  // !ISensorTypeVisitor_H