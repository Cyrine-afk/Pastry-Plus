#include "eventicket.h"
#include "ui_eventicket.h"
#include "connexion.h"
#include "gestion_eventicket.h"
#include <QPixmap>
#include <QPainter>

eventicket::eventicket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eventicket)
{
    ui->setupUi(this);
    QPixmap pix("D:/QT/Awork/produit_ingredient_1/image/pastry_plus.png");
       /* int w_P= ui->logo_p->width();
        int h_P= ui->logo_p->height();
        ui->logo_p->setPixmap(pix.scaled(w_P,h_P, Qt::KeepAspectRatio));*/
}

eventicket::~eventicket()
{
    delete ui;
}




void eventicket::on_pushButton_clicked()
{
    //ouverture connection base de donnees
    connexion c;

    if( c.createConnection()){
     close();
     gestion_eventicket *go;
     go = new gestion_eventicket();
     go->show();
     }
}
