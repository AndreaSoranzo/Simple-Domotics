#ifndef ISensorClassVisitorConst_H
#define ISensorClassVisitorConst_H

class AlertSensor;
class InfoSensor;

class ISensorClassVisitorConst {
   public:
    virtual ~ISensorClassVisitorConst() = default;

    virtual void visit(const InfoSensor& sens) = 0;
    virtual void visit(const AlertSensor& sens) = 0;
};

#endif  // !ISensotClassVisitorConst_H