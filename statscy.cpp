#include "statscy.h"
#include "ui_statscy.h"
#include <QDebug>

statscy::statscy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statscy)
{
    ui->setupUi(this);

    QBarSet *set0=new QBarSet("Enactus");
    QBarSet *set1=new QBarSet("Warda");

    QDate date_1970(1970,01,01);
    QDate date_1980(1980,01,01);
    QDate date_1990(1990,01,01);
    QDate date_2000(2000,01,01);
    QDate date_2010(2010,01,01);
    QDate date_2020(2020,01,01);

    *set0 << tmpcomm.count_date(date_1970,date_2020,"Enactus") << tmpcomm.count_date(date_1980,date_1990,"Enactus") << tmpcomm.count_date(date_1990,date_2000,"Enactus") << tmpcomm.count_date(date_2000,date_2010,"Enactus") << tmpcomm.count_date(date_2010,date_2020,"Enactus");
    *set1 << tmpcomm.count_date(date_1970,date_1980,"Warda") << tmpcomm.count_date(date_1980,date_1990,"Warda") << tmpcomm.count_date(date_1990,date_2000,"Warda") << tmpcomm.count_date(date_2000,date_2010,"Warda") << tmpcomm.count_date(date_2010,date_2020,"Warda");

    qDebug()<< tmpcomm.count_date(date_1970,date_2020,"Enactus");
    qDebug()<< tmpcomm.count_date(date_1970,date_2020,"Warda");

    QBarSeries *series= new QBarSeries();
    series->append(set0);
    series->append(set1);


    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques selon le nom de la société");

    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;
    categories << "1970-1980" << "1980-1990" << "1990-2000" << "2000-2010" << "2010-2020";
    QBarCategoryAxis *axis= new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView= new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    //PIE

    QPieSeries *series_pie = new QPieSeries();

    series_pie->append("Enactus",tmpcomm.count("Enactus"));
    series_pie->append("Warda", tmpcomm.count("Warda"));

    QPieSlice *slice = series_pie->slices().at(1);
    slice->setExploded(true);
    slice->setLabelVisible(true);
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QChart *chart_pie = new QChart();
    chart_pie->addSeries(series_pie);
    chart_pie->setTitle("Statistiques sur le nom de la société");

    QChartView *chartview_pie = new QChartView(chart_pie);

    chartView->setParent(ui->horizontalFrame_sticks);
    chartview_pie->setParent(ui->horizontalFrame_pie);

}

statscy::~statscy()
{
    delete ui;
}
