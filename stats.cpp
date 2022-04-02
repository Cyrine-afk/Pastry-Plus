#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
}


Stats::~Stats()
{
    delete ui;
}

void Stats::stats_d()
{
    QPieSeries *series = new QPieSeries();
        QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("SELECT * FROM CLIENTS WHERE diabetique='oui'") ;

        while(requete.next())
        {
            count++ ;
        }


         QSqlQuery query1;
         int count1=0 ;
         QSqlQuery requete1("SELECT * FROM CLIENTS WHERE diabetique='non'") ;

         while(requete1.next())
         {
             count1++ ;
         }


      /*   QSqlQuery query2;
         int count2=0 ;
         QSqlQuery requete2("SELECT * FROM Produit WHERE type_P='salee'") ;

         while(requete2.next())
         {
             count2++ ;
         }*/

         series->append("diabetique",count);
         series->append("non diabetique",count1);
         //series->append("Salee",count2);


     QChart * chart_P =new QChart();

     chart_P-> addSeries(series);
     chart_P->setTitle("Statistique des clients par diabetique ");

     QChartView *chartview= new QChartView (chart_P);
     chartview->setParent(ui->horizontalFrame);
}

