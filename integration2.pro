QT       += core gui sql printsupport network
QT       += multimedia
QT       += core gui
QT       +=serialport
QT       +=multimediawidgets charts


CONFIG += console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG   += resources_big

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
    achats.cpp \
    add_evenement.cpp \
    add_ticket.cpp \
    arduino_a.cpp \
    arduino_p_i.cpp \
    cam.cpp \
    client.cpp \
    clients_achats.cpp \
    comm_achats.cpp \
    conge.cpp \
    connexion.cpp \
    employe.cpp \
    evenement.cpp \
    eventicket.cpp \
    exportexcelobject.cpp \
    exportexcelobjectr.cpp \
    fournisseur.cpp \
    gestion_eventicket.cpp \
    ingredient.cpp \
    login.cpp \
    mailj.cpp \
    main.cpp \
    integr2.cpp \
    mainwindow.cpp \
    mainwindowj.cpp \
    mainwindowr.cpp \
    notifications.cpp \
    produit.cpp \
    produit_ingredient.cpp \
    qcustomplot.cpp \
    secdialog.cpp \
    sheet.cpp \
    smtp.cpp \
    smtp2.cpp \
    stats.cpp \
    statscy.cpp \
    statsmo.cpp \
    statsr.cpp \
    stmp.cpp \
    ticket.cpp \
    toulbar.cpp

HEADERS += \
    achats.h \
    add_evenement.h \
    add_ticket.h \
    arduino_a.h \
    arduino_p_i.h \
    cam.h \
    client.h \
    clients_achats.h \
    comm_achats.h \
    conge.h \
    connexion.h \
    employe.h \
    evenement.h \
    eventicket.h \
    exportexcelobject.h \
    exportexcelobjectr.h \
    fournisseur.h \
    gestion_eventicket.h \
    ingredient.h \
    integr2.h \
    login.h \
    mailj.h \
    mainwindow.h \
    mainwindowj.h \
    mainwindowr.h \
    notifications.h \
    produit.h \
    produit_ingredient.h \
    qcustomplot.h \
    secdialog.h \
    smtp.h \
    smtp2.h \
    stats.h \
    statscy.h \
    statsmo.h \
    statsr.h \
    stmp.h \
    ticket.h \
    toulbar.h

FORMS += \
    Cam.ui \
    add_evenement.ui \
    add_ticket.ui \
    clients_achats.ui \
    eventicket.ui \
    gestion_eventicket.ui \
    integr2.ui \
    login.ui \
    mailj.ui \
    mainwindow.ui \
    mainwindowj.ui \
    mainwindowr.ui \
    produit_ingredient.ui \
    secdialog.ui \
    stats.ui \
    statscy.ui \
    statsmo.ui \
    statsr.ui \
    toulbar.ui
QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/release/ -lSMTPEmail
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/ -lSMTPEmail
else:unix: LIBS += -L$$PWD/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/ -lSMTPEmail

INCLUDEPATH += $$PWD/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug
DEPENDPATH += $$PWD/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug

DISTFILES += \
    Toolery.qss \
    integration2.pro.user

RESOURCES += \
    integr.qrc
