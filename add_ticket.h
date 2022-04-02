#ifndef ADD_TICKET_H
#define ADD_TICKET_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class add_ticket;
}

class add_ticket : public QDialog
{
    Q_OBJECT

public:
    explicit add_ticket(QWidget *parent = nullptr);
    ~add_ticket();


    QString date_t() const;
    QString heure() const;
    QString prix() const;
    QString type() const;
    QString id() const ;



    void fill_form(QString);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::add_ticket *ui;
};

#endif // ADD_TICKET_H
