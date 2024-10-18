#ifndef ISensorTypeVisitorConst_H
#define ISensorTypeVisitorConst_H

class GroundSensor;
class HumiditySensor;
class SmokeSensor;
class SolarSensor;
class TemperatureSensor;
class WindSensor;

class ISensorTypeVisitorConst {
   public:
    virtual ~ISensorTypeVisitorConst() = default;

    virtual void visit(const HumiditySensor& sens) = 0;
    virtual void visit(const WindSensor& sens) = 0;
    virtual void visit(const TemperatureSensor& sens) = 0;
    virtual void visit(const SolarSensor& sens) = 0;
    virtual void visit(const GroundSensor& sens) = 0;
    virtual void visit(const SmokeSensor& sens) = 0;
};

#endif  // !ISensorTypeVisitorConst_H