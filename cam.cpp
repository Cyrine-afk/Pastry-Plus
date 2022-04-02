#include "cam.h"
#include "ui_Cam.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QDebug>


Cam::Cam(QWidget *parent) :
    QDialog(parent)
    , ui (new Ui::Cam)
{
    ui->setupUi(this);
    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture (mCamera, this);
    mLayout = new QVBoxLayout;
    mOpciconesMenu = new QMenu("Options", this);
    mApagarAction = new QAction("Eteindre", this);
    mCapturarAction = new QAction("Prendre une photo", this);

    mOpciconesMenu->addActions({mEncenderAction, mApagarAction, mCapturarAction});

    ui->opcionesPushButton->setMenu(mOpciconesMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);

    connect (mEncenderAction, &QAction::triggered, [&] () {

    } );
    connect (mApagarAction, &QAction::triggered, [&]() {
        auto filename = QFileDialog::getSaveFileName(this, "Capturer", "/", "Imagen (*.jpg;*.jpeg;)");
        if (filename.isEmpty()) {
            return ;
        }
        mCameraImageCapture->setCaptureDestination(
                    QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEnconderSettings;
        imageEnconderSettings.setCodec("image/jpeg");
        imageEnconderSettings.setResolution(1600, 1200);
        mCameraImageCapture->setEncodingSettings(imageEnconderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    } );
    connect (mCapturarAction, &QAction::triggered, [&] () {

    } );


}

Cam::~Cam () {
    delete ui;
}

