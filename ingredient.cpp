#include "ingredient.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Ingredient::Ingredient()
{
    identifiant_I=0;
    nom_I="";
    quantite_I=0;
    prix_I=0;
    type_I="";
}


Ingredient::Ingredient(int identifiant_I, QString nom_I, int quantite_I, float prix_I, QString type_I)
{
    this->identifiant_I= identifiant_I;
    this->nom_I= nom_I;
    this->quantite_I= quantite_I;
    this->prix_I= prix_I;
    this->type_I= type_I;
}


int Ingredient::getidentifiant_I(){return identifiant_I;}
QString Ingredient::getnom_I(){return nom_I;}
int Ingredient::getquantite_I(){return quantite_I;}
float Ingredient::getprix_I(){return prix_I;}
QString Ingredient::gettype_I(){return type_I;}


void Ingredient::setidentifiant_I(int identifiant_I){this->identifiant_I= identifiant_I;}
void Ingredient::setnom_I(QString nom_I){this->nom_I= nom_I;}
void Ingredient::setquantite_I(int quantite_I){this->quantite_I= quantite_I;}
void Ingredient::setprix_I(float prix_I){this->prix_I= prix_I;}
void Ingredient::settype_I(QString type_I){this->type_I= type_I;}





bool Ingredient::ajouter_ingredient()
{
    QString identifiant_I_string= QString::number(identifiant_I);
    QString quantite_I_string= QString::number(quantite_I);
    QString prix_I_string= QString::number(prix_I);
    QSqlQuery query;

        query.prepare("INSERT INTO Ingredient (identifiant_I, nom_I, quantite_I, prix_I, type_I)"
                      "VALUES (:identifiant_I_string, :nom_I, :quantite_I_string, :prix_I_string, :type_I)");
        query.bindValue(0,identifiant_I_string);
        query.bindValue(1,nom_I);
        query.bindValue(2,quantite_I_string);
        query.bindValue(3,prix_I_string);
        query.bindValue(4,type_I);


        return query.exec();
}



QSqlQueryModel* Ingredient::afficher_ingredient()
{
    QSqlQueryModel* model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM Ingredient");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiant_I"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom_I"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("quantite_I"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("prix_I"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("type_I"));


    return model;
}



bool Ingredient::supprimer_ingredient(int identifiant_I)
{
    QSqlQuery query;

        query.prepare("DELETE FROM Ingredient WHERE identifiant_I= :identifiant_I");
        query.bindValue(0,identifiant_I);

        return query.exec();
}



bool Ingredient::modifier_ingredient()
{
    QString identifiant_I_string= QString::number(identifiant_I);
    QString quantite_I_string= QString::number(quantite_I);
    QString prix_I_string= QString::number(prix_I);
    QSqlQuery query;

    query.prepare("UPDATE Ingredient SET nom_I= :nom_I, quantite_I= :quantite_I_string, prix_I= :prix_I_string, type_I= :type_I  WHERE  identifiant_I= :identifiant_I_string");

    query.bindValue(":identifiant_I_string",identifiant_I_string);
    query.bindValue(":nom_I",nom_I);
    query.bindValue(":quantite_I_string",quantite_I_string);
    query.bindValue(":prix_I_string",prix_I_string);
    query.bindValue(":type_I",type_I);


return query.exec();
}




QSqlQueryModel * Ingredient::trier_ingredient(int state)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    if(state == 1)
    {
            model->setQuery("SELECT * FROM Ingredient ORDER BY nom_I");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant_I"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_I"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite_I"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_I"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_I"));


    }
    if(state == 2)
    {
            model->setQuery("SELECT * FROM Ingredient ORDER BY quantite_I");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant_I"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_I"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite_I"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_I"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_I"));


    }
    if(state == 3)
    {
            model->setQuery("SELECT * FROM Ingredient ORDER BY prix_I");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant_I"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_I"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite_I"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_I"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_I"));



    }
    return model;
}



QSqlQueryModel * Ingredient::chercher_ingredient(int identifiant_I_rech, QString type_I_rech, QString test_vide_I)
{

    QString identifiant_I_string= QString::number(identifiant_I_rech);

    QSqlQueryModel * model = new QSqlQueryModel();


    if(test_vide_I!="" && type_I_rech=="")
        {
        model->setQuery("SELECT * FROM Ingredient WHERE identifiant_I LIKE '"+identifiant_I_string+"' ");
        }

        else if(type_I_rech!="" && test_vide_I=="")
        {
        model->setQuery("SELECT * FROM Ingredient WHERE type_I LIKE '"+type_I_rech+"' ");
        }

        else if(test_vide_I!=""  && type_I_rech!="")
        {
        model->setQuery("SELECT * FROM Ingredient WHERE identifiant_I LIKE '"+identifiant_I_string+"' AND  type_P LIKE '"+type_I_rech+"' ");
        }


    if(test_vide_I=="" && type_I_rech=="")
        {
        model->setQuery("SELECT * FROM Ingredient ");
        }


    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiant_I"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom_I"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("quantite_I"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("prix_I"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("type_I"));


    return model;

}




QString Ingredient:: tabview1(int id_I)
{
    QSqlQuery query;
    QString a;
    QString b;
    QString c;
    QString d;


    QString identifiant_I_string= QString::number(id_I);

    query.exec("SELECT * FROM  Ingredient WHERE identifiant_I ='"+identifiant_I_string+"'");
    query.bindValue(":identifiant_I_string",identifiant_I_string);

    while(query.next())
    {
        query.value(0).toString();
        a=query.value(1).toString();
        b=query.value(2).toString();
        c=query.value(3).toString();
        d=query.value(4).toString();



    }

    return a;

}

QString Ingredient:: tabview2(int id_I)
{
    QSqlQuery query;
    QString a;
    QString b;
    QString c;
    QString d;


    QString identifiant_I_string= QString::number(id_I);

    query.exec("SELECT * FROM  Ingredient WHERE identifiant_I ='"+identifiant_I_string+"'");
    query.bindValue(":identifiant_I_string",identifiant_I_string);

    while(query.next())
    {
        query.value(0).toString();
        a=query.value(1).toString();
        b=query.value(2).toString();
        c=query.value(3).toString();
        d=query.value(4).toString();



    }

    return b;

}

QString Ingredient:: tabview3(int id_I)
{
    QSqlQuery query;
    QString a;
    QString b;
    QString c;
    QString d;


    QString identifiant_I_string= QString::number(id_I);

    query.exec("SELECT * FROM  Ingredient WHERE identifiant_I ='"+identifiant_I_string+"'");
    query.bindValue(":identifiant_I_string",identifiant_I_string);

    while(query.next())
    {
        query.value(0).toString();
        a=query.value(1).toString();
        b=query.value(2).toString();
        c=query.value(3).toString();
        d=query.value(4).toString();



    }

    return c;

}

QString Ingredient:: tabview4(int id_I)
{
    QSqlQuery query;
    QString a;
    QString b;
    QString c;
    QString d;


    QString identifiant_I_string= QString::number(id_I);

    query.exec("SELECT * FROM  Ingredient WHERE identifiant_I ='"+identifiant_I_string+"'");
    query.bindValue(":identifiant_I_string",identifiant_I_string);

    while(query.next())
    {
        query.value(0).toString();
        a=query.value(1).toString();
        b=query.value(2).toString();
        c=query.value(3).toString();
        d=query.value(4).toString();



    }

    return d;

}



bool Ingredient::verifierCin_aj(int identifiant_I)
 {
    QSqlQuery  query;
     bool test=true;

       QString identifiant_I_string=QString::number(identifiant_I);

         query.prepare("SELECT * FROM Ingredient WHERE identifiant_I=:identifiant_I");
          query.bindValue(":identifiant_I",identifiant_I_string);

     if(query.exec()&&query.next())
     {
         test=false;
          return test;
     }
     return test;
 }
