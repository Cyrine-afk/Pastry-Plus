#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H


#include <QSystemTrayIcon>
#include<QString>
class Notifications
{
public:
    Notifications();
    void notifications_ajouteremploye();
    void notifications_ajouterconge();
    void notifications_supprimeremploye();
    void notifications_supprimerconge();
    void notifications_modifieremploye();
    void notifications_modifierconge();

};



#endif // NOTIFICATIONS_H
