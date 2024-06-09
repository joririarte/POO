#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "login.h"
#include "ventana.h"
#include "registrousuario.h"


class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    void iniciar();

private:
    Login* login;
    Ventana* usuarios;
    RegistroUsuario* registro;


private slots:
    void slot_usuarioValidado(QString);
    void slot_registrarUsuario();
    void slot_volverALogin();

signals:

};

#endif // MANAGER_H
