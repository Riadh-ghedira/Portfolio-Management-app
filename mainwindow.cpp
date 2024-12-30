#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , chartView(new ChartView(this))
{
    ui->setupUi(this);

    // Ajoute ChartView au layout
    ui->verticalLayout->addWidget(chartView);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete chartView;
}

void MainWindow::on_addButton_clicked()
{
    QString name = QInputDialog::getText(this, "Ajouter Investissement", "Nom:");
    double value = QInputDialog::getDouble(this, "Ajouter Investissement", "Valeur:");

    QStringList types = {"crypto", "liquidité", "actifs"};
    bool ok;
    QString type = QInputDialog::getItem(this, "Ajouter Investissement", "Type:", types, 0, false, &ok);
    if (ok && !name.isEmpty()) {
        portfolio.addInvestment(name.toStdString(), value, type.toStdString());

        int row = ui->portfolioTable->rowCount();
        ui->portfolioTable->insertRow(row);
        ui->portfolioTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->portfolioTable->setItem(row, 1, new QTableWidgetItem(QString::number(value)));
        ui->portfolioTable->setItem(row, 2, new QTableWidgetItem(type));

        // Met à jour le graphique
        chartView->updateChart(portfolio.getInvestments());
    }
}
