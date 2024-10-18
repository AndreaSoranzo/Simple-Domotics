#include "ManagmentWindow.h"

#include "../CustomWidgets/Header.h"

ManagmentWindow::ManagmentWindow(QWidget* parent) : GenericWindow("Add or save your sensors...",parent) {
    addPanel = new AddPanel();
    managmentPanel = new ManagmentPanel();

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);

    panels = new QStackedLayout();
    panels->addWidget(managmentPanel);
    panels->addWidget(addPanel);

    mainLayout->addWidget(GetHeader());
    mainLayout->addLayout(panels, 3);

    panels->setCurrentIndex(0);

    connect(managmentPanel, &ManagmentPanel::OnAddSensor, this, &ManagmentWindow::ShowAddPanel);
    connect(addPanel, &AddPanel::ReturnToList, this, &ManagmentWindow::RevertToDefaultState);
}

void ManagmentWindow::RevertToDefaultState() {
    panels->setCurrentIndex(0);
    addPanel->ClearInput();
}

const AddPanel* ManagmentWindow::GetAddPanel() const {
    return addPanel;
}

const ManagmentPanel* ManagmentWindow::GetManagmentPanel() const {
    return managmentPanel;
}

void ManagmentWindow::ShowAddPanel() {
    panels->setCurrentIndex(1);
}
