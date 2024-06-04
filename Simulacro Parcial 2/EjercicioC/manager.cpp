#include "manager.h"
#include "login.h"
#include "ventana.h"
#include "admindb.h"

Manager::Manager(QObject *parent) : QObject(parent), ventana(new Ventana())
{
    connect(Login::getInstance(), SIGNAL(signal_solicitarValidacion(QString,QString)), this, SLOT(slot_validarUsuario(QString,QString)));
    connect(this->ventana, SIGNAL(signal_volver()), Login::getInstance(), SLOT(show()));
}

void Manager::iniciar()
{
    Login::getInstance()->show();
}

void Manager::slot_validarUsuario(QString usuario, QString clave)
{
    AdminDB::getInstance()->conectar("../EjercicioC/base.sqlite");
    if(!AdminDB::getInstance()->validarUsuario(usuario, clave).empty()){
        Login::getInstance()->hide();
        this->ventana->show();
    }
}
