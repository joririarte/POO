#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>

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
    QNetworkAccessManager* manager;
private slots:
    void slot_validarUsuario();
    void slot_apiResponse(QNetworkReply*);
signals:
    void signal_usuarioValidado(QString);
};
#endif // LOGIN_H
