#ifndef COMM_ACHATS_H
#define COMM_ACHATS_H
#include <QString>
#include <QSqlQuery>
#include <QDateTime>
#include <QSqlQueryModel>
#include <vector>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
//#include <QPrinter>
#include <QSqlTableModel>
//#include <tableprinter.h>
//#include "mainwindow.h"


class comm_achats
{
public:
    comm_achats();

    comm_achats(int,QString,int,int,float,QDateTime,QDateTime);
     bool ajouter_comm_achat();
     int getId_2(){return ID_ACHAT;}
     QString getNom_A(){return NOM_SOC_ACHAT;}
     int getId_Ing_A(){return ID_ING_COM_A;}
     int getQte_A(){return QTE_ING_COM_A;}
     float getPrix_A(){return PRIX_ACHAT;}

     QSqlQueryModel * afficher_com_a();
     bool supp_com_a(int);
     bool modifier_com_a();
     QSqlQueryModel * rechercher_com_a (QString);
     QSqlQueryModel * trier_qte_a();
     QSqlQueryModel * trier_id_ing_a();
     QSqlQueryModel * trier_nom_soc_a();
     QSqlQueryModel * trier_prix_com_a();
     int count(QString);
     int count_date(QDate,QDate,QString);

private:
    int ID_ACHAT;
    QString NOM_SOC_ACHAT;
    int ID_ING_COM_A;
    int QTE_ING_COM_A;
    float PRIX_ACHAT;
    QDateTime DATE_AJOUT_ACHAT;
    QDateTime DATE_LIVR_ACHAT;
};

#endif // COMM_ACHATS_H
