#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

class Ventana;

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    void iniciar();
private:
    Ventana* ventana;
private slots:
    void slot_validarUsuario(QString,QString);
};

#endif // MANAGER_H
