#ifndef GESTION_EVENTICKET_H
#define GESTION_EVENTICKET_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPrintDialog>
#include <QTextStream>


#include "evenement.h"
#include "add_evenement.h"
#include "ticket.h"
#include "add_ticket.h"
#include "statsmo.h"
//#include "arduino.h"


namespace Ui {
class gestion_eventicket;
}

class gestion_eventicket : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_eventicket(QWidget *parent = nullptr);
    ~gestion_eventicket();


    evenement tmp_evenement;
    ticket tmp_ticket;
    QSortFilterProxyModel *proxy_evenement,*proxy_ticket;
    void show_evenement();
    void show_ticket();
    void show_tables();



private slots:
    void on_actionadd_evenement_triggered();

    void on_table_evenement_clicked(const QModelIndex &index);

    void on_table_evenement_doubleClicked(const QModelIndex &index);

    void on_actiondelete_evenement_triggered();

    void on_evenement_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_evenement_textChanged(const QString &arg1);

    void on_actionadd_ticket_triggered();

    void on_table_ticket_clicked(const QModelIndex &index);

    void on_table_ticket_doubleClicked(const QModelIndex &index);

    void on_actiondelete_ticket_triggered();

    void on_ticket_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_ticket_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();



    void on_actionadd_evenement_clicked();

    void on_stats_clicked();

    void on_video_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::gestion_eventicket *ui;
    QString selected_evenement="",selected_ticket="";
    int sel_col_evenement=-1,sel_col_ticket=-1;
    //arduino A;
};

#endif // GESTION_EVENTICKET_H
