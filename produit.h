#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Produit
{
public:
    Produit();
    Produit(int, QString, int, float, QString);

    int getidentifiant_P();
    QString getnom_P();
    int getquantite_P();
    float getprix_P();
    QString gettype_P();


    void setidentifiant_P(int);
    void setnom_P(QString);
    void setquantite_P(int);
    void setprix_P(float);
    void settype_P(QString);


    bool ajouter_produit();
    QSqlQueryModel* afficher_produit();
    bool supprimer_produit(int);
    bool modifier_produit();

    QSqlQueryModel * trier_produit(int);
    QSqlQueryModel * chercher_produit(int, QString, QString);

    QString tabview1(int);
    QString tabview2(int);
    QString tabview3(int);
    QString tabview4(int);


    bool verifierCin_aj(int identifiant_P);

private:
    int identifiant_P, quantite_P;
    float prix_P;
    QString nom_P, type_P;

};

#endif // PRODUIT_H
