#ifndef EditorInjector_H
#define EditorInjector_H

#include <QObject>

#include "../Model/Sensors/VisitorTypes/ISensorTypeVisitor.h"
#include "../View/Windows/SubPanels/EditPanel.h"

class EditorInjector : public QObject, public ISensorTypeVisitor {
    Q_OBJECT
   private:
    EditPanel* editPanel;

   public:
    explicit EditorInjector(EditPanel* editPanel);
    void visit(HumiditySensor& sens) override;
    void visit(WindSensor& sens) override;
    void visit(TemperatureSensor& sens) override;
    void visit(SolarSensor& sens) override;
    void visit(GroundSensor& sens) override;
    void visit(SmokeSensor& sens) override;
};

#endif  // !EditorInjector_H