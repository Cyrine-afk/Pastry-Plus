#ifndef STATSR_H
#define STATSR_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

using namespace std;
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Statsr;
}

class Statsr : public QDialog
{
    Q_OBJECT

public:
    explicit Statsr(QWidget *parent = nullptr);

    void statistique_P();
    void statistique_I();

    ~Statsr();

private slots:

    void on_hide_P_clicked();

private:
    Ui::Statsr *ui;
};

#endif // STATS_H
