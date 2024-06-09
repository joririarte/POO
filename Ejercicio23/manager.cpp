#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent), login(new Login), ventana(new Ventana)
{
    connect(this->login, SIGNAL(signal_usuarioValidado()),this, SLOT(slot_abrirVentana()));
}

void Manager::iniciar()
{
    connect(this->login,SIGNAL(signal_imgLista()),this->login,SLOT(show()));
}

void Manager::slot_abrirVentana()
{
    this->login->hide();
    this->ventana->show();
    this->ventana->setLabelText(this->login->loggedUser);
}
