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

private:
    Ui::RegistroUsuario *ui;
private slots:
    void slot_registarUsuario();
    void slot_mostrarClave();
signals:
    void signal_usuarioRegistrado();
};

#endif // REGISTROUSUARIO_H
