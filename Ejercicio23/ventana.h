#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;
    void setLabelText(QString);
    friend class Manager;
    void crearPersonajes();
    QVector<class Character*> personajes;
private slots:
    void slot_publicarPersonajes();
};
#endif // VENTANA_H
