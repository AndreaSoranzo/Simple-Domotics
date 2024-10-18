#include "BarChart.h"

#include <limits>
#include <numeric>

BarChart::BarChart(QWidget* parent) : AbstractChart(parent) {
    series = new QBarSeries();
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
}

void BarChart::AddData(const std::vector<double>& values) {
    series->clear();
    double min = std::numeric_limits<double>::max();
    double max = std::numeric_limits<double>::min();

    int dataSize = values.size();
    int offset = dataSize / 24;

    QBarSet* valueSet = new QBarSet("Data");
    for (std::vector<double>::size_type i = 0; i < 24; i++) {
        int startIndex = i * offset;
        int endIndex = std::min(startIndex + offset, dataSize);
        if (startIndex >= dataSize) {
            break;
        }

        int partSum = std::accumulate(values.begin() + startIndex, values.begin() + endIndex, 0);
        int avg = partSum / (endIndex - startIndex);

        *valueSet << avg;

        if (values[i] < min) {
            min = values[i];
        }
        if (values[i] > max) {
            max = values[i];
        }
    }
    series->append(valueSet);
    axisY->setRange(min - paddingY, max + paddingY);
}

void BarChart::Clear() {
    series->clear();
}
