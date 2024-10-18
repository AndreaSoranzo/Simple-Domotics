#ifndef GridRenderer_H
#define GridRenderer_H

#include "IRendererStrategy.h"

class GridRenderer : public IRendererStrategy {
   private:
    unsigned int columnNumber;

   public:
    explicit GridRenderer(unsigned int columnNumber);
    void render(QGridLayout* layout, const std::vector<const SensorItem*>& items, std::vector<ItemButtons>& buttons) const override;
};

#endif  // !GridRenderer_H