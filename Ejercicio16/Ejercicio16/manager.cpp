#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{
    login = new Login();
    ventana = new Ventana;
    connect(login, SIGNAL(signal_usuarioValidado(QString)),this,SLOT(slot_abrirVentana(QString)));
}

void Manager::iniciar()
{
    login->show();
}

void Manager::slot_abrirVentana(QString texto)
{
    ventana->slot_setLabelText(texto);
    ventana->show();
}
