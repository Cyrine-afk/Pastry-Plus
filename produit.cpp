#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Produit::Produit()
{
    identifiant_P=0;
    nom_P="";
    quantite_P=0;
    prix_P=0;
    type_P="";

}


Produit::Produit(int identifiant_P, QString nom_P, int quantite_P, float prix_P, QString type_P)
{
    this->identifiant_P= identifiant_P;
    this->nom_P= nom_P;
    this->quantite_P= quantite_P;
    this->prix_P= prix_P;
    this->type_P= type_P;

}



int Produit::getidentifiant_P(){return identifiant_P;}
QString Produit::getnom_P(){return nom_P;}
int Produit::getquantite_P(){return quantite_P;}
float Produit::getprix_P(){return prix_P;}
QString Produit::gettype_P(){return type_P;}


void Produit::setidentifiant_P(int identifiant_P){this->identifiant_P= identifiant_P;}
void Produit::setnom_P(QString nom_P){this->nom_P= nom_P;}
void Produit::setquantite_P(int quantite_P){this->quantite_P= quantite_P;}
void Produit::setprix_P(float prix_P){this->prix_P= prix_P;}
void Produit::settype_P(QString type_P){this->type_P= type_P;}




bool Produit::ajouter_produit()
{
    QString identifiant_P_string= QString::number(identifiant_P);
    QString quantite_P_string= QString::number(quantite_P);
    QString prix_P_string= QString::number(prix_P);
    QSqlQuery query;

        query.prepare("INSERT INTO Produit (identifiant_P, nom_P, quantite_P, prix_P, type_P)"
                      "VALUES (:identifiant_P_string, :nom_P, :quantite_P_string, :prix_P_string, :type_P)");
        query.bindValue(0,identifiant_P_string);
        query.bindValue(1,nom_P);
        query.bindValue(2,quantite_P_string);
        query.bindValue(3,prix_P_string);
        query.bindValue(4,type_P);


        return query.exec();
}



QSqlQueryModel* Produit::afficher_produit()
{
    QSqlQueryModel* model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM Produit");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiant_P"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom_P"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("quantite_P"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("prix_P"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("type_P"));


    return model;
}



bool Produit::supprimer_produit(int identifiant_P)
{
    QSqlQuery query;

        query.prepare("DELETE FROM Produit WHERE identifiant_P= :identifiant_P");
        query.bindValue(0,identifiant_P);

        return query.exec();
}



bool Produit::modifier_produit()
{
    QString identifiant_P_string= QString::number(identifiant_P);
    QString quantite_P_string= QString::number(quantite_P);
    QString prix_P_string= QString::number(prix_P);
    QSqlQuery query;

    query.prepare("UPDATE Produit SET nom_P= :nom_P, quantite_P= :quantite_P_string, prix_P= :prix_P_string, type_P= :type_P  WHERE  identifiant_P= :identifiant_P_string");

    query.bindValue(":identifiant_P_string",identifiant_P_string);
    query.bindValue(":nom_P",nom_P);
    query.bindValue(":quantite_P_string",quantite_P_string);
    query.bindValue(":prix_P_string",prix_P_string);
    query.bindValue(":type_P",type_P);


return query.exec();
}




QSqlQueryModel * Produit::trier_produit(int state)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    if(state == 1)
    {
            model->setQuery("SELECT * FROM Produit ORDER BY nom_P");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant_P"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_P"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite_P"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_P"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_P"));


    }
    if(state == 2)
    {
            model->setQuery("SELECT * FROM Produit ORDER BY quantite_P");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant_P"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_P"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite_P"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_P"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_P"));


    }
    if(state == 3)
    {
            model->setQuery("SELECT * FROM Produit ORDER BY prix_P");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant_P"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_P"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite_P"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_P"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_P"));



    }
    return model;
}




QSqlQueryModel * Produit::chercher_produit(int identifiant_P_rech, QString type_P_rech, QString test_vide_P)
{

    QString identifiant_P_string= QString::number(identifiant_P_rech);

    QSqlQueryModel * model = new QSqlQueryModel();


    if(test_vide_P!="" &&type_P_rech=="")
        {
        model->setQuery("SELECT * FROM Produit WHERE identifiant_P LIKE '"+identifiant_P_string+"' ");
        }

        else if(type_P_rech!="" && test_vide_P=="")
        {
        model->setQuery("SELECT * FROM Produit WHERE type_P LIKE '"+type_P_rech+"' ");
        }

        else if(test_vide_P!=""  && type_P_rech!="")
        {
        model->setQuery("SELECT * FROM Produit WHERE identifiant_P LIKE '"+identifiant_P_string+"' AND  type_P LIKE '"+type_P_rech+"' ");
        }


    if(test_vide_P=="" &&type_P_rech=="")
        {
        model->setQuery("SELECT * FROM Produit ");
        }


    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiant_P"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom_P"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("quantite_P"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("prix_P"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("type_P"));


    return model;

}



QString Produit:: tabview1(int id_P)
{
    QSqlQuery query;
    QString a;
    QString b;
    QString c;
    QString d;


    QString identifiant_P_string= QString::number(id_P);

    query.exec("SELECT * FROM  Produit WHERE identifiant_P ='"+identifiant_P_string+"'");
    query.bindValue(":identifiant_P_string",identifiant_P_string);

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

QString Produit:: tabview2(int id_P)
{
    QSqlQuery query;
    QString a;
    QString b;
    QString c;
    QString d;


    QString identifiant_P_string= QString::number(id_P);

    query.exec("SELECT * FROM  Produit WHERE identifiant_P ='"+identifiant_P_string+"'");
    query.bindValue(":identifiant_P_string",identifiant_P_string);

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

QString Produit:: tabview3(int id_P)
{
    QSqlQuery query;
    QString a;
    QString b;
    QString c;
    QString d;


    QString identifiant_P_string= QString::number(id_P);

    query.exec("SELECT * FROM  Produit WHERE identifiant_P ='"+identifiant_P_string+"'");
    query.bindValue(":identifiant_P_string",identifiant_P_string);

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

QString Produit:: tabview4(int id_P)
{
    QSqlQuery query;
    QString a;
    QString b;
    QString c;
    QString d;


    QString identifiant_P_string= QString::number(id_P);

    query.exec("SELECT * FROM  Produit WHERE identifiant_P ='"+identifiant_P_string+"'");
    query.bindValue(":identifiant_P_string",identifiant_P_string);

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




bool Produit::verifierCin_aj(int identifiant_P)
 {
    QSqlQuery  query;
     bool test=true;

       QString identifiant_P_string = QString::number(identifiant_P);

         query.prepare("SELECT * FROM Produit WHERE identifiant_P=:identifiant_P");
          query.bindValue(":identifiant_P",identifiant_P_string);

     if(query.exec()&&query.next())
     {
         test=false;
          return test;
     }
     return test;
 }
