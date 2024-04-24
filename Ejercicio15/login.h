#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>

class Login : public QWidget
{
    Q_OBJECT
private:
    class QLabel *lUsername, *lPassword;
    class QLineEdit *leUsername, *lePassword;
    class QGridLayout *layout;
    class QPushButton *pbValidate;
    class Formulario* form;
public:
    Login();
private slots:
    void slot_validarUsuario();

};

#endif // LOGIN_H
