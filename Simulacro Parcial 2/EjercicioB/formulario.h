#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QVector>
#include "instrumento.h"
#include "guitarra.h"
#include "teclado.h"
#include "viento.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Formulario; }
QT_END_NAMESPACE

class Formulario : public QWidget
{
    Q_OBJECT

public:
    Formulario(QWidget *parent = nullptr);
    ~Formulario();

private:
    Ui::Formulario *ui;
    QVector<Instrumento*> instrumentos;
    void resetInputs();
private slots:
    void slot_cambiarInfoAdicional(QString info);
    void slot_agregarInstrumento();
    void slot_verStock();
};
#endif // FORMULARIO_H
