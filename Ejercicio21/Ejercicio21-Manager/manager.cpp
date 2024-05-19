#include "manager.h"
#include "login.h"
#include "ventana.h"

Manager::Manager(QObject *parent) : QObject(parent), login(new Login()), ventana(new Ventana())
{
    connect(this->login, SIGNAL(signal_ingresar()), this->ventana, SLOT(show()));
    connect(this->ventana, SIGNAL(signal_volver()), this->login, SLOT(show()));
}

void Manager::iniciar()
{
    this->login->show();
}
