#ifndef CLIENTS_ACHATS_H
#define CLIENTS_ACHATS_H

#include <QDialog>
#include "client.h"
#include "achats.h"
#include "stmp.h"
#include "arduino_a.h"
#include <QFileDialog>
namespace Ui {
class Clients_Achats;
void refreshw();
}

class Clients_Achats : public QDialog
{
    Q_OBJECT

public:
 int cl=0;
    int xx=0;
    QString point3="";

     void refreshw();
     void calcul_prix();
     void music(int ,int ,int);
    explicit Clients_Achats(QWidget *parent = nullptr);
    ~Clients_Achats();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_11_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_comboBox_p_currentIndexChanged(const QString &arg1);

    void on_pushButton_15_clicked();




    void on_pushButton_16_clicked();

private:
    Ui::Clients_Achats *ui;
    client c;
    achat a;
    QStringList files;
    arduino_a A;
};

#endif // CLIENTS_ACHATS_H
