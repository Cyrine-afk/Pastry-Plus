#include "client.h"
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <vector>

//test
client::client()
{


}

client::client(int cin1,QString nom1,QString prenom1,int tel1,QString email1,QString adresse1,QString diabetique1,int age1,int point1)
{
    cin=cin1;
    tel=tel1;
    nom=nom1;
    prenom=prenom1;
    age=age1;
    email=email1;
    adresse=adresse1;
    diabitique=diabetique1;
    point=point1;
}



bool client::ajouter_client()
{
QSqlQuery query;

QString cin1 = QString::number(cin);
QString age1 = QString::number(age);
QString tel1 = QString::number(tel);
QString point1 = QString::number(point);


query.prepare("insert into CLIENTS(cin,nom,prenom,tel,email,adresse_locale,diabetique,age,point) values(:cin1,:nom,:prenom,:tel1,:email,:adresse,:diabitique,:age1,:point1)");
query.bindValue(":cin1",cin1);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":tel1",tel1);
query.bindValue(":email",email);
query.bindValue(":adresse",adresse);
query.bindValue(":diabitique",diabitique);
query.bindValue(":age1",age1);
query.bindValue(":point1",point1);






return query.exec();

}

QSqlQueryModel * client::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();







      model->setQuery("select * from clients");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adresse_locale"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("diabetique"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("age"));
    return model;

}

QSqlQueryModel * client::chercher(int d,QString nom3,QString mail3)
{
    QSqlQueryModel * model = new QSqlQueryModel();
       QString ch,chx;
       ch[0]=nom3[0];
       chx[0]=mail3[0];


       if(nom3=="" && mail3=="")
       {

       if(d==0)
       {
       model->setQuery("select * from clients");
       }

       if(d==1)
       {
       model->setQuery("select * from clients where diabetique='oui'");
       }

       if(d==2)
       {
       model->setQuery("select * from clients where diabetique='non'");
       }

       if(d==0)
       {
       model->setQuery("select * from clients");
       }

       }



       if(nom3!=""&& d==0  && mail3=="")
       {
       model->setQuery("select * from clients where nom like '%"+nom3+"%' and nom like '"+ch+"%' ");
       }
       else if(nom3!=""&& d==1  && mail3=="")
       {
          model->setQuery("select * from clients where nom like '%"+nom3+"%' and diabetique='oui' and nom like '"+ch+"%' ");
       }

       else if(nom3!=""&& d==2  && mail3=="")
       {
          model->setQuery("select * from clients where nom like '%"+nom3+"%' and diabetique='non' and nom like '"+ch+"%' ");
       }



       if(mail3!=""&& d==0 && nom3=="")
       {
       model->setQuery("select * from clients where email like '%"+mail3+"%' and email like '"+chx+"%'");
       }
       else if(mail3!=""&& d==1 && nom3=="" )
       {
          model->setQuery("select * from clients where email like '%"+mail3+"%' and email like '"+chx+"%'  and diabetique='oui' ");
       }

       else if(mail3!=""&& d==2  && nom3=="")
       {
          model->setQuery("select * from clients where email like '%"+mail3+"%' and email like '"+chx+"%'  and diabetique='non' ");
       }



       if(nom3!="" && d==0  && mail3!="")
       {
       model->setQuery("select * from clients where nom like '%"+nom3+"%' and nom like '"+ch+"%' and  email like '%"+mail3+"%' and email like '"+chx+"%' ");
       }
       else if(nom3!=""&& d==1 && mail3!="" )
       {
          model->setQuery("select * from clients where nom like '%"+nom3+"%' and nom like '"+ch+"%' and diabetique='oui'  and  email like '%"+mail3+"%' and email like '"+chx+"%' ");
       }

       else if(nom3!=""&& d==2  && mail3!="")
       {
          model->setQuery("select * from clients where nom like '%"+nom3+"%' and nom like '"+ch+"%' and diabetique='non' and  email like '%"+mail3+"%' and email like '"+chx+"%' ");
       }


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adresse_locale"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("diabetique"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("age"));
    return model;

}

QSqlQueryModel * client::trier(int t,QString nom3,QString mail3,int d)
{

    QSqlQueryModel * model = new QSqlQueryModel();



    if(nom3=="" )
    {


    if(t==0)
    {
    model->setQuery("select * from clients");
    }

    if(t==1)
    {
    model->setQuery("select * from clients order by cin");
    }

    if(t==2)
    {
    model->setQuery("select * from clients order by cin desc");
    }




    if(d==1)
    {
    model->setQuery("select * from clients order by age");
    }

    if(d==2)
    {
    model->setQuery("select * from clients order by age desc");
    }



    }



    if(nom3!=""&& t==0)
    {
        model->setQuery("select * from clients where nom like '"+nom3+"' ");
    }


    else if(nom3!=""&& t==1 && d==0)
    {
       model->setQuery("select * from clients where nom like '"+nom3+"' order by cin ");
    }

    else if(nom3!=""&& t==2 && d==0)
    {
       model->setQuery("select * from clients where nom like '"+nom3+"' order by cin desc ");
    }





    else if(nom3!=""&& d==1 && t==0)
    {
       model->setQuery("select * from clients where nom like '"+nom3+"' order by age ");
    }

    else if(nom3!=""&& d==2 && t==0)
    {
       model->setQuery("select * from clients where nom like '"+nom3+"' order by age desc ");
    }





    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adresse_locale"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("diabetique"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("age"));
    return model;

}

  bool client::modifier_client()
  {

      QSqlQuery query;
      QString cin1 = QString::number(cin);
      QString age1 = QString::number(age);
      QString tel1 = QString::number(tel);

      query.prepare("update CLIENTS set nom=:nom,prenom=:prenom,tel=:tel1,email=:email,adresse_locale=:adresse,diabetique=:diabitique,age=:age1 where cin=:cin1");
      query.bindValue(":cin1",cin1);
      query.bindValue(":nom",nom);
      query.bindValue(":prenom",prenom);
      query.bindValue(":tel1",tel1);
      query.bindValue(":email",email);
      query.bindValue(":adresse",adresse);
      query.bindValue(":diabitique",diabitique);
      query.bindValue(":age1",age1);

      return query.exec();


  }


  bool client::supp_client(int cin)
  {

      QSqlQuery query;
      QString cin1 = QString::number(cin);
      query.prepare("Delete from CLIENTS  where cin =:cin1");
      query.bindValue(":cin1",cin1);
      return query.exec();

  }


  QSqlQueryModel * client::combobox()
  {
      QSqlQueryModel * model = new QSqlQueryModel();
      //QString acc_ = QString::number(account);
      //QString perm=  QString::number(permissions);

      model->setQuery("select cin from clients");


      return model;
  }





  QString client::clicker1(int cin2)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  QString f;
  QString g;


  QSqlQuery query;
   QString cin3 = QString::number(cin2);
   query.exec("select * from CLIENTS  where cin = '"+cin3+"' ");
   query.bindValue(":cin3",cin3);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toString();
           g=query.value(7).toString();

  }


  return a;

  }





  QString client::clicker2(int cin2)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  QString f;
  QString g;


  QSqlQuery query;
   QString cin3 = QString::number(cin2);
   query.exec("select * from CLIENTS  where cin = '"+cin3+"' ");
   query.bindValue(":cin3",cin3);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toString();
           g=query.value(7).toString();

  }








  return b;





  }

  QString client::clicker3(int cin2)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  QString f;
  QString g;


  QSqlQuery query;
   QString cin3 = QString::number(cin2);
   query.exec("select * from CLIENTS  where cin = '"+cin3+"' ");
   query.bindValue(":cin3",cin3);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toString();
           g=query.value(7).toString();

  }







  return c;





  }

  QString client::clicker4(int cin2)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  QString f;
  QString g;


  QSqlQuery query;
   QString cin3 = QString::number(cin2);
   query.exec("select * from CLIENTS  where cin = '"+cin3+"' ");
   query.bindValue(":cin3",cin3);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toString();
           g=query.value(7).toString();

  }








  return d;





  }


  QString client::clicker5(int cin2)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  QString f;
  QString g;


  QSqlQuery query;
   QString cin3 = QString::number(cin2);
   query.exec("select * from CLIENTS  where cin = '"+cin3+"' ");
   query.bindValue(":cin3",cin3);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toString();
           g=query.value(7).toString();

  }




  return e;




  }



  QString client::clicker6(int cin2)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  QString f;
  QString g;


  QSqlQuery query;
   QString cin3 = QString::number(cin2);
   query.exec("select * from CLIENTS  where cin = '"+cin3+"' ");
   query.bindValue(":cin3",cin3);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toString();
           g=query.value(7).toString();

  }


  return f;





  }




  QString client::clicker7(int cin2)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  QString f;
  QString g;


  QSqlQuery query;
   QString cin3 = QString::number(cin2);
   query.exec("select * from CLIENTS  where cin = '"+cin3+"' ");
   query.bindValue(":cin3",cin3);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toString();
           g=query.value(7).toString();

  }




  return g;


  }


  int client::clicker8(int cin2)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  QString f;
  QString g;
  int h;


  QSqlQuery query;
   QString cin3 = QString::number(cin2);
   query.exec("select * from CLIENTS  where cin = '"+cin3+"' ");
   query.bindValue(":cin3",cin3);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toString();
           g=query.value(7).toString();
           h=query.value(8).toInt();

  }




  return h;


  }



  int client::clicker9(QString cin2)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  QString f;
  QString g;
  int h;


  QSqlQuery query;

   query.exec("select * from CLIENTS  where cin = '"+cin2+"' ");
   query.bindValue(":cin2",cin2);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toString();
           g=query.value(7).toString();
           h=query.value(8).toInt();

  }




  return h;


  }


  bool client::modifier_client2(QString cin2,int point2)
  {

      QSqlQuery query;
      QString point3 = QString::number(point2);


      query.prepare("update CLIENTS set  point=:point3 where cin=:cin2");
      query.bindValue(":cin2",cin2);
      query.bindValue(":point3",point3);


      return query.exec();

  }




  int client::clicker10(QString cin3)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  int f;
  int g;


  QSqlQuery query;

   query.exec("select * from CLIENTS  where cin = '"+cin3+"' ");
   query.bindValue(":cin3",cin3);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toInt();
           g=query.value(7).toInt();

  }


  return g;





  }




  QString client::clicker11(QString cin3)
  {

  QString a;
  QString b;
  QString c;
  QString d;
  QString e;
  QString f;
  QString g;


  QSqlQuery query;

   query.exec("select * from CLIENTS  where cin = '"+cin3+"' ");
   query.bindValue(":cin3",cin3);

  while(query.next())
  {
      query.value(0).toString();
      a=query.value(1).toString();
       b= query.value(2).toString();
        c=query.value(3).toString();
        d= query.value(4).toString();
         e= query.value(5).toString();
          f= query.value(6).toString();
           g=query.value(7).toString();

  }




  return f;


  }
