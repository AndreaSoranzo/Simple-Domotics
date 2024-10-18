#ifndef ISensorClassVisitor_H
#define ISensorClassVisitor_H

class AlertSensor;
class InfoSensor;

class ISensorClassVisitor {
   public:
    virtual ~ISensorClassVisitor() = default;

    virtual void visit(InfoSensor& sens) = 0;
    virtual void visit(AlertSensor& sens) = 0;
};

#endif  // !ISensorClassVisitor_H