#include "add_ticket.h"
#include "ui_add_ticket.h"
#include "QMessageBox"

add_ticket::add_ticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_ticket)
{
    ui->setupUi(this);

}

add_ticket::~add_ticket()
{
    delete ui;
}
//zouuz fles
void add_ticket::on_buttonBox_accepted()
{
    accept();
}

void add_ticket::on_buttonBox_rejected()
{
    reject();
}

//get form content

QString add_ticket::prix() const{

    return ui->prix->text();
}

QString add_ticket::type() const {

    return ui->type->currentText();
}

QString add_ticket::date_t() const {

    return ui->date_t->date().toString("dd.MM.yyyy");
}

QString add_ticket::heure() const { //time

    return ui->heure->time().toString("hh:mm");
}

QString add_ticket::id() const { //line edit

    return ui->id->text();
   /*
    if id =('a'){}
    QMessageBox::information(nullptr,QObject::tr(""),QObject::tr("La quantité et le prix ne doivent pas etre negatives"),QMessageBox::Ok);
    else
    {
    if(test)
       {
        msgBox.setText("Ajout avec succées");
        ui->afficher_produit->setModel(P.afficher_produit());
        }
    else
        msgBox.setText("Echec d'ajout");

    msgBox.exec();
}
*/
}




//remplissage des champs du formulaire a partir de la base

void add_ticket::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from ticket where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){
   ui->id->setText(query.value(0).toString()); //line edit
   ui->heure->setTime(QTime::fromString(query.value(2).toString(),"hh:mm"));
   ui->date_t->setDate(QDate::fromString(query.value(2).toString(),"dd.MM.yyyy"));
   ui->type->setCurrentText(query.value(3).toString()); // reel
   ui->prix->setText(query.value(4).toString());

    }

}






