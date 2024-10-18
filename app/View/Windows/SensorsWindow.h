#ifndef SensorsWindow_H
#define SensorsWindow_H

#include <QStackedLayout>

#include "../../Observers/ISensorListObserver.h"
#include "../CustomWidgets/Renderers/IRendererStrategy.h"
#include "GenericWindow/GenericWindow.h"
#include "SubPanels/EditPanel.h"
#include "SubPanels/ListPanel.h"
#include "SubPanels/SensorViewer.h"

class SensorsWindow : public GenericWindow, public ISensorListObserver {
    Q_OBJECT
   private:
    QStackedLayout* panels;
    SensorViewer* viewPanel;
    ListPanel* listPanel;
    EditPanel* editPanel;

   public:
    explicit SensorsWindow(QWidget* parent = 0);

    void NotifyAdd(const std::vector<const SensorItem*>& list) override;
    void NotifySearch(const std::vector<unsigned int>& list) override;
    void NotifySimulation(const std::vector<double>& list) override;

    EditPanel* GetEditPanel() const;
    ListPanel* GetListPanel() const;
    SensorViewer* GetSensorViewer() const;

    void RevertToDefaultState() override;

   signals:
    void OnOpenSensor(unsigned int idx);

};

#endif  // !SensorsWindow_H