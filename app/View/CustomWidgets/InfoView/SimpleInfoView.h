#ifndef SimpleInfoView_H
#define SimpleInfoView_H

#include <QGridLayout>
#include <QLabel>

#include "AbstractInfoView.h"

class SimpleInfoView : public AbstractInfoView {
    Q_OBJECT
   private:
    QLabel* minLabel;
    QLabel* maxLabel;
    QLabel* avgLabel;

    QGridLayout* sensorValuesLay;

   public:
    explicit SimpleInfoView(QWidget* parent = 0);

    void AddInfo(QLabel* info, int row, int column, int rowStretch = 1, int columnStretch = 1);
    void UpdateMin(const QString& value);
    void UpdateMax(const QString& value);
    void UpdateAvg(const QString& value);
};

#endif  // !SimpleInfoView_H