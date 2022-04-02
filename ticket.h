#ifndef TICKET_H
#define TICKET_H


#include <QSqlQuery>
#include <QSqlQueryModel>

class ticket
{
public:
    ticket();
    ticket(QString,QString,QString,QString,QString);


    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);


      QString id,type,prix,heure,date_t;


};

#endif // TICKET_H
