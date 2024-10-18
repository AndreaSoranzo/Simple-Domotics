#include "GridRenderer.h"

#include "../Boxes/SensorGridBox.h"

GridRenderer::GridRenderer(unsigned int columnNumber) : columnNumber(columnNumber) {
}

void GridRenderer::render(QGridLayout* layout, const std::vector<const SensorItem*>& items, std::vector<ItemButtons>& buttons) const {
    for (std::vector<SensorItem*>::size_type i = 0; i < items.size(); i++) {
        SensorGridBox* item = new SensorGridBox(items[i]->id, QString::fromStdString(items[i]->icon), QString::fromStdString(items[i]->name), QString::fromStdString(items[i]->brand));
        layout->addWidget(item, i / columnNumber, i % columnNumber, {Qt::AlignTop, Qt::AlignCenter});

        buttons.push_back(ItemButtons{item, item->GetEditButton(), item->GetDeleteButton()});
    }
}
