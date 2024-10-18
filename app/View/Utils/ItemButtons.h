#ifndef ItemButtons_H
#define ItemButtons_H

#include <QPushButton>

#include "../CustomWidgets/Boxes/AbstractSensorBox.h"

struct ItemButtons {
    const AbstractSensorBox* box;
    const QPushButton* editBtn;
    const QPushButton* deleteBtn;
};

#endif  // !ItemButtons_H