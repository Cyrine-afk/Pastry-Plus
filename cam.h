#ifndef CAM_H
#define CAM_H

#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class Cam;
}

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

class Cam : public QDialog
{
    Q_OBJECT;

public:
    explicit Cam(QWidget *parent = nullptr);
    ~Cam();
private:
    Ui::Cam *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOpciconesMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;
};

#endif // CAM_H
