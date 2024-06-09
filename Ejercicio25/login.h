#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;

private slots:
    void slot_validarUsuario();

signals:
    void signal_usuarioValidado(QString);
    void signal_registrarUsuario();
};

#endif // LOGIN_H
