#include "produit_ingredient.h"
#include "ui_produit_ingredient.h"
#include "produit.h"
#include "ingredient.h"
#include "statsr.h"
#include "exportexcelobjectr.h"
#include "toulbar.h"
#include "tableprinter.h"
#include "arduino_p_i.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QIntValidator>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>
#include <QtPrintSupport/QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QSound>
#include <QMediaPlayer>
#include <QPropertyAnimation>
#include <QLabel>
#include <QDateTime>
#include <QTime>


class PrintBorder : public PagePrepare {
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

int PrintBorder::pageNumber = 0;

void PrintBorder::preparePage(QPainter *painter) { // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));
    pageNumber += 1;
}


void Produit_ingredient:: music()
{
   QMediaPlayer * player = new QMediaPlayer;

   player->setMedia(QUrl::fromLocalFile("D:/QT/Awork/produit_ingredient_1/sound/piano.mp3"));
   player->setVolume(100);
   player->play();

}


Produit_ingredient::Produit_ingredient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Produit_ingredient)
{
    ui->setupUi(this);

    int ret= A.connect_arduino();

        switch(ret)
        {
        case(0):qDebug()<<"arduino is available and connected to:"<<A.getarduino_port_name(); break;

        case(1):qDebug()<<"arduino is available but bot connected to:"<<A.getarduino_port_name(); break;

        case(-1):qDebug()<<"arduino is not available ";
                           break;
        }

        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
        ui->arduino->setText( A.read_from_arduino());


    ui->identifiant_P->setValidator(new QIntValidator(0,99999999,this));
    ui->afficher_produit->setModel(P.afficher_produit());

    ui->identifiant_I->setValidator(new QIntValidator(0,99999999,this));
    ui->afficher_ingredient->setModel(I.afficher_ingredient());


    QPixmap pix("C:/Users/ALPHA/Desktop/qt_projets/integration2/image/pastry_plus.png");
    int w_P= ui->logo_P->width();
    int h_P= ui->logo_P->height();
    ui->logo_P->setPixmap(pix.scaled(w_P,h_P, Qt::KeepAspectRatio));

    int w_I= ui->logo_I->width();
    int h_I= ui->logo_I->height();
    ui->logo_I->setPixmap(pix.scaled(w_I,h_I, Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/ALPHA/Desktop/qt_projets/integration2/bg1.jpg");
    int w= ui->bg_P->width();
    int h= ui->bg_P->height()+400;
    ui->bg_P->setPixmap(pix1.scaled(w,h, Qt::KeepAspectRatio));


    QPropertyAnimation *animation;
    animation = new QPropertyAnimation (ui ->logo_P,"geometry" );

                       animation->setDuration(50000);
                       animation->setStartValue(ui->logo_P->geometry());
                       animation->setEndValue(QRect(140,200,5,1));
                       //animation->setEndValue(QRect(0,0,5,1));
                       animation->start();



     QTimer *timer=new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
     timer->start();

     QDate date = QDate ::currentDate();
     QString datee=date.toString();

     ui->date_P->setText(datee) ;
     ui->date_I->setText(datee) ;

    //music();
}

Produit_ingredient::~Produit_ingredient()
{
    delete ui;
}


void change(QLabel * label, const QString & text, int ms_keep = 7000, int ms_after = 0)
{
    //QString originaltext = label->text();
    QTimer::singleShot(ms_after, [=](){
        label->setText(text);
        QTimer::singleShot(ms_keep, [=](){
            label->setText("");
        });
    });
}


//************************* Produit ********************************


void Produit_ingredient::on_ajouter_produit_clicked()
{
    int identifiant_P= ui->identifiant_P->text().toInt();
    QString nom_P= ui->nom_P->text();
    int quantite_P= ui->quantite_P->text().toInt();
    float prix_P= ui->prix_P->text().toInt();
    QString type_P= ui->type_P->currentText();


    Produit P(identifiant_P, nom_P, quantite_P, prix_P, type_P);

    if(P.verifierCin_aj(P.getidentifiant_P())==false)
       {
           change(ui->msg_P,"<font color='red'> Cet identifiant est déjà utilisé</font>",7000, 0);
       }

   if( P.verifierCin_aj(P.getidentifiant_P())==true)
   {
     bool test= P.ajouter_produit();
       QMessageBox msgBox;

    if(quantite_P <= 0 || prix_P<=0)
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
}
}


void Produit_ingredient::on_supprimer_produit_clicked()
{
    Produit P1;
    P1.setidentifiant_P(ui->identifiant_P_supp->text().toInt());

    bool test=P1.supprimer_produit(P1.getidentifiant_P());
    QMessageBox msgBox;
    if(test)
       {
        msgBox.setText("Suppression avec succées");
        ui->afficher_produit->setModel(P.afficher_produit());
        }
    else
        msgBox.setText("Echec de suppression");

    msgBox.exec();
}

void Produit_ingredient::on_modifier_produit_clicked()
{
    int identifiant_P= ui->identifiant_P_modif->text().toInt();
    QString nom_P= ui->nom_P_modif->text();
    int quantite_P= ui->quantite_P_modif->text().toInt();
    float prix_P= ui->prix_P_modif->text().toInt();
    QString type_P= ui->type_P_modif->text();


    Produit P(identifiant_P, nom_P, quantite_P, prix_P, type_P);

    bool test=P.modifier_produit();
    QMessageBox msgBox;
    if(quantite_P <= 0 || prix_P<=0)
    QMessageBox::information(nullptr,QObject::tr(""),QObject::tr("La quantité et le prix ne doivent pas etre negatives"),QMessageBox::Ok);
    else
    {
    if(test)
       {
        msgBox.setText("Modifier avec succées");
        ui->afficher_produit->setModel(P.afficher_produit());
        }
    else
        msgBox.setText("Echec de modification");

    msgBox.exec();
}
}



void Produit_ingredient::on_afficher_produit_clicked(const QModelIndex &index)
{
    QString prod1;
    QString prod2;
    QString prod3;
    QString prod4;



    if(index.isValid())
    {

        QString ligne=index.data(index.column()).toString();


        ui->identifiant_P_modif->setText(ligne);
        ui->identifiant_P_supp->setText(ligne);

        int id_P= ui->identifiant_P_modif->text().toInt();


    prod1= P.tabview1(id_P); //nom
    prod2= P.tabview2(id_P); //quntite
    prod3= P.tabview3(id_P);//prix
    prod4= P.tabview4(id_P);//type




    ui->nom_P_modif->setText(prod1);
    ui->quantite_P_modif->setText(prod2);
    ui->prix_P_modif->setText(prod3);
    ui->type_P_modif->setText(prod4);



    }

}

//************************* INGREDIENT ********************************



void Produit_ingredient::on_ajouter_ingredient_clicked()
{
    int identifiant_I= ui->identifiant_I->text().toInt();
    QString nom_I= ui->nom_I->text();
    int quantite_I= ui->quantite_I->text().toInt();
    float prix_I= ui->prix_I->text().toInt();
    QString type_I= ui->type_I->currentText();


    Ingredient I(identifiant_I, nom_I, quantite_I, prix_I, type_I);


    if(I.verifierCin_aj(I.getidentifiant_I())==false)
       {
           change(ui->msg_I,"<font color='red'> Cet identifiant est déjà utilisé</font>",7000, 0);
       }

    if( I.verifierCin_aj(I.getidentifiant_I())==true)
    {
    bool test= I.ajouter_ingredient();
    QMessageBox msgBox;

    if(quantite_I <= 0 || prix_I<=0)
    QMessageBox::information(nullptr,QObject::tr(""),QObject::tr("La quantité et le prix ne doivent pas etre negatives"),QMessageBox::Ok);
    else
    {
    if(test)
       {
        msgBox.setText("Ajout avec succées");
        ui->afficher_ingredient->setModel(I.afficher_ingredient());
        }
    else
        msgBox.setText("Echec d'ajout");

    msgBox.exec();
}
}
}

void Produit_ingredient::on_supprimer_ingredient_clicked()
{
    Ingredient I1;
    I1.setidentifiant_I(ui->identifiant_I_supp->text().toInt());

    bool test=I1.supprimer_ingredient(I1.getidentifiant_I());
    QMessageBox msgBox;
    if(test)
       {
        msgBox.setText("Suppression avec succées");
        ui->afficher_ingredient->setModel(I.afficher_ingredient());
        }
    else
        msgBox.setText("Echec de suppression");

    msgBox.exec();
}



void Produit_ingredient::on_modifier_ingredient_clicked()
{
    int identifiant_I= ui->identifiant_I_modif->text().toInt();
    QString nom_I= ui->nom_I_modif->text();
    int quantite_I= ui->quantite_I_modif->text().toInt();
    float prix_I= ui->prix_I_modif->text().toInt();
    QString type_I= ui->type_I_modif->text();


    Ingredient I(identifiant_I, nom_I, quantite_I, prix_I, type_I);

    bool test=I.modifier_ingredient();
    QMessageBox msgBox;
    if(quantite_I <= 0 || prix_I<=0)
    QMessageBox::information(nullptr,QObject::tr(""),QObject::tr("La quantité et le prix ne doivent pas etre negatives"),QMessageBox::Ok);
    else
    {
    if(test)
       {
        msgBox.setText("Modifier avec succées");
        ui->afficher_ingredient->setModel(I.afficher_ingredient());
        }
    else
        msgBox.setText("Echec de modification");

    msgBox.exec();
}
}




void Produit_ingredient::on_afficher_ingredient_clicked(const QModelIndex &index)
{
    QString ingr1;
    QString ingr2;
    QString ingr3;
    QString ingr4;



    if(index.isValid())
    {

        QString ligne=index.data(index.column()).toString();


        ui->identifiant_I_modif->setText(ligne);
        ui->identifiant_I_supp->setText(ligne);

        int id_I= ui->identifiant_I_modif->text().toInt();


    ingr1= I.tabview1(id_I); //nom
    ingr2= I.tabview2(id_I); //quntite
    ingr3= I.tabview3(id_I);//prix
    ingr4= I.tabview4(id_I);//type




    ui->nom_I_modif->setText(ingr1);
    ui->quantite_I_modif->setText(ingr2);
    ui->prix_I_modif->setText(ingr3);
    ui->type_I_modif->setText(ingr4);


    }
}


//*************** METIER ******************************


void Produit_ingredient::on_trier_produit_clicked()
{
    if (ui->nom_P_trie->isChecked())
    {
         ui->afficher_produit->setModel(P.trier_produit(1));
    }
    if (ui->quantite_P_trie->isChecked())
    {
         ui->afficher_produit->setModel(P.trier_produit(2));
    }
    if (ui->prix_P_trie->isChecked())
    {
         ui->afficher_produit->setModel(P.trier_produit(3));
    }


}



void Produit_ingredient::on_trier_ingredient_clicked()
{
    if (ui->nom_I_trie->isChecked())
    {
         ui->afficher_ingredient->setModel(I.trier_ingredient(1));
    }
    if (ui->quantite_I_trie->isChecked())
    {
         ui->afficher_ingredient->setModel(I.trier_ingredient(2));
    }
    if (ui->prix_I_trie->isChecked())
    {
         ui->afficher_ingredient->setModel(I.trier_ingredient(3));
    }
}






/*void Produit_ingredient::on_exporter_P_clicked()
{
    QString identifiant_P_string= ui->identifiant_P->text();
    QString nom_P= ui->nom_P->text();
    QString quantite_P_string= ui->quantite_P->text();
    QString prix_P_string= ui->prix_P->text();
    QString type_P= ui->type_P->text();




        QPixmap logo;
        logo.load("D:/QT/Awork/produit_ingredient_1/pastry_plus.png");
        logo.scaled(logo.width()*4, logo.height()*4);

        QString pdf_name= "Produit"+identifiant_P_string+".pdf";
        QPdfWriter pdf(pdf_name);
        QPainter painter(&pdf);
        painter.drawPixmap(3000,0,logo.width()*4,logo.height()*4,logo);


        painter.setPen(Qt::blue);
        painter.drawText(100,2300,"Identifiant du produit : ");
        painter.setPen(Qt::black);
        painter.drawText(2000,2300,identifiant_P_string);
        painter.setPen(Qt::blue);
        painter.drawText(100,2600,"Nom du produit : ");
        painter.setPen(Qt::black);
        painter.drawText(2000,2600,nom_P);
        painter.setPen(Qt::blue);
        painter.drawText(100,2900,"Quantité du produit : ");
        painter.setPen(Qt::black);
        painter.drawText(2000,2900,quantite_P_string);
        painter.setPen(Qt::blue);
        painter.drawText(100,3200,"Prix du produit : ");
        painter.setPen(Qt::black);
        painter.drawText(2000,3200,prix_P_string);
        painter.setPen(Qt::blue);
        painter.drawText(100,3500,"Type du produit : ");
        painter.setPen(Qt::black);
        painter.drawText(2000,3500,type_P);
        painter.setPen(Qt::blue);



        painter.end();
        QMessageBox::information(nullptr, QObject::tr("pdf  "),
                    QObject::tr("Exportation PDF terminer"), QMessageBox::Accepted);


}*/



/*void Produit_ingredient::on_exporter_I_clicked()
{
    QString identifiant_I_string= ui->identifiant_I->text();
    QString nom_I= ui->nom_I->text();
    QString quantite_I_string= ui->quantite_I->text();
    QString prix_I_string= ui->prix_I->text();
    QString type_I= ui->type_I->text();



        QPixmap logo;
        logo.load("D:/QT/Awork/produit_ingredient_1/pastry_plus.png");
        logo.scaled(logo.width()*4, logo.height()*4);

        QString pdf_name= "Ingredient"+identifiant_I_string+".pdf";
        QPdfWriter pdf(pdf_name);
        QPainter painter(&pdf);
        painter.drawPixmap(3000,0,logo.width()*4,logo.height()*4,logo);


        painter.setPen(Qt::blue);
        painter.drawText(100,2300,"Identifiant d'ingredient : ");
        painter.setPen(Qt::black);
        painter.drawText(2000,2300,identifiant_I_string);
        painter.setPen(Qt::blue);
        painter.drawText(100,2600,"Nom d'ingredient : ");
        painter.setPen(Qt::black);
        painter.drawText(2000,2600,nom_I);
        painter.setPen(Qt::blue);
        painter.drawText(100,2900,"Quantité d'ingredient : ");
        painter.setPen(Qt::black);
        painter.drawText(2000,2900,quantite_I_string);
        painter.setPen(Qt::blue);
        painter.drawText(100,3200,"Prix d'ingredient : ");
        painter.setPen(Qt::black);
        painter.drawText(2000,3200,prix_I_string);
        painter.setPen(Qt::blue);
        painter.drawText(100,3500,"Type d'ingredient : ");
        painter.setPen(Qt::black);
        painter.drawText(2000,3500,type_I);
        painter.setPen(Qt::blue);



        painter.end();
        QMessageBox::information(nullptr, QObject::tr("pdf  "),
                    QObject::tr("Exportation PDF terminer"), QMessageBox::Accepted);


}*/






void Produit_ingredient::on_chercher_produit_clicked()
{

    int identifiant_P_rech= -1;
        identifiant_P_rech= ui->identifiant_P_rech->text().toInt();

    QString test_vide_P= ui->identifiant_P_rech->text();
    QString type_P_rech= ui->type_P_rech->text();

    ui->afficher_produit->setModel(P.chercher_produit(identifiant_P_rech, type_P_rech, test_vide_P));

}



void Produit_ingredient::on_chercher_ingredient_clicked()
{
    int identifiant_I_rech= -1;
        identifiant_I_rech= ui->identifiant_I_rech->text().toInt();

    QString test_vide_I= ui->identifiant_I_rech->text();
    QString type_I_rech= ui->type_I_rech->text();

    ui->afficher_ingredient->setModel(I.chercher_ingredient(identifiant_I_rech, type_I_rech, test_vide_I));
}







void Produit_ingredient::on_stat_P_clicked()
{
    QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/sound/button.wav");

    Statsr S;
            S.statistique_P();
            S.setModal(true);
            S.exec();

}

void Produit_ingredient::on_stat_I_clicked()
{
    QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/sound/button.wav");

    Statsr S;
            S.statistique_I();
            S.setModal(true);
            S.exec();
}





void Produit_ingredient::on_excel_P_clicked()
{
    QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/sound/button.wav");

    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObjectr obj(fileName, "mydata", ui->afficher_produit);

        //colums to export
        obj.addField(0, "Identifiant", "char(20)");
        obj.addField(1, "Nom", "char(20)");
        obj.addField(2, "Quantité", "char(20)");
        obj.addField(3, "Prix", "char(20)");
        obj.addField(4, "Type", "char(20)");




        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
}



void Produit_ingredient::on_excel_I_clicked()
{
    QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/sound/button.wav");

    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObjectr obj(fileName, "mydata", ui->afficher_ingredient);

        //colums to export
        obj.addField(0, "Identifiant", "char(20)");
        obj.addField(1, "Nom", "char(20)");
        obj.addField(2, "Quantité", "char(20)");
        obj.addField(3, "Prix", "char(20)");
        obj.addField(4, "Type", "char(20)");




        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal));
        }

}




void Produit_ingredient::on_PDF_P_clicked()
{
    QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/sound/button.wav");
     // QSound::play(":/new/prefix1/sond/632.wav");

        QString strStream;
                   QTextStream out(&strStream);
                   const int rowCount = ui->afficher_produit->model()->rowCount();
                   const int columnCount =ui->afficher_produit->model()->columnCount();

                   out <<  "<html>\n"
                           "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           <<  QString("<title>%1</title>\n").arg("eleve")
                           <<  "</head>\n"
                           "<body bgcolor=#b8f4ce link=#5000A0>\n"
                              // "<img src='C:/Users/ksemt/Desktop/final/icon/logo.webp' width='20' height='20'>\n"
                               "<img src='C:/Users/ALPHA/Desktop/qt_projets/integration2/pastry_plus.png' width='220' height='200'>\n"
                               "<h1>   Liste des Produits </h1>"
                                "<h1>  </h1>"

                               "<table border=1 cellspacing=0 cellpadding=2>\n";


                   // headers
                       out << "<thead><tr bgcolor=#f0f0f0>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->afficher_produit->isColumnHidden(column))
                               out << QString("<th>%1</th>").arg(ui->afficher_produit->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";
                       // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->afficher_produit->isColumnHidden(column)) {
                                      QString data = ui->afficher_produit->model()->data(ui->afficher_produit->model()->index(row, column)).toString().simplified();
                                      out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                  }
                              }
                              out << "</tr>\n";
                          }
                          out <<  "</table>\n"
                              "</body>\n"
                              "</html>\n";

                          QTextDocument *document = new QTextDocument();
                          document->setHtml(strStream);

                          QPrinter printer;

                          QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                          if (dialog->exec() == QDialog::Accepted) {
                              document->print(&printer);
                       }

                          QMessageBox::information(nullptr, QObject::tr("pdf  "),
                                      QObject::tr("Exportation PDF terminer"), QMessageBox::Accepted);

}



void Produit_ingredient::on_PDF_I_clicked()
{
    QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/sound/button.wav");
     // QSound::play(":/new/prefix1/sond/632.wav");*/

        QString strStream;
                   QTextStream out(&strStream);
                   const int rowCount = ui->afficher_ingredient->model()->rowCount();
                   const int columnCount =ui->afficher_ingredient->model()->columnCount();

                   out <<  "<html>\n"
                           "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           <<  QString("<title>%1</title>\n").arg("eleve")
                           <<  "</head>\n"
                           "<body bgcolor=#b8f4ce link=#5000A0>\n"
                              // "<img src='C:/Users/ksemt/Desktop/final/icon/logo.webp' width='20' height='20'>\n"
                               "<img src='C:/Users/ALPHA/Desktop/qt_projets/integration2/pastry_plus.png' width='220' height='200'>\n"
                               "<h1>   Liste des Ingredients </h1>"
                                "<h1>  </h1>"

                               "<table border=1 cellspacing=0 cellpadding=2>\n";


                   // headers
                       out << "<thead><tr bgcolor=#f0f0f0>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->afficher_ingredient->isColumnHidden(column))
                               out << QString("<th>%1</th>").arg(ui->afficher_ingredient->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";
                       // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->afficher_ingredient->isColumnHidden(column)) {
                                      QString data = ui->afficher_ingredient->model()->data(ui->afficher_ingredient->model()->index(row, column)).toString().simplified();
                                      out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                  }
                              }
                              out << "</tr>\n";
                          }
                          out <<  "</table>\n"
                              "</body>\n"
                              "</html>\n";

                          QTextDocument *document = new QTextDocument();
                          document->setHtml(strStream);

                          QPrinter printer;

                          QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                          if (dialog->exec() == QDialog::Accepted) {
                              document->print(&printer);
                       }

                          QMessageBox::information(nullptr, QObject::tr("pdf  "),
                                      QObject::tr("Exportation PDF terminer"), QMessageBox::Accepted);

}




//*************** TOUL BAR ******************************


void Produit_ingredient::on_produit1_triggered()
{
    QString image;
    image="gateau";

   ToulBar tb;
   tb.afficher(image);

   tb.setModal(true);
   tb.exec();

}


void Produit_ingredient::on_produit2_triggered()
{
    QString image;
    image="pate";

   ToulBar tb;
   tb.afficher(image);

   tb.setModal(true);
   tb.exec();
}


void Produit_ingredient::on_produit3_triggered()
{
    QString image;
    image="sale";

   ToulBar tb;
   tb.afficher(image);

   tb.setModal(true);
   tb.exec();
}




//*************** DATE ******************************


void Produit_ingredient::showtime ()
{
    QTime time = QTime::currentTime();

           QString time_text=time.toString("hh : mm : ss");
           if((time.second() % 2) == 0 )
           {
               time_text[3] = ' ';
               time_text[8] = ' ';
           }
           ui->digital_date_P->setText(time_text) ;
           ui->digital_date_I->setText(time_text) ;
}

void Produit_ingredient::on_pushButton_clicked()
{
     QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/button-30.wav");
    hide();
}
