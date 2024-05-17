#ifndef REGISTROUSUARIO_H
#define REGISTROUSUARIO_H

#include <QWidget>

namespace Ui {
class RegistroUsuario;
}

class RegistroUsuario : public QWidget
{
    Q_OBJECT

public:
    explicit RegistroUsuario(QWidget *parent = nullptr);
    ~RegistroUsuario();
    void setCaller(QWidget* widget);

private:
    Ui::RegistroUsuario *ui;
    class AdminDB* database;
    class Login* caller;
private slots:
    void slot_registarUsuario();
    void slot_mostrarClave();
};

#endif // REGISTROUSUARIO_H
