#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
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

class fournisseur
{
public:
    fournisseur();
    fournisseur(int,QString,int,QString,QDateTime,QString,QString);
     bool ajouter_fournisseur();
     int getId(){return id_f;}
     int getTel(){return tel_f;}
     QString getNom(){return nom_soc;}
     QString getAdresse(){return adresse_add_f;}
     QString getEmail(){return email_f;}

     QSqlQueryModel * afficher();
     bool supp_fournisseur(int);
     bool modifier_fournisseur();
     QSqlQueryModel * rechercher (QString);
     QSqlQueryModel * trier_id();
     QSqlQueryModel * trier_nom_soc();
     QSqlQueryModel * trier_specialite();

private:
    int id_f;
    QString nom_soc;
    int tel_f;
    QString email_f;
    QDateTime date_add_f;
    QString specialite_f;
    QString adresse_add_f;

};

#endif // FOURNISSEUR_H
