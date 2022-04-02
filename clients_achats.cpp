
#include "clients_achats.h"
#include "ui_clients_achats.h"
#include "QSqlQuery"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>

#include "connexion.h"
#include "client.h"
#include "achats.h"
//#include "qcustomplot.h"

//#include "secdialog.h"

#include "stmp.h"

#include <QtPrintSupport/QPrinter>
#include <QPainter>


#include <QDesktopServices>
#include <QUrl>

#include "stats.h"

#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QSound>
#include <QMediaPlayer>
#include "arduino_a.h"
#include "integr2.h"


void Clients_Achats::refreshw()
{

    ui->tableView->setModel(c.afficher());

    ui->id_ec->setModel(a.combobox3());

    ui->tableView_2->setModel(a.afficher2());

}


void Clients_Achats:: music(int pp,int m,int mu)
{



   QMediaPlayer * player = new QMediaPlayer;
   player->setMedia(QUrl::fromLocalFile("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/music2.mp3"));
   player->setVolume(20);
   player->play();



}

void Clients_Achats:: calcul_prix()
{

float total=0;

    QString total2 = QString::number(total);
    ui->lineEdit->setText(total2);




}


Clients_Achats::Clients_Achats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clients_Achats)
{
    QString nom3="";
    ui->setupUi(this);
    refreshw();
    calcul_prix();

    int ret= A.connect_arduino();

    switch(ret)
    {
    case(0):qDebug()<<"arduino is available and connected to:"<<A.getarduino_port_name(); break;

    case(1):qDebug()<<"arduino is available but bot connected to:"<<A.getarduino_port_name(); break;

    case(-1):qDebug()<<"arduino is not available ";
                       break;
    }

    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

   // music(0,0,0);






}

Clients_Achats::~Clients_Achats()
{
    delete ui;
}


void change2(QLabel * label, const QString & text, int ms_keep = 7000, int ms_after = 0)
{
    //QString originaltext = label->text();
    QTimer::singleShot(ms_after, [=](){
        label->setText(text);
        QTimer::singleShot(ms_keep, [=](){
            label->setText("");
        });
    });
}

void Clients_Achats::on_pushButton_clicked() //ajout
{

    QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/button-30.wav");


    int i=0,j=0,x=0,n=0,p=0,a=0,b=0,c=0,y=0,w=0,h=0,r=0,t=0,k=0,l=0 ,r2=0,t2=0,k2=0,l2=0,s=0;
    int  c1=0, c2=0, c3=0, c4=0, c5=0, c6=0,c7=0,c8=0;
    int ajout=0;
     int point=10;
    QString diabetique1="";
    int cin1= ui->txt_cin->text().toInt();
    int tel1=ui->txt_tel->text().toInt();
    QString nom1 = ui->txt_nom->text();
    QString prenom1 = ui->txt_prenom->text();
    int age1= ui->txt_age->text().toInt();
    QString email1 = ui->txt_email->text();
    QString adresse1 = ui->txt_adresse->text();


    QString cin2= ui->txt_cin->text();
    QString tel2=ui->txt_tel->text();
    QString age2= ui->txt_age->text();




    QString gmail1="gmail";
     QString gmail2="esprit";

    if(ui->radioButton->isChecked())
       diabetique1="oui";
    else if(ui->radioButton_2->isChecked())
         diabetique1="non";

    if(cin2!="")
    {
     if(cin2.length()!=8)
         c1=1;
    for(i=0;i<cin2.length();i++)
     {
        if(cin2[i]=="a"  )
                c1=1;
        if(cin2[i]=="b"  )
                c1=1;
        if(cin2[i]=="c"  )
                c1=1;
        if(cin2[i]=="d"  )
                c1=1;

        if(cin2[i]=="e"  )
                c1=1;

        if(cin2[i]=="f"  )
                c1=1;

        if(cin2[i]=="g"  )
                c1=1;

        if(cin2[i]=="h"  )
                c1=1;

        if(cin2[i]=="i"  )
                c1=1;

        if(cin2[i]=="j"  )
                c1=1;

        if(cin2[i]=="k"  )
                c1=1;


        if(cin2[i]=="l"  )
                c1=1;

        if(cin2[i]=="m"  )
                c1=1;


        if(cin2[i]=="n"  )
                c1=1;


        if(cin2[i]=="o"  )
                c1=1;


        if(cin2[i]=="p"  )
                c1=1;


        if(cin2[i]=="r"  )
                c1=1;

        if(cin2[i]=="s"  )
                c1=1;


        if(cin2[i]=="t"  )
                c1=1;


        if(cin2[i]=="u"  )
                c1=1;

        if(cin2[i]=="v"  )
                c1=1;

        if(cin2[i]=="w"  )
                c1=1;

        if(cin2[i]=="x"  )
                c1=1;

        if(cin2[i]=="y"  )
                c1=1;

        if(cin2[i]=="z"  )
                c1=1;
     }

    }
    else
    {
        c1=1;
    }

    if(tel2!="")
    {
     if(tel2.length()!=8)
         c4=1;
    for(i=0;i<tel2.length();i++)
     {
        if(tel2[i]=="a"  )
                c4=1;
        if(tel2[i]=="b"  )
                c4=1;
        if(tel2[i]=="c"  )
                c4=1;
        if(tel2[i]=="d"  )
                c4=1;

        if(tel2[i]=="e"  )
                c4=1;

        if(tel2[i]=="f"  )
                c4=1;

        if(tel2[i]=="g"  )
                c4=1;

        if(tel2[i]=="h"  )
                c4=1;

        if(tel2[i]=="i"  )
                c4=1;

        if(tel2[i]=="j"  )
                c4=1;

        if(tel2[i]=="k"  )
                c4=1;


        if(tel2[i]=="l"  )
                c4=1;

        if(tel2[i]=="m"  )
                c4=1;


        if(tel2[i]=="n"  )
                c4=1;


        if(tel2[i]=="o"  )
                c4=1;


        if(tel2[i]=="p"  )
                c4=1;


        if(tel2[i]=="r"  )
                c4=1;

        if(tel2[i]=="s"  )
                c4=1;


        if(tel2[i]=="t"  )
                c4=1;


        if(tel2[i]=="u"  )
                c4=1;

        if(tel2[i]=="v"  )
                c4=1;

        if(tel2[i]=="w"  )
                c4=1;

        if(tel2[i]=="x"  )
                c4=1;

        if(tel2[i]=="y"  )
                c4=1;

        if(tel2[i]=="z"  )
                c4=1;
     }

    }
    else
    {
        c4=1;
    }


    if(nom1!="")
    {
    for(i=0;i<nom1.length();i++)
    {
        if(nom1[i]=="0")
            c2=1;
        if(nom1[i]=="1")
            c2=1;
        if(nom1[i]=="2")
            c2=1;
        if(nom1[i]=="3")
            c2=1;
        if(nom1[i]=="4")
            c2=1;
        if(nom1[i]=="5")
            c2=1;
        if(nom1[i]=="6")
            c2=1;
        if(nom1[i]=="7")
            c2=1;
        if(nom1[i]=="8")
            c2=1;
        if(nom1[i]=="9")
            c2=1;
    }
    }else
       c2=1;

    if(nom1!="")
    {
    for(i=0;i<prenom1.length();i++)
    {
        if(prenom1[i]=="0")
            c3=1;
        if(prenom1[i]=="1")
            c3=1;
        if(prenom1[i]=="2")
            c3=1;
        if(prenom1[i]=="3")
            c3=1;
        if(prenom1[i]=="4")
            c3=1;
        if(prenom1[i]=="5")
            c3=1;
        if(prenom1[i]=="6")
            c3=1;
        if(prenom1[i]=="7")
            c3=1;
        if(prenom1[i]=="8")
            c3=1;
        if(prenom1[i]=="9")
            c3=1;
    }
    }else
       c3=1;







    for(i=0;i<email1.length();i++)
    {
        if(email1[i]=="a"  )
                j++;
        if(email1[i]=="b"  )
                  j++;
        if(email1[i]=="c"  )
                    j++;
        if(email1[i]=="d"  )
 j++;

        if(email1[i]=="e"  )
 j++;

        if(email1[i]=="f"  )
 j++;

        if(email1[i]=="g"  )
 j++;

        if(email1[i]=="h"  )

 j++;

        if(email1[i]=="i"  )
 j++;

        if(email1[i]=="j"  )
 j++;

        if(email1[i]=="k"  )

 j++;

        if(email1[i]=="l"  )
 j++;

        if(email1[i]=="m"  )

 j++;

        if(email1[i]=="n"  )

 j++;

        if(email1[i]=="o"  )
 j++;

        if(email1[i]=="p"  )
 j++;

        if(email1[i]=="r"  )

 j++;

        if(email1[i]=="s"  )


j++;


        if(email1[i]=="t"  )
j++;
        if(email1[i]=="u"  )

j++;
        if(email1[i]=="v"  )
j++;
        if(email1[i]=="w"  )
j++;
        if(email1[i]=="x"  )
j++;
        if(email1[i]=="y"  )

j++;
        if(email1[i]=="z"  )
j++;


        if(email1[i]=="0")
            n++;

        if(email1[i]=="1")
            n++;
        if(email1[i]=="2")
            n++;
        if(email1[i]=="3")
            n++;
        if(email1[i]=="4")
            n++;
        if(email1[i]=="5")
            n++;
        if(email1[i]=="6")
            n++;
        if(email1[i]=="7")
            n++;
        if(email1[i]=="8")
            n++;
        if(email1[i]=="9")
            n++;


        if(email1[i]=="@")
          {
            y=i;
           x++;
           if(i<9)
               b=1;
          }

        if(email1[i]==".")
        {
            p++;
            w=i;
         }



}
    for( h=y+1;h<w;h++)
    {
        if(r!=1)
        {

            if(email1[h]==gmail1[t])
            {
                k++;
                t++;
                r=0;
            }
            else
                r==1;

        }


        if(r2!=1)
        {

            if(email1[h]==gmail2[t2])
            {
                k2++;
                t2++;
                r2=0;
            }
            else
                r2==1;

        }


    }

    if(k>=4)
        s=1;
    if(k2>=6)
        s=1;

    if(w-y<5)
        c=1;


    if(adresse1=="")
        c6=1;

    if(diabetique1=="")
        c7=1;

    if(age2=="")
    {
        c8=1;
    }

    if(c1==1)
    ui->c_1->setText("cin vide ou contient des lettres ");
    else
      ui->c_1->setText("");

    if(j<8 || x==0 || x>1 || n<2 ||p==0||p>1||b==1||c==1||s!=1)
    ui->c_5->setText("email vide ou non valide");
    else
      ui->c_5->setText("");

    if(c2==1)
    ui->c_2->setText("nom vide ou contient des numeros");
     else
    ui->c_2->setText("");

    if(c3==1)
    ui->c_3->setText("prenom vide ou contient des numeros");
     else
    ui->c_3->setText("");

    if(c7==1)
    ui->c_7->setText("cocher OUI ou NON");
     else
    ui->c_7->setText("");

    if(c6==1)
    ui->c_6->setText("adresse vide");
     else
    ui->c_6->setText("");


    if(c4==1)
    ui->c_4->setText("tel vide ou non valide");
     else
    ui->c_4->setText("");

    if(c8==1)
    ui->c_8->setText("age vide ou non valide");
     else
    ui->c_8->setText("");




if(j<8 || x==0 || x>1 || n<2 ||p==0||p>1||b==1||c==1||s!=1||c1==1||c2==1||c3==1||c7==1||c6==1||c4==1||c8==1)
   {
      ajout=1;
   }

if(ajout==0)
{


   client c(cin1,nom1,prenom1,tel1,email1,adresse1,diabetique1,age1,point);







   bool test= c.ajouter_client();




   if(test)
   {

   refreshw();
    // ui->label_52->setText("ajout terminer");

      change2(ui->label_52,"<font color='green'> ajout terminer </font>",7000, 0);

      //ui->label_53->setText("");
  }






else
   {
   //ui->label_53->setText("ajout refuser");
     change2(ui->label_52,"<font color='red'> ajout terminer </font>",7000, 0);

     //ui->label_52->setText("");
   }

   }

}



void Clients_Achats::on_pushButton_2_clicked() //recherche
{

     QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/button-30.wav");
    refreshw();

QString nom3 = ui->nom_aff->text();
QString mail3=ui->txt_email_3->text();

    int d=0,t=0;
    if(ui->radioButton_5->isChecked())
      d=1;
   else if(ui->radioButton_6->isChecked())
        d=2;

    else if(ui->radioButton_7->isChecked())
         d=0;



     ui->tableView->setModel(c.chercher(d,nom3,mail3));
}


void Clients_Achats::on_pushButton_5_clicked()//trier
{


     QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/button-30.wav");
    refreshw();
    QString nom3 = ui->nom_aff->text();
    QString mail3=ui->txt_email_3->text();
    int t=0,d=0;
    if(ui->radioButton_8->isChecked())
             t=1;

     if(ui->radioButton_9->isChecked())
         t=2;

     if(ui->radioButton_10->isChecked())
         t=0;



     if(ui->radioButton_39->isChecked())
              d=1;

      if(ui->radioButton_38->isChecked())
          d=2;

      if(ui->radioButton_10->isChecked())
          d=0;

     ui->tableView->setModel(c.trier(t,nom3,mail3,d));
}



void Clients_Achats::on_pushButton_3_clicked() //modif
{


    QString diabetique2;
   int cin2 =ui->cin_ligne->text().toInt();


int point2=c.clicker8(cin2);

   QString nom2 = ui->txt_nom_2->text();
   QString prenom2 = ui->txt_prenom_2->text();
   int age2 = ui->txt_age_2->text().toInt();
   int tel2=ui->txt_tel_2->text().toInt();
   QString adresse2 = ui->txt_adresse_2->text();
   QString email2 = ui->txt_email_2->text();

    if(ui->radioButton_3->isChecked())
      diabetique2="oui";
   else if(ui->radioButton_4->isChecked())
        diabetique2="non";
 client c(cin2,nom2,prenom2,tel2,email2,adresse2,diabetique2,age2,point2);
 bool test=c.modifier_client();

 if(test)
 {
refreshw();
 }
 else
     QMessageBox::critical(nullptr, QObject::tr("modif refuser"),
                 QObject::tr("la modf de client  est refusé.\n"
                             "Clicker sur  Abort ."), QMessageBox::Abort);

}

void Clients_Achats::on_pushButton_4_clicked() //delete
{
    int cin = ui->ligne1->text().toInt();
        bool  test = c.supp_client(cin);
        if (test)
        {
       refreshw();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("suprr refuser"),
                        QObject::tr("la supp de compte  est refusé.\n"
                                    "Clicker sur  Abort ."), QMessageBox::Abort);
}






void Clients_Achats::on_pushButton_7_clicked() //ajout_achat
{
    int x=0,y=0,z=0;
  int i=0,c2=0,c3=0,c4=0,c5=0;
    int nomc6;
    QString nomc7;

    QString conf1;
    QDate date1=ui->dateEdit->date();
    int id_a1 =ui->id_a->text().toInt();
    int id_e1 =ui->id_e->text().toInt();
    QString nom_c1=ui->nom_c->text();
    QString prenom_c1=ui->prenom_c->text();
    QString produit1=ui->comboBox_p->currentText();
    int quantite1=ui->spinBox_q->text().toInt();

    if(ui->radioButton_11->isChecked())
      conf1="oui";
   else if(ui->radioButton_12->isChecked())
      conf1="non";



    QString id_ima =ui->id_a->text();
    QString id_ime =ui->id_e->text();
    QString quantite_im=ui->spinBox_q->text();
    QString dw = date1.toString("dd-MM-yyyy");

    QString cin4 =ui->lineEdit_3->text();


    int point=c.clicker9(cin4);

    nomc6=c.clicker10(cin4);
    nomc7=c.clicker11(cin4);


    if(id_ima.length()==0)
        c4=1;
    if(id_ime.length()==0)
        c5=1;


    if(produit1=="Produits")
    {x=1;
        ui->c_12->setText("choisir un produit");
    }
    else
       ui->c_12->setText("");

 if(conf1=="")
 {
     ui->c_14->setText("OUI ou NON");
     z=1;
}
  ui->c_14->setText("");

    if(quantite1==0)
    {
     ui->c_13->setText("quantite egale a 0 ");
        y=1;
    }
    if(nom_c1!="")
    {
    for(i=0;i<nom_c1.length();i++)
    {
        if(nom_c1[i]=="0")
            c2=1;
        if(nom_c1[i]=="1")
            c2=1;
        if(nom_c1[i]=="2")
            c2=1;
        if(nom_c1[i]=="3")
            c2=1;
        if(nom_c1[i]=="4")
            c2=1;
        if(nom_c1[i]=="5")
            c2=1;
        if(nom_c1[i]=="6")
            c2=1;
        if(nom_c1[i]=="7")
            c2=1;
        if(nom_c1[i]=="8")
            c2=1;
        if(nom_c1[i]=="9")
            c2=1;
    }
    }else
       c2=1;

    if(prenom_c1!="")
    {

    for(i=0;i<prenom_c1.length();i++)
    {
        if(prenom_c1[i]=="0")
            c3=1;
        if(prenom_c1[i]=="1")
            c3=1;
        if(prenom_c1[i]=="2")
            c3=1;
        if(prenom_c1[i]=="3")
            c3=1;
        if(prenom_c1[i]=="4")
            c3=1;
        if(prenom_c1[i]=="5")
            c3=1;
        if(prenom_c1[i]=="6")
            c3=1;
        if(prenom_c1[i]=="7")
            c3=1;
        if(prenom_c1[i]=="8")
            c3=1;
        if(prenom_c1[i]=="9")
            c3=1;
    }
    }else
       c3=1;

 if(c2==1)
     ui->c_11->setText("nom vide ou non valide");
 else
     ui->c_11->setText("");
 if(c3==1)
     ui->c_15->setText("prenom vide ou non valide");
     else
         ui->c_15->setText("");

 if(c4==1)
     ui->c_9->setText("id achats vide");
      else
      ui->c_9->setText("");

 if(c5==1)
     ui->c_10->setText("id emp vide");
   else
      ui->c_10->setText("");

    if(x==0 && y==0 && z==0 && c2==0 && c3==0 && c4==0 && c5==0)
    {


        if( nomc7=="oui")
        {

          if(produit1=="Gateau" || produit1=="Millefeuille")
      {

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Diabetique", "confirme?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
          qDebug() << "Yes was clicked";
          if(xx==1 || point3!="")
            {
              point=0;
              point=point+5;
              c.modifier_client2(cin4,point);

            }
          else{
         point=point+5;
         c.modifier_client2(cin4,point);
          }

            achat a( conf1, date1,id_a1,id_e1 , nom_c1, prenom_c1, produit1, quantite1);
            bool test= a.ajouter_achat();
             refreshw();
         if(test)
            {
             if(ui->checkBox->isChecked())
             {


                /* QPixmap logo;
                         logo.load("D:/QT/Awork/produit_ingredient_1/pastry_plus.png");
                         logo.scaled(logo.width()4, logo.height()4);

                        QString pdf_name= "file_ach_"+id_ima+".pdf";
                         QPdfWriter pdf(pdf_name);
                         QPainter painter(&pdf);
                         painter.drawPixmap(3000,0,logo.width()4,logo.height()4,logo);*/


                 QPixmap logo;
                 logo.load("C:/Users/ALPHA/Desktop/qt_projets/pastry.png");
                 logo.scaled(logo.width()*10,logo.height()*10);

                 QString pdf_name= "file_ach_"+id_ima+".pdf";
                 QPdfWriter pdf(pdf_name);
                 QPainter painter(&pdf);
                 painter.drawPixmap(7100,0,logo.width()*3,logo.height()*3,logo);




                 painter.setPen(Qt::red);
                 painter.drawText(100,1200,"votre info : ");

                 painter.setPen(Qt::blue);
                 painter.drawText(100,1700," id_achats : ");
                 painter.setPen(Qt::black);
                 painter.drawText(1500,1700,id_ima);

                 painter.setPen(Qt::blue);
                 painter.drawText(100,2200,"id_employe : ");
                 painter.setPen(Qt::black);
                 painter.drawText(1500,2200,id_ime);

                 painter.setPen(Qt::blue);
                 painter.drawText(100,2700,"nom client : ");
                 painter.setPen(Qt::black);
                 painter.drawText(1500,2700,nom_c1);

                 painter.setPen(Qt::blue);
                 painter.drawText(100,3200,"prenom client : ");
                 painter.setPen(Qt::black);
                 painter.drawText(1500,3200,prenom_c1);

                 painter.setPen(Qt::blue);
                 painter.drawText(100,3700,"date achat : ");
                 painter.setPen(Qt::black);
                 painter.drawText(1500,3700,dw);

                 painter.setPen(Qt::blue);
                 painter.drawText(100,4200,"produit : ");
                 painter.setPen(Qt::black);
                 painter.drawText(1500,4200,produit1);

                 painter.setPen(Qt::blue);
                 painter.drawText(100,4700,"quantite : ");
                 painter.setPen(Qt::black);
                 painter.drawText(1500,4700,quantite_im);

                 painter.setPen(Qt::blue);
                 painter.drawText(100,5200,"confirmation : ");
                 painter.setPen(Qt::black);
                 painter.drawText(1500,5200,conf1);




                 painter.end();

                         ui->label_54->setText("achat terminer avec pdf");

                         ui->label_55->setText("");


         }
        else{

           ui->label_54->setText("achat terminer");
           ui->label_55->setText("");
        }
        }

      else
         {
      ui->label_55->setText("achat refuser");
         ui->label_54->setText("");



         }


          //QApplication::quit();
        } else {
          qDebug() << "Yes was *not* clicked";
        }

       }

        }

        else if(nomc7=="non" || nomc7=="")
        {

            if(xx==1 || point3!="")
              {
                point=0;
                point=point+5;
                c.modifier_client2(cin4,point);

              }
            else{
           point=point+5;
           c.modifier_client2(cin4,point);
            }
       achat a( conf1, date1,id_a1,id_e1 , nom_c1, prenom_c1, produit1, quantite1);
       bool test= a.ajouter_achat();
        refreshw();
    if(test)
       {
        if(ui->checkBox->isChecked())
        {


           /* QPixmap logo;
                    logo.load("D:/QT/Awork/produit_ingredient_1/pastry_plus.png");
                    logo.scaled(logo.width()4, logo.height()4);

                   QString pdf_name= "file_ach_"+id_ima+".pdf";
                    QPdfWriter pdf(pdf_name);
                    QPainter painter(&pdf);
                    painter.drawPixmap(3000,0,logo.width()4,logo.height()4,logo);*/


            QPixmap logo;
            logo.load("C:/Users/ALPHA/Desktop/qt_projets/pastry.png");
            logo.scaled(logo.width()*10,logo.height()*10);

            QString pdf_name= "file_ach_"+id_ima+".pdf";
            QPdfWriter pdf(pdf_name);
            QPainter painter(&pdf);
            painter.drawPixmap(7100,0,logo.width()*3,logo.height()*3,logo);




            painter.setPen(Qt::red);
            painter.drawText(100,1200,"votre info : ");

            painter.setPen(Qt::blue);
            painter.drawText(100,1700," id_achats : ");
            painter.setPen(Qt::black);
            painter.drawText(1500,1700,id_ima);

            painter.setPen(Qt::blue);
            painter.drawText(100,2200,"id_employe : ");
            painter.setPen(Qt::black);
            painter.drawText(1500,2200,id_ime);

            painter.setPen(Qt::blue);
            painter.drawText(100,2700,"nom client : ");
            painter.setPen(Qt::black);
            painter.drawText(1500,2700,nom_c1);

            painter.setPen(Qt::blue);
            painter.drawText(100,3200,"prenom client : ");
            painter.setPen(Qt::black);
            painter.drawText(1500,3200,prenom_c1);

            painter.setPen(Qt::blue);
            painter.drawText(100,3700,"date achat : ");
            painter.setPen(Qt::black);
            painter.drawText(1500,3700,dw);

            painter.setPen(Qt::blue);
            painter.drawText(100,4200,"produit : ");
            painter.setPen(Qt::black);
            painter.drawText(1500,4200,produit1);

            painter.setPen(Qt::blue);
            painter.drawText(100,4700,"quantite : ");
            painter.setPen(Qt::black);
            painter.drawText(1500,4700,quantite_im);

            painter.setPen(Qt::blue);
            painter.drawText(100,5200,"confirmation : ");
            painter.setPen(Qt::black);
            painter.drawText(1500,5200,conf1);




            painter.end();
            ui->label_54->setText("achat terminer avec pdf");

            ui->label_55->setText("");


}
else{

ui->label_54->setText("achat terminer");
ui->label_55->setText("");
}
}

else
{
ui->label_55->setText("achat refuser");
ui->label_54->setText("");



}


}

}

}


void Clients_Achats::on_pushButton_9_clicked() //mod achats_cl
{

    int x=0,y=0,z=0;

    QString conf1;
    QDate date1=ui->dateEdit_2->date();
    int id_a1 =ui->mod_a->text().toInt();
    int id_e1 =ui->id_e2->text().toInt();
    QString nom_c1=ui->nom_c_2->text();
    QString prenom_c1=ui->prenom_c_2->text();
    QString produit1=ui->produit2->currentText();
    int quantite1=ui->spinBox_q_2->text().toInt();

    if(ui->radioButton_13->isChecked())
      conf1="oui";
   else if(ui->radioButton_14->isChecked())
      conf1="non";

    if(produit1=="Produits")
    x=1;

 if(conf1=="")
     z=1;

    if(quantite1==0)
     y=1;

    if(x==1 && y==1 && z==1)
    {
        QMessageBox::information(nullptr, QObject::tr("Produit , Quantite et Confirmation"),
                    QObject::tr("Produit non choisi , Quantite egale a 0 et Confirmation n'est pas choisi.\n"
                                ""), QMessageBox::Ok);
    }


    if(x==1 && y==0 && z==0)
    {
        QMessageBox::information(nullptr, QObject::tr("Produit"),
                    QObject::tr("Produit non choisi .\n"
                                ""), QMessageBox::Ok);
    }

    if(x==1 && y==1 && z==0)
    {
        QMessageBox::information(nullptr, QObject::tr("Produit et Quantite"),
                    QObject::tr("Produit non choisi et qunatite egale a  0.\n"
                                ""), QMessageBox::Ok);
    }


    if(x==1 && y==0 && z==1)
    {
        QMessageBox::information(nullptr, QObject::tr("Produit et Confirmation"),
                    QObject::tr("Produit non choisi et Confirmation non choisi.\n"
                                ""), QMessageBox::Ok);
    }

    if(x==0 && y==1 && z==1)
    {
        QMessageBox::information(nullptr, QObject::tr("Confirmation et Quantite"),
                    QObject::tr("Confirmation non choisi et qunatite egale a  0.\n"
                                ""), QMessageBox::Ok);
    }


    if(x==0 && y==1 && z==0)
    {
        QMessageBox::information(nullptr, QObject::tr("Quantite"),
                    QObject::tr("Quantite egale a 0.\n"
                                ""), QMessageBox::Ok);
    }

    if(z==1 && x==0 && y==0)
    {
        QMessageBox::information(nullptr, QObject::tr(" Confirmation"),
                    QObject::tr(" Confirmation n'est pas choisi.\n"
                                ""), QMessageBox::Ok);
    }


    if(x==0 && y==0 && z==0)
    {

       achat a( conf1, date1,id_a1,id_e1 , nom_c1, prenom_c1, produit1, quantite1);
       bool test=a.modif_achat();
       if(test)
       {
      refreshw();
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("modif refuser"),
                       QObject::tr("la modf d' Achats  est refusé.\n"
                                   "Clicker sur  Abort ."), QMessageBox::Abort);

      }





}





void Clients_Achats::on_pushButton_8_clicked() //supp achats_cl
{
    int id_a = ui->sup_a->text().toInt();
        bool  test = a.supp_achat(id_a);
        if (test)
        {
       refreshw();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("suprr refuser"),
                        QObject::tr("la supp d'achats  est refusé.\n"
                                    "Clicker sur  Abort ."), QMessageBox::Abort);
}


void Clients_Achats::on_pushButton_10_clicked() //chercher achats
{

     QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/button-30.wav");
    int x=0,y=0,z=0;
//refreshw();
     ui->tableView_2->setModel(a.afficher2());
    QDate d1(2000, 01, 01);

    QString conf2="";
     QDate date2;
     int id_e2 =ui->id_ec->currentText().toInt();


     if(ui->radioButton_15->isChecked())
      y=1;
   else if(ui->radioButton_16->isChecked())
      y=2;
    else if(ui->radioButton_17->isChecked())
      y=0;

       if(ui->radioButton_18->isChecked())
       z=1;
       else
       z=2;

 ui->tableView_2->setModel(a.cherchera(y,z,conf2,date2,id_e2));

}

void Clients_Achats::on_pushButton_41_clicked() //trier achats
{


   QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/button-30.wav");
    refreshw();

    int t=0,d=0;


   if(ui->radioButton_65->isChecked())
            t=1;

    if(ui->radioButton_66->isChecked())
        t=2;

    if(ui->radioButton_70->isChecked())
        t=0;


    if(ui->radioButton_68->isChecked())
             d=1;

     if(ui->radioButton_69->isChecked())
           d=2;





    ui->tableView_2->setModel(a.triera(t,d));

}


void Clients_Achats::on_tableView_clicked(const QModelIndex &index)
{

    if(index.isValid())
        {
            QString ligne = index.data(index.column()).toString();


            QString nomc1;
            QString nomc2;
            QString nomc3;
            QString nomc4;
            QString nomc5;
            QString nomc6;
            QString nomc7;



            ui->ligne1->setText(ligne);
            ui->cin_ligne->setText(ligne);
            int cin2 =ui->cin_ligne->text().toInt();

            nomc1=c.clicker1(cin2);
            nomc2=c.clicker2(cin2);
            nomc3=c.clicker3(cin2);
            nomc4=c.clicker4(cin2);
            nomc5=c.clicker5(cin2);
            nomc6=c.clicker6(cin2);
            nomc7=c.clicker7(cin2);



            ui->txt_nom_2->setText(nomc1);
            ui->txt_prenom_2->setText(nomc2);
            ui->txt_adresse_2->setText(nomc5);
            ui->txt_email_2->setText(nomc4);

            ui->txt_age_2->setText(nomc7);
            ui->txt_tel_2->setText(nomc3);
            ui->diab_ret->setText(nomc6);
}

}



void Clients_Achats::on_tableView_2_clicked(const QModelIndex &index)
{


    if(index.isValid())
        {
            QString ligne = index.data(index.column()).toString();



            QString nomc1;
            QString nomc2;
            QString nomc3;
            QString nomc4;
            int nomc5;
            QString nomc6;
            QDate nomc7;




            ui->sup_a->setText(ligne);
            ui->mod_a->setText(ligne);
            int cin2 =ui->mod_a->text().toInt();

            nomc1=a.clicker1(cin2);
            nomc2=a.clicker2(cin2);
            nomc3=a.clicker3(cin2);
            nomc4=a.clicker4(cin2);
            nomc6=a.clicker6(cin2);


            nomc5=a.clicker5(cin2);

            nomc7=a.clicker7(cin2);




            ui->id_e2->setText(nomc1);
            ui->nom_c_2->setText(nomc2);
            ui->prenom_c_2->setText(nomc3);
            ui->prod->setText(nomc4);

            ui->spinBox_q_2->setValue(nomc5);

            ui->conf->setText(nomc6);
            ui->dateEdit_2->setDate(nomc7);

}



}




void Clients_Achats::on_pushButton_11_clicked()
{

    QSound::play("C:/Users/ALPHA/Desktop/qt_projets/Clients_Achats/images/button-30.wav");
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( """ + QFileInfo(file).fileName() + "" " );

    ui->lineEdit_2->setText( fileListString );
}


void Clients_Achats::on_pushButton_6_clicked()
{
    Smtp* smtp = new Smtp("ahmed.missaoui1@esprit.tn",ui->mail_pass_2->text(), "smtp.gmail.com");
      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

      if( !files.isEmpty() )
          smtp->sendMail("ahmed.missaoui1@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->text(),files );
      else
          smtp->sendMail("ahmed.missaoui1@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->text());

}





void Clients_Achats::on_pushButton_12_clicked()
{


     QSound::play("C:/Users/ALPHA/Desktop/qt_projets/Clients_Achats/images/button-30.wav");

    float prix=0;
    float total=0;


     QString produit1=ui->comboBox_p->currentText();
     int quantite1=ui->spinBox_q->text().toInt();



      if(ui->comboBox_p->currentText()=="Gateau")
       {
        prix=35.700;
        total=prix*quantite1;



       }

      if(ui->comboBox_p->currentText()=="Millefeuille")
       {
        prix=3.500;
        total=prix*quantite1;


       }

      if(ui->comboBox_p->currentText()=="Croissant")
       {
        prix=1.500;
        total=prix*quantite1;


       }



      QString total2 = QString::number(total);
      ui->lineEdit->setText(total2);



}

void Clients_Achats::on_pushButton_13_clicked()
{

     QSound::play("C:/Users/ALPHA/Desktop/qt_projets/Clients_Achats/images/button-30.wav");
    int cin2 =ui->lineEdit_3->text().toInt();

 int point2=c.clicker8(cin2);
  point3 = QString::number(point2);



 ui->label_48->setText("votre point de fidélité est: '"+point3+"' ");
}



void Clients_Achats::on_pushButton_14_clicked()
{
 QSound::play("C:/Users/ALPHA/Desktop/qt_projets/Clients_Achats/images/button-30.wav");

    xx=1;
    float prix=0;
    float total=0;

    QString cin4 =ui->lineEdit_3->text();
    int point=c.clicker9(cin4);
    float remise=point*0.1;


     QString produit1=ui->comboBox_p->currentText();
     int quantite1=ui->spinBox_q->text().toInt();



      if(ui->comboBox_p->currentText()=="Gateau")
       {
        prix=35.7;
        total=prix*quantite1;
        total=total-remise;


       }

      if(ui->comboBox_p->currentText()=="Millefeuille")
       {
        prix=3.5;
        total=prix*quantite1;
            total=total-remise;

       }

      if(ui->comboBox_p->currentText()=="Croissant")
       {
        prix=1.5;
        total=prix*quantite1;
        total=total-remise;

       }

      if(ui->comboBox_p->currentText()=="Mini-cakes  sans sucre")
       {
        prix=8.9;
        total=prix*quantite1;
        total=total-remise;

       }


      if(ui->comboBox_p->currentText()=="Cookies sans sucre")
       {
        prix=6.9;
        total=prix*quantite1;
        total=total-remise;

       }






      QString total2 = QString::number(total);
      ui->lineEdit->setText(total2);

}

void Clients_Achats::on_comboBox_p_currentIndexChanged(const QString &produit)
{
// QMessageBox::information(this,"test",arg1);
  /*secDialog se;
  se.afficher(arg1);
  se.setModal(true);
  se.exec();*/

    float prix;


      if(produit=="Gateau")
      {
          prix=35.7;

          QPixmap pix("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/gateau.jpg");
          ui->label_img->setPixmap(pix.scaled(340,300,Qt::KeepAspectRatio));
           ui->label->setText(produit);
      }

      if(produit=="Millefeuille")
      {
          prix=3.5;

          QPixmap pix("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/millefeuille.jpeg");
          ui->label_img->setPixmap(pix.scaled(340,300,Qt::KeepAspectRatio));
           ui->label->setText(produit);
      }

      if(produit=="Croissant")
      {
          prix=1.5;

          QPixmap pix("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/croissant.jpeg");
          ui->label_img->setPixmap(pix.scaled(340,300,Qt::KeepAspectRatio));
          ui->label->setText(produit);
      }


      if(produit=="Mini-cakes  sans sucre")
      {
          prix=8.9;

          QPixmap pix("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/mini.jpg");
          ui->label_img->setPixmap(pix.scaled(340,300,Qt::KeepAspectRatio));
           ui->label->setText("Mini-cakes");
      }



      if(produit=="Cookies sans sucre")
      {
          prix=6.9;

          QPixmap pix("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/cookies.jpeg");
          ui->label_img->setPixmap(pix.scaled(340,300,Qt::KeepAspectRatio));
           ui->label->setText("Cookies");
      }




      ui->label_51->setText("Prix:");
      ui->label_50->setText("DT");
      ui->label_49->setNum(prix);





}





void Clients_Achats::on_pushButton_15_clicked()
{

    Stats S;
                S.stats_d();
                S.setModal(true);
                S.exec();

}





void Clients_Achats::on_pushButton_16_clicked()
{
     QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/button-30.wav");
  hide();

}
