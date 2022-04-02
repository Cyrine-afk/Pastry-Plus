#include "fournisseur.h"
#include "connexion.h"
#include <QString>
#include <QSqlQuery>
#include <QDateTime>
#include <QDate>
#include <QSqlQueryModel>
#include <vector>
#include <QDebug>

fournisseur::fournisseur()
{

   id_f=0;
    nom_soc="";
   tel_f=0;
    email_f="";
    specialite_f="";
    adresse_add_f="";

}

fournisseur::fournisseur(int id_f, QString nom_soc, int tel_f, QString email_f, QDateTime date_add_f, QString specialite_f, QString adresse_add_f)
{

    this->id_f=id_f;
    this->nom_soc=nom_soc;
    this->tel_f=tel_f;
    this->email_f=email_f;
    this->date_add_f=date_add_f;
    this->specialite_f=specialite_f;
    this->adresse_add_f=adresse_add_f;

}



bool fournisseur::ajouter_fournisseur()
{
QSqlQuery query;


query.prepare("insert into FOURNISSEURS(id_f,nom_soc,tel_f,email_f,date_add_f,specialite_f,adresse_add_f) values(:id_f,:nom_soc,:tel_f,:email_f,:date_add_f,:specialite_f,:adresse_add_f)");

QString res = QString::number(id_f);
QString ress = QString::number(tel_f);

query.bindValue(":id_f",res);
query.bindValue(":nom_soc",nom_soc);
query.bindValue(":tel_f",ress);
query.bindValue(":email_f",email_f);
query.bindValue(":date_add_f",date_add_f);
query.bindValue(":specialite_f",specialite_f);
query.bindValue(":adresse_add_f",adresse_add_f);


return query.exec();

}

QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FOURNISSEURS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_f"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_soc"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("tel_f"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email_f"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_add_f"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("specialite_f"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("adresse_add_f"));
    return model;

}


  bool fournisseur::modifier_fournisseur()
  {
      //qDebug()<<"is working";

      QSqlQuery query;

      query.prepare("update FOURNISSEURS set nom_soc=:nom_soc,tel_f=:tel_f,email_f=:email_f,date_add_f=:date_add_f,specialite_f=:specialite_f,adresse_add_f=:adresse_add_f where id_f=:id_f");

      QString res = QString::number(id_f);
      QString ress = QString::number(tel_f);

      query.bindValue(":id_f",res);
      query.bindValue(":nom_soc",nom_soc);
      query.bindValue(":tel_f",ress);
      query.bindValue(":email_f",email_f);
      query.bindValue(":date_add_f",date_add_f);
      query.bindValue(":specialite_f",specialite_f);
      query.bindValue(":adresse_add_f",adresse_add_f);
      //qDebug()<<"is done";
      //qDebug()<<res+nom_soc+ress+date_add_f.toString();

      return query.exec();
  }


  bool fournisseur::supp_fournisseur(int id_f)
  {

      QSqlQuery query;
      QString id_f1 = QString::number(id_f);
      query.prepare("Delete from FOURNISSEURS  where id_f=:id_f1");
      query.bindValue(":id_f1",id_f1);
      return query.exec();

  }

  QSqlQueryModel *fournisseur::rechercher(QString rech)
  {
      QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("select * from FOURNISSEURS where upper(id_f) LIKE upper ('%"+rech+"%') or upper(nom_soc) LIKE upper ('%"+rech+"%') or upper(adresse_add_f) LIKE upper ('%"+rech+"%')");


      return model;

  }

  QSqlQueryModel * fournisseur::trier_id()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from FOURNISSEURS order by ID_F ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }
  QSqlQueryModel * fournisseur::trier_nom_soc()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from FOURNISSEURS order by NOM_SOC ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }

  QSqlQueryModel * fournisseur::trier_specialite()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from FOURNISSEURS order by SPECIALITE_F ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }
