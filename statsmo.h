#ifndef STATS_H
#define STATS_H

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
class statsmo;
}

class statsmo : public QDialog
{
    Q_OBJECT

public:
    explicit statsmo(QWidget *parent = nullptr);
    void statistique_P();
    void statistique_I();

    ~statsmo();

private slots:
    void on_hide_P_clicked();

private:
    Ui::statsmo *ui;
};

#endif // STATS_H
