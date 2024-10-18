#include "LineChart.h"

#include <QPropertyAnimation>
#include <limits>

LineChart::LineChart(QWidget* parent) : AbstractChart(parent) {
    series = new QSplineSeries();
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
}

void LineChart::AddData(const std::vector<double>& values) {
    series->clear();
    double min = std::numeric_limits<double>::max();
    double max = std::numeric_limits<double>::min();
    for (std::vector<double>::size_type i = 0; i < values.size(); i++) {
        series->append(static_cast<double>(i) / values.size() * 23, values[i]);
        if (values[i] < min) {
            min = values[i];
        }
        if (values[i] > max) {
            max = values[i];
        }
    }
    axisY->setRange(min - paddingY, max + paddingY);
}

void LineChart::Clear() {
    series->clear();
}
