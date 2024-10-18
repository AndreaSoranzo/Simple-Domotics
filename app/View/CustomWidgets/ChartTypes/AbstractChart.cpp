#include "AbstractChart.h"

#include <QVBoxLayout>

AbstractChart::AbstractChart(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    axisX = new QValueAxis();
    axisX->setLabelFormat("%f");
    axisX->setRange(0, 23);
    axisX->setTitleText("Hours");

    axisY = new QValueAxis();
    axisY->setLabelFormat("%f");
    axisY->setRange(-100, 100);
    axisY->setTitleText("Values");

    chart = new QChart();
    chart->legend()->hide();
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(900);
    chart->setAnimationEasingCurve(QEasingCurve::OutCirc);

    QChartView* chartView = new QChartView(chart);
    chartView->setMinimumHeight(400);
    chartView->setFocusPolicy(Qt::NoFocus);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);
}