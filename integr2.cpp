#include "integr2.h"
#include "ui_integr2.h"
#include <QMediaPlayer>
#include <QDate>
#include <QDateTime>
#include <QTimer>

void integr2:: music(int pp,int m,int mu)
{



   QMediaPlayer * player = new QMediaPlayer;
   player->setMedia(QUrl::fromLocalFile("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/music2.mp3"));
   player->setVolume(0);
   player->stop();



}


integr2::integr2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::integr2)
{
    ui->setupUi(this);
    music(0,0,0);

    QPixmap pix("C:/Users/ALPHA/Desktop/qt_projets/integration2/menu.jpg");
    ui->label->setPixmap(pix.scaled(1400,750,Qt::KeepAspectRatio));

   /* QPixmap pix2("C:/Users/ALPHA/Desktop/qt_projets/integration2/pastry_plus.png");
    ui->label_2->setPixmap(pix2.scaled(250,250,Qt::KeepAspectRatio));*/

    QTimer *timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
        timer->start();

        QDate date = QDate ::currentDate();
        QString datee=date.toString();

        ui->date_P->setText(datee) ;


}

integr2::~integr2()
{
    delete ui;
}


void integr2::on_pushButton_14_clicked()
{

   c = new Clients_Achats(this);
   c->show();

}

void integr2::on_pushButton_10_clicked()
{
    m = new MainWindow(this);
    m->show();

}



void integr2::on_pushButton_13_clicked()
{

    g = new gestion_eventicket(this);
    g->show();
}

void integr2::on_pushButton_12_clicked()
{
    mj =new MainWindowj(this);

    mj->show();

}

void integr2::on_pushButton_11_clicked()
{
    pr =new Produit_ingredient(this);
    pr->show();
}
