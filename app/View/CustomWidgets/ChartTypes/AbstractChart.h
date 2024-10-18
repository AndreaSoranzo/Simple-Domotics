#ifndef AbstractChart_H
#define AbstractChart_H

#include <QValueAxis>
#include <QWidget>
#include <QtCharts>
#include <vector>

class AbstractChart : public QWidget {
    Q_OBJECT
   private:
    QChartView* chartView;

   protected:
    QChart* chart;
    QValueAxis* axisX;
    QValueAxis* axisY;
    double paddingY = 3;

   public:
    explicit AbstractChart(QWidget* parent = 0);
    virtual void AddData(const std::vector<double>& values) = 0;
    virtual void Clear() = 0;
};

#endif  // !AbstractChart_H