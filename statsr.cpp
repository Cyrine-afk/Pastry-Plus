#include "statsr.h"
#include "ui_statsr.h"

Statsr::Statsr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statsr)
{
    ui->setupUi(this);
}

Statsr::~Statsr()
{
    delete ui;
}


void Statsr::statistique_P()
{
    QPieSeries *series = new QPieSeries();
        QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("SELECT * FROM Produit WHERE type_P='gateau'") ;

        while(requete.next())
        {
            count++ ;
        }


         QSqlQuery query1;
         int count1=0 ;
         QSqlQuery requete1("SELECT * FROM Produit WHERE type_P='patee'") ;

         while(requete1.next())
         {
             count1++ ;
         }


         QSqlQuery query2;
         int count2=0 ;
         QSqlQuery requete2("SELECT * FROM Produit WHERE type_P='salee'") ;

         while(requete2.next())
         {
             count2++ ;
         }

         series->append("Gateau",count);
         series->append("Patee",count1);
         series->append("Salee",count2);


     QChart * chart_P =new QChart();

     chart_P-> addSeries(series);
     chart_P->setTitle("Statistique des produits par type ");

     QChartView *chartview= new QChartView (chart_P);
     chartview->setParent(ui->charts_P);
}

void Statsr::on_hide_P_clicked()
{
   hide();
}




void Statsr::statistique_I()
{
    QPieSeries *series = new QPieSeries();
        QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("SELECT * FROM Ingredient WHERE type_I='beuf'") ;

        while(requete.next())
        {
            count++ ;
        }


         QSqlQuery query1;
         int count1=0 ;
         QSqlQuery requete1("SELECT * FROM Ingredient WHERE type_I='poulet'") ;

         while(requete1.next())
         {
             count1++ ;
         }


         QSqlQuery query2;
         int count2=0 ;
         QSqlQuery requete2("SELECT * FROM Ingredient WHERE type_I='vegetarian'") ;

         while(requete2.next())
         {
             count2++ ;
         }

         series->append("Beuf",count);
         series->append("Poulet",count1);
         series->append("Vegetarian",count2);


     QChart * chart_I =new QChart();

     chart_I-> addSeries(series);
     chart_I->setTitle("Statistique des ingredients par type ");

     QChartView *chartview= new QChartView (chart_I);
     chartview->setParent(ui->charts_P);
}
