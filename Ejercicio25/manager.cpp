#include "manager.h"
#include "admindb.h"
#include <QDebug>

Manager::Manager(QObject *parent) : QObject(parent), login(new Login), registro(new RegistroUsuario)
{
    qDebug() << "Base de datos: " << AdminDB::getInstancia()->conectar("../Ejercicio25/usuarios.sqlite");
    this->usuarios = new Ventana;
    connect(this->login, SIGNAL(signal_usuarioValidado(QString)), this, SLOT(slot_usuarioValidado(QString)));
    connect(this->login, SIGNAL(signal_registrarUsuario()), this, SLOT(slot_registrarUsuario()));
    connect(this->registro, SIGNAL(signal_usuarioRegistrado()), this, SLOT(slot_volverALogin()));
    connect(this->usuarios, SIGNAL(signal_volver()), this, SLOT(slot_volverALogin()));
}

void Manager::iniciar()
{
    this->login->show();
}

void Manager::slot_usuarioValidado(QString user)
{
    this->login->hide();
    this->usuarios->setUser(user);
    this->usuarios->updateTreeWidget();
    this->usuarios->show();
}

void Manager::slot_registrarUsuario()
{
    this->login->hide();
    this->registro->show();
}

void Manager::slot_volverALogin()
{
    QWidget* sender = qobject_cast<QWidget*>(this->sender());
    sender->close();
    this->login->show();
}
