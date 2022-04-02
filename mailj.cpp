#include "mailj.h"
#include "ui_mailj.h"
#include "smtp2.h"

mailj::mailj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mailj)
{
    ui->setupUi(this);
}

mailj::~mailj()
{
    delete ui;
}

void mailj::on_pushButton_clicked()
{
    Smtp3* smtp = new Smtp3("pastryplus1@gmail.com",ui->mail_pass_2->text(), "smtp.gmail.com");
      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


          smtp->sendMail3("pastryplus1@gmail.com", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->text());
}

void mailj::on_pushButton_2_clicked()
{
    hide();
}
