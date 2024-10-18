#ifndef ListRenderer_H
#define ListRenderer_H

#include "IRendererStrategy.h"

class ListRenderer : public IRendererStrategy {
   private:
    unsigned int spacing;

   public:
    explicit ListRenderer(unsigned int spacing);
    void render(QGridLayout* layout, const std::vector<const SensorItem*>& items, std::vector<ItemButtons>& buttons) const override;
};

#endif  // !ListRenderer_H