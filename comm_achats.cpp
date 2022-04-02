#include "comm_achats.h"
#include "connexion.h"
#include <QString>
#include <QSqlQuery>
#include <QDateTime>
#include <QDate>
#include <QSqlQueryModel>
#include <vector>
#include <QDebug>


comm_achats::comm_achats()
{
    ID_ACHAT=0;
    NOM_SOC_ACHAT="";
    ID_ING_COM_A=0;
    QTE_ING_COM_A=0;
    PRIX_ACHAT=0;

}

comm_achats::comm_achats(int ID_ACHAT,QString NOM_SOC_ACHAT,int ID_ING_COM_A,int QTE_ING_COM_A,float PRIX_ACHAT,QDateTime DATE_AJOUT_ACHAT,QDateTime DATE_LIVR_ACHAT)
{

    this->ID_ACHAT=ID_ACHAT;
    this->NOM_SOC_ACHAT=NOM_SOC_ACHAT;
    this->ID_ING_COM_A=ID_ING_COM_A;
    this->QTE_ING_COM_A=QTE_ING_COM_A;
    this->PRIX_ACHAT= PRIX_ACHAT;
    this->DATE_AJOUT_ACHAT=DATE_AJOUT_ACHAT;
    this->DATE_LIVR_ACHAT=DATE_LIVR_ACHAT;

}



bool comm_achats::ajouter_comm_achat()
{
QSqlQuery query;


query.prepare("insert into COMM_ACHATS(ID_ACHAT, NOM_SOC_ACHAT, ID_ING_COM_A, QTE_ING_COM_A, PRIX_ACHAT, DATE_AJOUT_ACHAT, DATE_LIVR_ACHAT) values(:ID_ACHAT,:NOM_SOC_ACHAT,:ID_ING_COM_A,:QTE_ING_COM_A,:PRIX_ACHAT,:DATE_AJOUT_ACHAT,:DATE_LIVR_ACHAT)");

QString res1 = QString::number(ID_ACHAT);
QString res2 = QString::number(ID_ING_COM_A);
QString res3 = QString::number(QTE_ING_COM_A);
QString res4 = QString::number(PRIX_ACHAT);

query.bindValue(":ID_ACHAT",res1);
query.bindValue(":NOM_SOC_ACHAT",NOM_SOC_ACHAT);
query.bindValue(":ID_ING_COM_A",res2);
query.bindValue(":QTE_ING_COM_A",res3);
query.bindValue(":PRIX_ACHAT",res4);
query.bindValue(":DATE_AJOUT_ACHAT",DATE_AJOUT_ACHAT);
query.bindValue(":DATE_LIVR_ACHAT",DATE_LIVR_ACHAT);

return query.exec();

}

QSqlQueryModel * comm_achats::afficher_com_a()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM COMM_ACHATS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_ACHAT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_AJOUT_ACHAT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_LIVR_ACHAT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QTE_ING_COM_A"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("PRIX_ACHAT"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID_ING_COM_A"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOM_SOC_ACHAT"));


    return model;

}


  bool comm_achats::modifier_com_a()
  {
      //qDebug()<<"is working";

      QSqlQuery query;

      query.prepare("update COMM_ACHATS set NOM_SOC_ACHAT=:NOM_SOC_ACHAT,ID_ING_COM_A=:ID_ING_COM_A,QTE_ING_COM_A=:QTE_ING_COM_A,PRIX_ACHAT=:PRIX_ACHAT,DATE_AJOUT_ACHAT=:DATE_AJOUT_ACHAT,DATE_LIVR_ACHAT=:DATE_LIVR_ACHAT where ID_ACHAT=:ID_ACHAT");

      QString res1 = QString::number(ID_ACHAT);
      QString res2 = QString::number(ID_ING_COM_A);
      QString res3 = QString::number(QTE_ING_COM_A);
      QString res4 = QString::number(PRIX_ACHAT);

      query.bindValue(":ID_ACHAT",res1);
      query.bindValue(":NOM_SOC_ACHAT",NOM_SOC_ACHAT);
      query.bindValue(":ID_ING_COM_A",res2);
      query.bindValue(":QTE_ING_COM_A",res3);
      query.bindValue(":PRIX_ACHAT",res4);
      query.bindValue(":DATE_AJOUT_ACHAT",DATE_AJOUT_ACHAT);
      query.bindValue(":DATE_LIVR_ACHAT",DATE_LIVR_ACHAT);

      return query.exec();
  }


  bool comm_achats::supp_com_a(int ID_ACHAT)
  {

      QSqlQuery query;
      QString ID_ACHAT_1 = QString::number(ID_ACHAT);
      query.prepare("Delete from COMM_ACHATS  where ID_ACHAT=:ID_ACHAT_1");
      query.bindValue(":ID_ACHAT_1",ID_ACHAT_1);
      return query.exec();

  }

  QSqlQueryModel *comm_achats::rechercher_com_a(QString rech)
  {
      QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("select * from COMM_ACHATS where upper(ID_ACHAT) LIKE upper ('%"+rech+"%') or upper(NOM_SOC_ACHAT) LIKE upper ('%"+rech+"%') or upper(PRIX_ACHAT) LIKE upper ('%"+rech+"%')");


      return model;

  }

  QSqlQueryModel *comm_achats::trier_qte_a()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from COMM_ACHATS order by QTE_ING_COM_A ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }
  QSqlQueryModel * comm_achats::trier_nom_soc_a()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from COMM_ACHATS order by NOM_SOC_ACHAT ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }

  QSqlQueryModel * comm_achats::trier_id_ing_a()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from COMM_ACHATS order by ID_ING_COM_A ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }

  QSqlQueryModel * comm_achats::trier_prix_com_a()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from COMM_ACHATS order by PRIX_ACHAT ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }

  int comm_achats::count(QString nom)
  {
      QSqlQuery query;
      query.prepare("select * from COMM_ACHATS where NOM_SOC_ACHAT=:nom");
      query.bindValue(":nom",nom);

      query.exec();
      int total=0;
      while(query.next()){
          total++;
      }

      return total;

  }

  int comm_achats::count_date(QDate date_1,QDate date_2,QString nom)
  {
      QSqlQuery query;
      query.prepare("select * from COMM_ACHATS where DATE_LIVR_ACHAT between :date_1 AND :date_2  AND NOM_SOC_ACHAT=:nom");
      query.bindValue(":date_1",date_1);
      query.bindValue(":date_2",date_2);
      query.bindValue(":nom",nom);

      query.exec();
      int total=0;
      while(query.next()){
          total++;
      }

      return total;
  }


