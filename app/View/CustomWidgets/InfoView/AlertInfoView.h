#ifndef AlertInfoView_H
#define AlertInfoView_H

#include <QLabel>
#include <QWidget>

#include "AbstractInfoView.h"

class AlertInfoView : public AbstractInfoView {
    Q_OBJECT
   private:
    QLabel* lastTriggerLabel;

   public:
    explicit AlertInfoView(int danger, QWidget* parent = 0);

    void UpdateLastTrigger(const QString& time);
};

#endif  // !AlertInfoView_H