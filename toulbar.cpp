#include "toulbar.h"
#include "ui_toulbar.h"
#include <QPixmap>


ToulBar::ToulBar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToulBar)
{
    ui->setupUi(this);
}

ToulBar::~ToulBar()
{
    delete ui;
}


void ToulBar::afficher(QString tb)
{
    if(tb == "gateau")
    {
        QPixmap pix("C:/Users/ALPHA/Desktop/qt_projets/integration2/image/sucre.jpg");
              ui->img1->setPixmap(pix.scaled(340,300,Qt::KeepAspectRatio));
               ui->text1->setText("Sucre");

               QPixmap pix2("C:/Users/ALPHA/Desktop/qt_projets/integration2/image/farine.jpg");
                     ui->img2->setPixmap(pix2.scaled(340,300,Qt::KeepAspectRatio));
                      ui->text2->setText("Farine");

                      QPixmap pix3("C:/Users/ALPHA/Desktop/qt_projets/integration2/image/oeuf.jpg");
                            ui->img3->setPixmap(pix3.scaled(340,300,Qt::KeepAspectRatio));
                             ui->text3->setText("Oeuf");
    }


    if(tb == "pate")
    {
        QPixmap pix("C:/Users/ALPHA/Desktop/qt_projets/integration2/image/buerre.jpg");
              ui->img1->setPixmap(pix.scaled(340,300,Qt::KeepAspectRatio));
               ui->text1->setText("Buerre");

               QPixmap pix2("C:/Users/ALPHA/Desktop/qt_projets/integration2/image/oeuf.jpg");
                     ui->img2->setPixmap(pix2.scaled(340,300,Qt::KeepAspectRatio));
                      ui->text2->setText("Oeuf");

                      QPixmap pix3("C:/Users/ALPHA/Desktop/qt_projets/integration2/image/semoule.jpg");
                            ui->img3->setPixmap(pix3.scaled(340,300,Qt::KeepAspectRatio));
                             ui->text3->setText("Semoule");
    }


    if(tb == "sale")
    {
        QPixmap pix("C:/Users/ALPHA/Desktop/qt_projets/integration2/image/fruitsec.jpg");
              ui->img1->setPixmap(pix.scaled(340,300,Qt::KeepAspectRatio));
               ui->text1->setText("Fruit Sec");

               QPixmap pix2("C:/Users/ALPHA/Desktop/qt_projets/integration2/image/huile.jpg");
                     ui->img2->setPixmap(pix2.scaled(340,300,Qt::KeepAspectRatio));
                      ui->text2->setText("Huile");

                      QPixmap pix3("C:/Users/ALPHA/Desktop/qt_projets/integration2/image/miel.jpg");
                            ui->img3->setPixmap(pix3.scaled(340,300,Qt::KeepAspectRatio));
                             ui->text3->setText("Miel");
    }
}




