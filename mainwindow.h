#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include "fournisseur.h"
#include "connexion.h"
#include "comm_achats.h"
#include "statscy.h"
#include "cam.h"
#include "C:\Users\ALPHA\Desktop\qt_projets\integration2\SmtpClient-for-Qt-1.1\src/SmtpMime"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QCamera;
class QCameraViewFinder;
class QCameraImageCapture;
class QVBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static EmailAddress * stringToEmail(const QString & str);
    void refreshw();
    void afficher();
    void music();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_suppr_f_clicked();

    void on_pushButton_pdf_clicked();

    void on_rech_bouton_returnPressed();

    void on_pushButton_trier_fournisseur_clicked();

    void on_addAttachment_2_clicked();

    void on_sendEmail_2_clicked();

    void errorMessage(const QString & message);
    void on_export_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_mod_com_clicked();

    void on_pushButton_suppr_f_2_clicked();

    void on_imprint_ca_clicked();

    void on_pushButton_trier_comm_clicked();

    void on_rech_bouton_2_returnPressed();

    void on_stats_clicked();

    void on_pushButton_cam_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    fournisseur f;
    QSqlTableModel *model;
    fournisseur tmpfournisseur;
    comm_achats tmpcomma;

    /*QCamera *mCamera;
    QCameraViewFinder *mCameraViewFinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOpciconesMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;*/


};
#endif // MAINWINDOW_H
