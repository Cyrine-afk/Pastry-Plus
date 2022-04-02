#ifndef ADD_EVENEMENT_H
#define ADD_EVENEMENT_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class add_evenement;
}

class add_evenement : public QDialog
{
    Q_OBJECT

public:
    explicit add_evenement(QWidget *parent = nullptr);
    ~add_evenement();

    QString produit() const;
    QString lieu() const;
    QString date_e() const;
    QString nom() const;
    QString id() const ;




    void fill_form(QString);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::add_evenement *ui;
};

#endif // ADD_EVENEMENT_H
