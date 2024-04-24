#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>

class Login : public QWidget
{
    Q_OBJECT
private:
    class QLabel *lUsername, *lPassword, *lWeather;
    class QLineEdit *leUsername, *lePassword;
    class QGridLayout *layout;
    class QPushButton *pbValidate, *pbShowTemp, *pbShowPassword;
    class Formulario* form;
    class WeatherFetcher* weather;
public:
    Login();
private slots:
    void slot_validarUsuario();
    void slot_publicarTemperatura(QString);
    void slot_mostrarTemp();
    void slot_mostrarPassword();
};

#endif // LOGIN_H
