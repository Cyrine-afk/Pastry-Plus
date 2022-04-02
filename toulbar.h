#ifndef TOULBAR_H
#define TOULBAR_H

#include <QDialog>

namespace Ui {
class ToulBar;
}

class ToulBar : public QDialog
{
    Q_OBJECT

public:
    explicit ToulBar(QWidget *parent = nullptr);

    void afficher(QString);

    ~ToulBar();



private:
    Ui::ToulBar *ui;
};

#endif // TOULBAR_H
