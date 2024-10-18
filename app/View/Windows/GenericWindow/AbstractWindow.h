#ifndef AbstractWindow_H
#define AbstractWindow_H

#include <QWidget>

class AbstractWindow : public QWidget {
   public:
    explicit AbstractWindow(QWidget* parent = 0);
    virtual ~AbstractWindow() = default;
    virtual void RevertToDefaultState() = 0;
};

#endif  // !AbstractWindow_H