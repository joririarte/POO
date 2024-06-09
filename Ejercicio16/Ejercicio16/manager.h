#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "login.h"
#include "ventana.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    void iniciar();
private:
    Login* login;
    Ventana* ventana;
private slots:
    void slot_abrirVentana(QString);

signals:

};

#endif // MANAGER_H
