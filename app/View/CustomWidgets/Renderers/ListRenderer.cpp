#include "ListRenderer.h"

#include "../Boxes/SensorListBox.h"

ListRenderer::ListRenderer(unsigned int spacing) : spacing(spacing) {
}

void ListRenderer::render(QGridLayout* layout, const std::vector<const SensorItem*>& items, std::vector<ItemButtons>& buttons) const {
    layout->setVerticalSpacing(spacing);
    for (std::vector<SensorItem*>::size_type i = 0; i < items.size(); i++) {
        SensorListBox* item = new SensorListBox(items[i]->id, QString::fromStdString(items[i]->icon), QString::fromStdString(items[i]->name), QString::fromStdString(items[i]->brand));
        layout->addWidget(item, i, 0);
        buttons.push_back(ItemButtons{item, item->GetEditButton(), item->GetDeleteButton()});
    }
}
