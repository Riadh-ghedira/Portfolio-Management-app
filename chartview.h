#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QChartView>
#include <QPieSeries>
#include <vector>
#include "portfolio.h"

class ChartView : public QChartView
{
    Q_OBJECT

public:
    explicit ChartView(QWidget *parent = nullptr);
    void updateChart(const std::vector<Investment>& investments);

private:
    QPieSeries *series;
};

#endif // CHARTVIEW_H
