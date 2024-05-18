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
    QImage imgFondo;
    class ImageFetcher* imageFetcher;
    class Ventana* ventana;
protected:
    void paintEvent(QPaintEvent *event) override;
private slots:
    void slot_validarUsuario();
    void slot_publicarImagen(QImage);
};
#endif // LOGIN_H
