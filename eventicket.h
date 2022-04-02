#ifndef EVENTICKET_H
#define EVENTICKET_H

#include <QDialog>
#include "evenement.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class eventicket;
}
QT_END_NAMESPACE

class eventicket : public QDialog
{
    Q_OBJECT

public:
     eventicket(QWidget *parent = nullptr);
    ~eventicket();


private slots:

 void on_pushButton_clicked();






private:
    Ui::eventicket *ui;

};

#endif // EVENTICKET_H
