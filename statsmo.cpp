#include "statsmo.h"
#include "ui_statsmo.h"

statsmo::statsmo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statsmo)
{
    ui->setupUi(this);
}

statsmo::~statsmo()
{
    delete ui;
}

void statsmo::statistique_P()
{
    QPieSeries *series = new QPieSeries();
        QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("SELECT * FROM ticket WHERE type='premium'") ;

        while(requete.next())
        {
            count++ ;
        }


         QSqlQuery query1;
         int count1=0 ;
         QSqlQuery requete1("SELECT * FROM ticket WHERE type='VIP'") ;

         while(requete1.next())
         {
             count1++ ;
         }


         QSqlQuery query2;
         int count2=0 ;
         QSqlQuery requete2("SELECT * FROM ticket WHERE type='standard'") ;

         while(requete2.next())
         {
             count2++ ;
         }

         series->append("premium",count);
         series->append("VIP",count1);
         series->append("standard",count2);


     QChart * chart_P =new QChart();

     chart_P-> addSeries(series);
     chart_P->setTitle("Statistique des tickets par type ");

     QChartView *chartview= new QChartView (chart_P);
     chartview->setParent(ui->charts_P);
}

void statsmo::on_hide_P_clicked()
{
   hide();
}






