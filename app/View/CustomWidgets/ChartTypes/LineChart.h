#ifndef LineChart_H
#define LineChart_H

#include "AbstractChart.h"

class LineChart : public AbstractChart {
   private:
    QSplineSeries* series;

   public:
    LineChart(QWidget* parent = 0);
    void AddData(const std::vector<double>& values) override;
    void Clear() override;
};

#endif  // !LineChart_H