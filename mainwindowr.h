#ifndef MAINWINDOWR_H
#define MAINWINDOWR_H

#include <QMainWindow>
#include "connexion.h"
#include <QDebug>
#include "produit_ingredient.h"
#include "integr2.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowr; }
QT_END_NAMESPACE

class MainWindowr : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowr(QWidget *parent = nullptr);
    ~MainWindowr();

    QString user() const ;
 //QString userID;
 private slots:
    void on_pushButton_submit_clicked();
signals :
    void sig();

private:
    Ui::MainWindowr *ui;
    QByteArray data;
    QString id;
     int e;
    Produit_ingredient * PI;
     integr2 * i;
};
#endif // MAINWINDOW_H
