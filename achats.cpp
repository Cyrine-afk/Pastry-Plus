#include "achats.h"
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <vector>
#include <QDate>
achat::achat()
{

}

achat::achat( QString conf1,QDate date1,int id_a1,int id_e1 ,QString nom_c1,QString prenom_c1,QString produit1,int quantite1)
{
     id_a=id_a1;
     id_e=id_e1;
     nom_c=nom_c1;
     prenom_c=prenom_c1;
     date=date1;
     produit=produit1;
     quantite=quantite1;
     conf=conf1;

}

 bool achat::ajouter_achat()
 {
     QSqlQuery query;

     QString id_a1 = QString::number(id_a);
     QString id_e1 = QString::number(id_e);
     QString quantite1 = QString::number(quantite);




     query.prepare("insert into ACHATS_CLIENTS(id_a,id_e,nom_c,prenom_c,date_a,produit,quantite,confirmation) values(:id_a1,:id_e1,:nom_c,:prenom_c,:date,:produit,:quantite1,:conf)");

     query.bindValue(0,id_a1);
     query.bindValue(1,id_e1);
     query.bindValue(2,nom_c);
     query.bindValue(3,prenom_c);
     query.bindValue(4,date);
     query.bindValue(5,produit);
     query.bindValue(6,quantite1);
     query.bindValue(7,conf);







     return query.exec();


 }

 bool achat::modif_achat()
 {

     QSqlQuery query;

     QString id_a1 = QString::number(id_a);
     QString id_e1 = QString::number(id_e);
     QString quantite1 = QString::number(quantite);



     query.prepare("update ACHATS_CLIENTS set id_e=:id_e1,nom_c=:nom_c,prenom_c=:prenom_c,date_a=:date,produit=:produit,quantite=:quantite1,confirmation=:conf where id_a=:id_a1");

     query.bindValue(":id_a1",id_a1);
     query.bindValue(":id_e1",id_e1);
     query.bindValue(":nom_c",nom_c);
     query.bindValue(":prenom_c",prenom_c);
     query.bindValue(":date",date);
     query.bindValue(":produit",produit);
     query.bindValue(":quantite1",quantite1);
     query.bindValue(":conf",conf);



     return query.exec();
 }


 bool achat::supp_achat(int id_a)
 {

     QSqlQuery query;
     QString id_a2 = QString::number(id_a);
     query.prepare("Delete from ACHATS_CLIENTS  where id_a =:id_a2");
     query.bindValue(":id_a2",id_a2);
     return query.exec();

 }



QSqlQueryModel * achat::afficher2()
 {
     QSqlQueryModel * model = new QSqlQueryModel();




       model->setQuery("select * from ACHATS_CLIENTS");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_a"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_e"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_c"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("prenom_c"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_a"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("produit"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("quantite"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("confirmation"));
     return model;

 }


  QSqlQueryModel * achat::cherchera(int y,int z, QString conf2,QDate date2,int id_e2 )
  {



 QSqlQueryModel * model = new QSqlQueryModel();


  QString id_eq = QString::number(id_e2);


  if(z==2)
  {
        if(y==1)
      model->setQuery("select * from ACHATS_CLIENTS where  confirmation ='oui' ");

        if(y==2)
      model->setQuery("select * from ACHATS_CLIENTS where  confirmation ='non' ");

        if(y==0)
       model->setQuery("select * from ACHATS_CLIENTS");
  }

     if(z==1)
       model->setQuery("select * from ACHATS_CLIENTS where  id_e  like '"+id_eq+"' ");



        /*if( y==0 && z==0)
      model->setQuery("select * from ACHATS_CLIENTS where id_e=id_e2 ");

        if( y==1 && z==0)
           model->setQuery("select * from ACHATS_CLIENTS where confirmation like '"+conf+"' ");

        if( y==0 && z==1)
           model->setQuery("select * from ACHATS_CLIENTS where date_a=date2 ");

        if( y==1 && z==0)
        model->setQuery("select * from ACHATS_CLIENTS where id_e=id_e2  and date_a=date2");

        if( y==0 && z==1)
            model->setQuery("select * from ACHATS_CLIENTS where id_e=id_e2 and confirmation  like '"+conf+"'");

        if( y==1 && z==1)
            model->setQuery("select * from ACHATS_CLIENTS where confirmation like '"+conf+"' and date_a=date2");

        if( y==1 && z==1)
      model->setQuery("select * from ACHATS_CLIENTS");*/



      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_a"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_e"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_c"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("prenom_c"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_a"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("produit"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("quantite"));
      model->setHeaderData(7,Qt::Horizontal,QObject::tr("confirmation"));

      return model;


  }

  QSqlQueryModel * achat::triera(int t,int a)
  {

       QSqlQueryModel * model = new QSqlQueryModel();

      if(t==0)
      {
      model->setQuery("select * from ACHATS_CLIENTS");
      }

      if(t==1)
      {
      model->setQuery("select * from ACHATS_CLIENTS order by quantite");
      }

      if(t==2)
      {
      model->setQuery("select * from ACHATS_CLIENTS order by quantite desc");
      }





      if(a==1)
      {
      model->setQuery("select * from ACHATS_CLIENTS order by date_a");
      }

      if(a==2)
      {
      model->setQuery("select * from ACHATS_CLIENTS order by date_a desc");
      }


      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_a"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_e"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_c"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("prenom_c"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_a"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("produit"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("quantite"));
      model->setHeaderData(7,Qt::Horizontal,QObject::tr("confirmation"));

      return model;

  }



 QSqlQueryModel * achat::combobox2()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     //QString acc_ = QString::number(account);
     //QString perm=  QString::number(permissions);

     model->setQuery("select id_a from ACHATS_CLIENTS");


     return model;
 }




 QSqlQueryModel * achat::combobox3()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     //QString acc_ = QString::number(account);
     //QString perm=  QString::number(permissions);

     model->setQuery("select id_e from ACHATS_CLIENTS");


     return model;
 }


 QDate achat::clicker7(int cin2)
 {

 QString a;
 QString b;
 QString c;
 QDate d;
 QString e;
 QString f;
 QString g;


 QSqlQuery query;
  QString cin3 = QString::number(cin2);
  query.exec("select * from ACHATS_CLIENTS  where id_a = '"+cin3+"' ");
  query.bindValue(":cin3",cin3);

 while(query.next())
 {
     query.value(0).toString();
     a=query.value(1).toString();
      b= query.value(2).toString();
       c=query.value(3).toString();
       d= query.value(4).toDate();
        e= query.value(5).toString();
         f= query.value(6).toString();
          g=query.value(7).toString();

 }




 return d;


 }



 QString achat::clicker6(int cin2)
 {

 QString a;
 QString b;
 QString c;
 QDate d;
 QString e;
 QString f;
 QString g;


 QSqlQuery query;
  QString cin3 = QString::number(cin2);
  query.exec("select * from ACHATS_CLIENTS  where id_a = '"+cin3+"' ");
  query.bindValue(":cin3",cin3);

 while(query.next())
 {
     query.value(0).toString();
     a=query.value(1).toString();
      b= query.value(2).toString();
       c=query.value(3).toString();
       d= query.value(4).toDate();
        e= query.value(5).toString();
         f= query.value(6).toString();
          g=query.value(7).toString();

 }





 return g ;


 }


 int achat::clicker5(int cin2)
 {

 QString a;
 QString b;
 QString c;
 QDate d;
 QString e;
 int f;
 QString g;


 QSqlQuery query;
  QString cin3 = QString::number(cin2);
  query.exec("select * from ACHATS_CLIENTS  where id_a = '"+cin3+"' ");
  query.bindValue(":cin3",cin3);

 while(query.next())
 {
     query.value(0).toString();
     a=query.value(1).toString();
      b= query.value(2).toString();
       c=query.value(3).toString();
       d= query.value(4).toDate();
        e= query.value(5).toString();
         f= query.value(6).toInt();
          g=query.value(7).toString();

 }





 return f ;


 }


 QString achat::clicker4(int cin2)
 {

 QString a;
 QString b;
 QString c;
 QDate d;
 QString e;
 QString f;
 QString g;


 QSqlQuery query;
  QString cin3 = QString::number(cin2);
  query.exec("select * from ACHATS_CLIENTS  where id_a= '"+cin3+"' ");
  query.bindValue(":cin3",cin3);

 while(query.next())
 {
     query.value(0).toString();
     a=query.value(1).toString();
      b= query.value(2).toString();
       c=query.value(3).toString();
       d= query.value(4).toDate();
        e= query.value(5).toString();
         f= query.value(6).toString();
          g=query.value(7).toString();

 }





 return e ;


 }


 QString achat::clicker3(int cin2)
 {

 QString a;
 QString b;
 QString c;
 QDate d;
 QString e;
 QString f;
 QString g;


 QSqlQuery query;
  QString cin3 = QString::number(cin2);
  query.exec("select * from ACHATS_CLIENTS  where id_a= '"+cin3+"' ");
  query.bindValue(":cin3",cin3);

 while(query.next())
 {
     query.value(0).toString();
     a=query.value(1).toString();
      b= query.value(2).toString();
       c=query.value(3).toString();
       d= query.value(4).toDate();
        e= query.value(5).toString();
         f= query.value(6).toString();
          g=query.value(7).toString();

 }





 return a ;


 }




 QString achat::clicker2(int cin2)
 {

 QString a;
 QString b;
 QString c;
 QDate d;
 QString e;
 QString f;
 QString g;


 QSqlQuery query;
  QString cin3 = QString::number(cin2);
  query.exec("select * from ACHATS_CLIENTS where id_a = '"+cin3+"' ");
  query.bindValue(":cin3",cin3);

 while(query.next())
 {
     query.value(0).toString();
     a=query.value(1).toString();
      b= query.value(2).toString();
       c=query.value(3).toString();
       d= query.value(4).toDate();
        e= query.value(5).toString();
         f= query.value(6).toString();
          g=query.value(7).toString();

 }





 return b ;


 }



 QString achat::clicker1(int cin2)
 {

 QString a;
 QString b;
 QString c;
 QDate d;
 QString e;
 QString f;
 QString g;


 QSqlQuery query;
  QString cin3 = QString::number(cin2);
  query.exec("select * from ACHATS_CLIENTS  where id_a = '"+cin3+"' ");
  query.bindValue(":cin3",cin3);

 while(query.next())
 {
     query.value(0).toString();
     a=query.value(1).toString();
      b= query.value(2).toString();
       c=query.value(3).toString();
       d= query.value(4).toDate();
        e= query.value(5).toString();
         f= query.value(6).toString();
          g=query.value(7).toString();

 }





 return c ;


 }




