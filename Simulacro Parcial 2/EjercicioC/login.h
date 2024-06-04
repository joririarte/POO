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
    ~Login();
    static Login *getInstance();

private:
    Ui::Login *ui;
    static Login* instance;
    Login(QWidget *parent = nullptr);

private slots:
    void slot_solicitarValidacion();
signals:
    void signal_ingresar();
    void signal_solicitarValidacion(QString, QString);
};
#endif // LOGIN_H
