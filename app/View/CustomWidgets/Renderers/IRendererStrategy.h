#ifndef IRenderStrategy_H
#define IRenderStrategy_H

#include <QGridLayout>
#include <vector>

#include "../../../Utils/SensorItem.h"
#include "../../Utils/ItemButtons.h"

class IRendererStrategy {
   public:
    virtual void render(QGridLayout* layout, const std::vector<const SensorItem*>& items, std::vector<ItemButtons>& buttons) const = 0;
    virtual ~IRendererStrategy() = default;
};

#endif  // !IRenderStrategy_H