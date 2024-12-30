#include "chartview.h"
#include <QChart>
#include <QString>
#include <stdexcept>

ChartView::ChartView(QWidget *parent) : QChartView(parent)
{
    series = new QPieSeries(this);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Types d'Investissements");
    chart->legend()->setAlignment(Qt::AlignBottom);
    setChart(chart);
    setRenderHint(QPainter::Antialiasing);
}

void ChartView::updateChart(const std::vector<Investment>& investments)
{
    series->clear();
    std::map<std::string, double> typeMap;

    for (const auto& inv : investments) {
        if (inv.value < 0) {
            throw std::invalid_argument("Investment value cannot be negative");
        }
        typeMap[inv.type] += inv.value;
    }

    for (const auto& type : typeMap) {
        series->append(QString::fromStdString(type.first), type.second);
    }
}
