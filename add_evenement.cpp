#include "add_evenement.h"
#include "ui_add_evenement.h"

add_evenement::add_evenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_evenement)
{
    ui->setupUi(this);
}

add_evenement::~add_evenement()
{
    delete ui;
}
//zouuz fles
void add_evenement::on_buttonBox_accepted()
{
    accept();
}

void add_evenement::on_buttonBox_rejected()
{
    reject();
}




//get form content

QString add_evenement::produit() const{ //float

    return ui->produit->text();
}

QString add_evenement::lieu() const { //combo box

    return ui->lieu->currentText();
}


QString add_evenement::date_e() const { //time

    return ui->date_e->date().toString("dd.MM.yyyy");
}
QString add_evenement::nom() const { //line edit

    return ui->nom->text();
}

QString add_evenement::id() const { //line edit

    return ui->id->text();
}






void add_evenement::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from EVENEMENT where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){
   ui->id->setText(query.value(0).toString()); //line edit
   ui->nom->setText(query.value(1).toString()); //line edit
   ui->date_e->setDate(QDate::fromString(query.value(2).toString(),"dd.MM.yyyy"));//date_e
   ui->lieu->setCurrentText(query.value(3).toString()); // reel
   ui->produit->setText(query.value(4).toString()); //combobox

    }
}
