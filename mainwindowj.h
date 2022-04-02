#ifndef MAINWINDOWJ_H
#define MAINWINDOWJ_H

#include <QMainWindow>
#include <QMainWindow>
#include <QWidget>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <QDebug>
#include <QSqlTableModel>
#include "secdialog.h"
#include "employe.h"
#include <QAbstractItemView>
#include <QRegExp>
#include <QFileDialog>
#include <QSortFilterProxyModel>
#include <QTextDocument>
#include <QPropertyAnimation>
#include <QFileDialog>
#include "notifications.h"
#include <QPropertyAnimation>
#include "connexion.h"
#include "mailj.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowj; }
QT_END_NAMESPACE

class MainWindowj : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowj(QWidget *parent = nullptr);
    ~MainWindowj();
    SecDialog *sec;
    Notifications n;
        QPropertyAnimation *A_ajouterEmploye;

private slots:

    void on_pushButtonAjouterEmploye_clicked();

    void on_pushButtonVider_clicked();

    void on_pushButtonMenu_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonRechercher_clicked();

    void on_pushButtonStats_clicked();

    void on_pushButtonExportPDF_clicked();

    void on_pushButtonPDF_2_clicked();

    void on_pushButtonPDF_clicked();

    void on_pushButtonTrier_clicked();

    void on_ajouter_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonSuppr_clicked();

    void on_pushButtonStatistiques_clicked();

    void on_pushButtonRechercherConge_clicked();

    void on_consulter_conge_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_stat_clicked();

    void on_label_15_linkActivated(const QString &link);

    void on_label_stat_1_linkActivated(const QString &link);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindowj *ui;
   employe tmpemploye;
     //  conge tmpconge;
       QRegExp mail_regex;
       QRegExp nom_regex,tel_regex,salaire_regex, id_regex;
       mailj * mj;

};
#endif // MAINWINDOW_H
