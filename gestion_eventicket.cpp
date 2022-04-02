#include "gestion_eventicket.h"
#include "ui_gestion_eventicket.h"
#include "statsmo.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QIntValidator>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include "QPrintDialog"
#include <QtPrintSupport/QPrintDialog>
#include <QPrintPreviewDialog>
#include <QSound>
#include "stmp.h"

gestion_eventicket::gestion_eventicket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_eventicket)
{
    ui->setupUi(this);

show_tables();
   /* int ret= A.connect_arduino();

         switch(ret)
        {
        case(0):qDebug()<<"arduino is available and connected to:"<<A.getarduino_port_name(); break;

        case(1):qDebug()<<"arduino is available but bot connected to:"<<A.getarduino_port_name(); break;

        case(-1):qDebug()<<"arduino is not available ";
                           break;
        }

        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
        ui->ard->setText(A.read_from_arduino());
        if (A.read_from_arduino()=="wait")
        {
            A.write_to_arduino("d");
        }
        */

}

gestion_eventicket::~gestion_eventicket()
{
    delete ui;
}

void gestion_eventicket::show_tables()
{
    show_evenement();
    show_ticket();
}
/*********************************** evenement ****************************/

//************************ crud

//ajout
void gestion_eventicket::on_actionadd_evenement_triggered()
{
    //creation instance
        add_evenement ac(this);

        //ouvrir dialog
        int res=ac.exec();
        if (res == QDialog::Rejected )
            return;

      //recuperation des donnees
        QString s1=ac.id();
        QString s2=ac.nom();
        QString s3=ac.date_e();
        QString s4=ac.produit();
        QString x=ac.lieu();

        //ajout
        evenement mc(s1,s2,s3,x,s4);
        mc.ajouter();

        //refresh du tableau (affichage)
          show_evenement();
}

                                                                                                                                                                          //sel
void gestion_eventicket::on_table_evenement_clicked(const QModelIndex &index)
{
    selected_evenement=ui->table_evenement->model()->data(index).toString();
}

//modification
void gestion_eventicket::on_table_evenement_doubleClicked(const QModelIndex &index)
{
    add_evenement ac(this);

  ac.fill_form(selected_evenement);
  int res=ac.exec();
  if (res == QDialog::Rejected )
    return;
  //recuperation des donnees
  QString s2=ac.nom();
  QString s3=ac.date_e();
  QString s4=ac.produit();
  QString x=ac.lieu();

    //mofication
    evenement mc(selected_evenement,s2,s3,x,s4);
    mc.modifier(selected_evenement);

    //refresh du tableau (affichage)
    show_evenement();

}

//suppression
void gestion_eventicket::on_actiondelete_evenement_triggered()
{
    evenement mc;
  mc.supprimer(selected_evenement);

 //refresh du tableau (affichage)
   show_evenement();
}

//affichage
void gestion_eventicket::show_evenement()
{
    //creation model (masque du tableau) : permet recherche
        proxy_evenement = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_evenement->setSourceModel(tmp_evenement.afficher());

     //pour la recherche
        proxy_evenement->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)

        //remplissage tableau avec le masque
        ui->table_evenement->setModel(proxy_evenement);
}


//************************ metiers


//recherche dynamique
void gestion_eventicket::on_evenement_sel_col_currentIndexChanged(const QString &arg1)
{
    sel_col_evenement=ui->evenement_sel_col->currentIndex()-1;
    proxy_evenement->setFilterKeyColumn(sel_col_evenement);                                                        // chercher dans tout le tableau (-1) ou donner le numero de la colone
}
void gestion_eventicket::on_rech_evenement_textChanged(const QString &arg1)
{
    proxy_evenement->setFilterFixedString(arg1);
}


/*********************************** ticket ****************************/

//************************ crud

//ajout
void gestion_eventicket::on_actionadd_ticket_triggered()
{
    //creation instance
        add_ticket ac(this);

        //ouvrir dialog
        int res=ac.exec();
        if (res == QDialog::Rejected )
            return;


      //recuperation des donnees
        QString s1=ac.id();
        QString s2=ac.type();
        QString s3=ac.prix();
        QString s4=ac.heure();
        QString x=ac.date_t();


        //ajout
        ticket mc(s1,s2,s3,x,s4);
        mc.ajouter();

        //refresh du tableau (affichage)
          show_ticket();
}


//selection
void gestion_eventicket::on_table_ticket_clicked(const QModelIndex &index)
{
    selected_ticket=ui->table_ticket->model()->data(index).toString();
}

//modification
void gestion_eventicket::on_table_ticket_doubleClicked(const QModelIndex &index)
{
    add_ticket ac(this);

  ac.fill_form(selected_ticket);
  int res=ac.exec();
  if (res == QDialog::Rejected )
    return;

  //recuperation des donnees
  QString s2=ac.type();
  QString s3=ac.prix();
  QString s4=ac.heure();
 QString x=ac.date_t();

    //mofication
    ticket mc(selected_ticket,s2,s3,x,s4);
    mc.modifier(selected_ticket);

    //refresh du tableau (affichage)
    show_ticket();

}


//suppression
void gestion_eventicket::on_actiondelete_ticket_triggered()
{
    ticket mc;
  mc.supprimer(selected_ticket);

 //refresh du tableau (affichage)
  show_ticket();
}

//affichage
void gestion_eventicket::show_ticket()
{
    //creation model (masque du tableau) : permet recherche et tri
        proxy_ticket = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_ticket->setSourceModel(tmp_ticket.afficher());

     //pour la recherche
        proxy_ticket->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)

        //remplissage tableau avec le masque
        ui->table_ticket->setModel(proxy_ticket);
}


//************************ metiers

//recherche dynamique
void gestion_eventicket::on_ticket_sel_col_currentIndexChanged(const QString &arg1)
{
    sel_col_ticket=ui->ticket_sel_col->currentIndex()-1;
    proxy_ticket->setFilterKeyColumn(sel_col_ticket); // chercher dans tout le tableau (-1) ou donner le numero de la colone

}
void gestion_eventicket::on_rech_ticket_textChanged(const QString &arg1)
{
    proxy_ticket->setFilterFixedString(arg1);
}

//     imprimer
void gestion_eventicket::on_pushButton_2_clicked()
{
        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->table_ticket->model()->rowCount();
        const int columnCount =ui->table_ticket->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (ui->table_ticket->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->table_ticket->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->table_ticket->isColumnHidden(column)) {
                    QString data = ui->table_ticket->model()->data(ui->table_ticket->model()->index(row, column)).toString().simplified();
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

        delete document;
}


void gestion_eventicket::on_stats_clicked()
{
    QSound::play("C:/Users/ALPHA/Desktop/qt_projets/aaaaa/sound/button.wav");

    statsmo S;
            S.statistique_P();
            S.setModal(true);
            S.exec();


}

void gestion_eventicket::on_video_clicked()
{
    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* vw = new QVideoWidget;

   player ->setVideoOutput(vw);
   player ->setMedia(QUrl::fromLocalFile("C:/Users/ALPHA/Desktop/qt_projets/integration2/aa.mpg"));
   vw -> setGeometry(100,100,300,400);
   vw-> show();
   player->play();
   qDebug() << player ->state();

}

void gestion_eventicket::on_pushButton_clicked()
{

        Smtp* smtp = new Smtp("pastryplus1@gmail.com",ui->mail_pass_2->text(), "smtp.gmail.com");
          connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
              smtp->sendMail("pastryplus1@gmail.com", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->text());



}

void gestion_eventicket::on_pushButton_3_clicked()
{
     QSound::play("C:/Users/ALPHA/Desktop/qt_projets/integration2/images/button-30.wav");
    hide();
}
