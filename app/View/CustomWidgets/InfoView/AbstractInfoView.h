#ifndef AbstractInfoView_H
#define AbstractInfoView_H

#include <QWidget>

class AbstractInfoView : public QWidget { // "fake" abstract class to use dynamic cast in SensorViewer
    Q_OBJECT
   public:
    explicit AbstractInfoView(QWidget* parent = 0);
    virtual ~AbstractInfoView() = default;
};

#endif  // !AbstractInfoView_H