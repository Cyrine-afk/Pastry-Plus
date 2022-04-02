#include "integr2.h"
#include <QApplication>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include "login.h"
#include "clients_achats.h"
#include "mainwindow.h"
#include "gestion_eventicket.h"
#include "mainwindowj.h"
#include "mainwindowr.h"
#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    connexion C;
   bool test;
       test=C.createConnection();
       integr2 w;
       Clients_Achats c;
       MainWindow m;
       gestion_eventicket g;
       MainWindowj mj;
       MainWindowr mr;
       login l;

       QFile file(":/integra/Toolery.qss");
                   file.open(QFile::ReadOnly);

                   QString styleSheet { QLatin1String(file.readAll()) };

                   //setup stylesheet
                   a.setStyleSheet(styleSheet);

//if(test)
  //  qDebug() <<"connection reussi";
  /*  QMessageBox::information(nullptr,QObject::tr("database is   open"),QObject::tr("connection reussi\n"
                                                                                 "click OK to exit"),
                             QMessageBox::Ok);*/

//else
    //qDebug()<<"erreur de connection";
   /* QMessageBox::information(nullptr,QObject::tr("database is  not open"),QObject::tr("connection failed\n"
                                                                                 "click cancel to exit"),
                             QMessageBox::Cancel);*/


   mr.show();
   QObject::connect(&mr,&MainWindowr::sig,&w,&integr2::show);
    return a.exec();

}
