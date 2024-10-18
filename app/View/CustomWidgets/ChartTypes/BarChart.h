#ifndef BarChart_H
#define BarChart_H

#include "AbstractChart.h"

class BarChart : public AbstractChart {
    Q_OBJECT
   private:
    QBarSeries* series;

   public:
    explicit BarChart(QWidget* parent = 0);
    void AddData(const std::vector<double>& values) override;
    void Clear() override;
};

#endif  // !BarChart_H