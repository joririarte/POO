#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();
    void setCaller(class Login*);

private:
    Ui::Ventana *ui;
    Login* login;
private slots:
    void slot_volver();
};

#endif // VENTANA_H
