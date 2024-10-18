#include "ListPanel.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>

#include "../../CustomWidgets/Renderers/GridRenderer.h"
#include "../../CustomWidgets/Renderers/ListRenderer.h"
#include "../../Utils/ItemButtons.h"

QPushButton* ListPanel::CreateRendererButton(const QString& iconPath, int width, int height, void (ListPanel::*slot)()) {
    QPushButton* btn = new QPushButton();
    btn->setObjectName("rendererBtn");
    btn->setFocusPolicy(Qt::NoFocus);
    btn->setIcon(QIcon(iconPath));
    btn->setIconSize(QSize(20, 20));
    btn->setFixedSize(width, height);

    connect(btn, &QPushButton::pressed, this, slot);

    return btn;
}

void ListPanel::FetchAllItems() {
    displayedItems.clear();
    for (const auto& item : cache) {
        displayedItems.push_back(item.second);
    }
}

void ListPanel::ClearList() {
    while (renderLay->count()) {
        QWidget* widget = renderLay->itemAt(0)->widget();
        if (widget) {
            renderLay->removeWidget(widget);
            delete widget;
        }
    }
}

void ListPanel::UpdateList() {
    std::vector<ItemButtons> buttons;
    ClearList();
    renderer->render(renderLay, displayedItems, buttons);

    for (std::vector<ItemButtons>::size_type i = 0; i < buttons.size(); i++) {
        unsigned int id = displayedItems[i]->id;
        if (buttons[i].box) {
            connect(buttons[i].box, &AbstractSensorBox::pressed, this, [&, id]() -> void { emit OnInspect(id); });
        }
        if (buttons[i].editBtn) {
            connect(buttons[i].editBtn, &QPushButton::pressed, this, [&, id]() -> void { emit OnEdit(id); });
        }
        if (buttons[i].deleteBtn) {
            connect(buttons[i].deleteBtn, &QPushButton::pressed, this, [&, id]() -> void { emit searchPanel->TriggerSearch(), DeleteItem(id); });
        }
    }
    searchPanel->UpdateResults(displayedItems.size());
}

ListPanel::ListPanel(QWidget* parent) : QWidget(parent) {
    searchPanel = new SearchPanel();
    renderer = new ListRenderer(20);

    QVBoxLayout* searchLay = new QVBoxLayout(this);

    // Renderer selectors

    QHBoxLayout* rendererBtnLay = new QHBoxLayout();
    rendererBtnLay->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    rendererBtnLay->setSpacing(10);

    QPushButton* listBtn = CreateRendererButton(":assets/icons/render_list.svg", 40, 40, &ListPanel::SetList);
    QPushButton* gridBtn = CreateRendererButton(":assets/icons/render_grid.svg", 40, 40, &ListPanel::SetGrid);

    rendererBtnLay->addWidget(listBtn);
    rendererBtnLay->addWidget(gridBtn);

    // renderer display
    QVBoxLayout* rendererLay = new QVBoxLayout();

    QLabel* rendererTitle = new QLabel("Sensors");
    rendererTitle->setObjectName("subtitle");
    rendererTitle->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    QWidget* rendererContainer = new QWidget();
    rendererContainer->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    renderLay = new QGridLayout(rendererContainer);
    renderLay->setHorizontalSpacing(10);
    renderLay->setVerticalSpacing(20);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setFocusPolicy(Qt::NoFocus);
    scrollArea->verticalScrollBar()->setSingleStep(5);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(rendererContainer);

    rendererLay->addWidget(rendererTitle);
    rendererLay->addWidget(scrollArea);

    searchLay->addWidget(searchPanel);
    searchLay->addLayout(rendererBtnLay);
    searchLay->addLayout(rendererLay, 3);

    connect(listBtn, &QPushButton::pressed, this, &ListPanel::SetList);
    connect(gridBtn, &QPushButton::pressed, this, &ListPanel::SetGrid);

    connect(searchPanel, &SearchPanel::OnSearch, this, &ListPanel::OnSearch);
}

ListPanel::~ListPanel() {
    ClearAllItems();
}

void ListPanel::UpdateCache(const std::vector<const SensorItem*>& list) {
    for (const SensorItem* item : list) {
        if (cache.count(item->id) > 0) {  // already present delete the old item
            delete cache[item->id];
            cache[item->id] = item;
        } else {
            cache[item->id] = item;
        }
    }
    FetchAllItems();
    UpdateList();
}

void ListPanel::ClearAllItems() {
    displayedItems.clear();
    for (auto& item : cache) {
        delete item.second;
    }
    cache.clear();
}

void ListPanel::ClearSearch() {
    searchPanel->ClearInput();
}

void ListPanel::Select(const std::vector<unsigned int>& list) {
    displayedItems.clear();
    for (unsigned int id : list) {
        if (cache.count(id) > 0) {
            displayedItems.push_back(cache[id]);
        }
    }
    UpdateList();
}

void ListPanel::DeleteItem(unsigned int idx) {
    QMessageBox msgBox;
    msgBox.setText("Are you sure to delete this sensor?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int choise = msgBox.exec();

    if (choise == QMessageBox::Ok) {
        delete cache[idx];
        cache.erase(idx);
        FetchAllItems();
        UpdateList();
        emit OnDelete(idx);
    }
}

void ListPanel::SetList() {
    if (dynamic_cast<ListRenderer*>(renderer)) {  // already in the same configuration
        return;
    }

    delete renderer;
    renderer = new ListRenderer(20);
    UpdateList();
}

void ListPanel::SetGrid() {
    if (dynamic_cast<GridRenderer*>(renderer)) {
        return;
    }
    delete renderer;
    renderer = new GridRenderer(5);
    UpdateList();
}
