#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>

// Used to create a line chart
#include <QtCharts/QLineSeries>

// Used to change names on axis
#include <QtCharts/QCategoryAxis>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "comm_achats.h"

// Define the scope for your variables and functions
QT_CHARTS_USE_NAMESPACE

/*QT_BEGIN_NAMESPACE
namespace Ui { class stats; }
QT_END_NAMESPACE*/


namespace Ui {
class statscy;
}

class statscy : public QDialog
{
    Q_OBJECT

public:
    explicit statscy(QWidget *parent = nullptr);
    ~statscy();


private:
    Ui::statscy *ui;
    comm_achats tmpcomm;
};

#endif // STATS_H
