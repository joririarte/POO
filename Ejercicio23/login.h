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
    class WeatherFetcher* clima;
    class ImageFetcher* bkgImageFetcher;
    class QImage bkgImage;
    class AdminDB* database;
    QString loggedUser;
    friend class Manager;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slot_validarUsuario();
    void slot_publicarClima(QString);
    void slot_publicarImagen(QImage);
signals:
    void signal_usuarioValidado();
    void signal_imgLista();
};
#endif // LOGIN_H
