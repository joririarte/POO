#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

class Login;
class Ventana;

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    void iniciar();
private:
    Login* login;
    Ventana* ventana;
};

#endif // MANAGER_H
