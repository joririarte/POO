#ifndef FORMULARIO_H
#define FORMULARIO_H
#include <QWidget>

class Formulario : public QWidget
{

private:
    class QLabel  *lLegajo, *lNombre, *lApellido;
    class QLineEdit *leLegajo, *leNombre, *leApellido;
    class QPushButton *pbInsert;
    class QGridLayout *layout;
public:
    Formulario();
};

#endif // FORMULARIO_H
