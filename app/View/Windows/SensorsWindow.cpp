#include "SensorsWindow.h"

#include <QVBoxLayout>

#include "../CustomWidgets/Header.h"

SensorsWindow::SensorsWindow(QWidget* parent) : GenericWindow("Here all your connected devices...",parent) {
    listPanel = new ListPanel();
    viewPanel = new SensorViewer();
    editPanel = new EditPanel();

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);

    panels = new QStackedLayout();
    panels->addWidget(listPanel);
    panels->addWidget(viewPanel);
    panels->addWidget(editPanel);

    mainLayout->addWidget(GetHeader());
    mainLayout->addLayout(panels);

    panels->setCurrentIndex(0);

    connect(listPanel, &ListPanel::OnEdit, this, [&](unsigned int) -> void { panels->setCurrentIndex(2); });
    connect(listPanel, &ListPanel::OnInspect, this, [&](unsigned int) -> void { panels->setCurrentIndex(1); });

    connect(editPanel, &EditPanel::OnEditComplete, this, [&](unsigned int) -> void { listPanel->ClearSearch(); });
    connect(editPanel, &EditPanel::OnApply, this, &SensorsWindow::RevertToDefaultState);

    connect(viewPanel, &SensorViewer::OnReturnList, this, &SensorsWindow::RevertToDefaultState);
}

void SensorsWindow::NotifyAdd(const std::vector<const SensorItem*>& list) {
    this->listPanel->UpdateCache(list);
}

void SensorsWindow::NotifySearch(const std::vector<unsigned int>& list) {
    this->listPanel->Select(list);
}

void SensorsWindow::NotifySimulation(const std::vector<double>& list) {
    viewPanel->UpdateValues(list);
}

EditPanel* SensorsWindow::GetEditPanel() const {
    return editPanel;
}

ListPanel* SensorsWindow::GetListPanel() const {
    return listPanel;
}

SensorViewer* SensorsWindow::GetSensorViewer() const {
    return viewPanel;
}

void SensorsWindow::RevertToDefaultState() {
    listPanel->ClearSearch();
    panels->setCurrentIndex(0);
}
