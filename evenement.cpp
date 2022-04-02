 #include "evenement.h"


evenement::evenement()
{

}

evenement::evenement(QString s1,QString s2,QString s3,QString x,QString s4){

    id=s1;
    nom=s2;
    date_e=s3;
    produit=x;
    lieu=s4;


}


bool evenement::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO EVENEMENT VALUES (:id,:nom,:date_e,:lieu,:produit)");

    query.bindValue(":id", id);

    query.bindValue(":nom",nom);
    query.bindValue(":date_e",date_e);
     query.bindValue(":lieu",lieu);
    query.bindValue(":produit",produit);


    return    query.exec();

}

bool evenement::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE EVENEMENT SET  NOM=:nom, DATE_E=:date_e, LIEU=:lieu ,PRODUIT=:produit"
                  " where ID= :id");
    query.bindValue(":id", selected);

    query.bindValue(":nom",nom);
    query.bindValue(":date_e",date_e);
     query.bindValue(":lieu",lieu);
    query.bindValue(":produit",produit);


    return    query.exec();

}

 QSqlQueryModel * evenement::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM EVENEMENT");

     return modal;

 }

 bool evenement::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from EVENEMENT where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }
