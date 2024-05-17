#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;
    class Formulario* formulario;
    class RegistroUsuario* registro;
    class WeatherFetcher* clima;
    class ImageFetcher* bkgImageFetcher;
    class QImage bkgImage;
    class AdminDB* database;
    class QHash<QString, int> intentosPorUsuario;
    class QTimer* temporizador;
    class QHash<QString, class QTime> tiempoRestantePorUsuario;
    bool estaBloqueado(QString usuario);
    friend class RegistroUsuario;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slot_validarUsuario();
    void slot_publicarClima(QString);
    void slot_publicarImagen(QImage);
    void slot_actualizarTiempo();
    void slot_registrarse();
signals:
    void signal_usuarioValidado(QString usuario);
};
#endif // LOGIN_H
