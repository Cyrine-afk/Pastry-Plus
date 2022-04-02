#ifndef INTEGR2_H
#define INTEGR2_H

#include <QMainWindow>
#include "mainwindow.h"
#include "gestion_eventicket.h"
#include "clients_achats.h"
#include "mainwindowj.h"
#include "produit_ingredient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class integr2; }
QT_END_NAMESPACE

class integr2 : public QMainWindow
{
    Q_OBJECT

public:
    integr2(QWidget *parent = nullptr);
  void music(int,int,int);
    ~integr2();

private slots:
    void on_pushButton_14_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::integr2 *ui;

    Clients_Achats * c;
    MainWindow * m;
    gestion_eventicket * g;
    MainWindowj * mj;
    Produit_ingredient * pr;


};
#endif // INTEGR2_H
