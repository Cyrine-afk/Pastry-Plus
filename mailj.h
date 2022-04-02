#ifndef MAILJ_H
#define MAILJ_H

#include <QDialog>

namespace Ui {
class mailj;
}

class mailj : public QDialog
{
    Q_OBJECT

public:
    explicit mailj(QWidget *parent = nullptr);
    ~mailj();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::mailj *ui;
};

#endif // MAILJ_H
