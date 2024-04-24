#include "formulario.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

Formulario::Formulario()
{
    this->setWindowTitle("Formulario");

    lLegajo = new QLabel("Legajo");
    lNombre = new QLabel("Nombre");
    lApellido = new QLabel("Apellido");
    leLegajo = new QLineEdit();
    leNombre = new QLineEdit();
    leApellido = new QLineEdit();
    pbInsert = new QPushButton("Alta");

    layout = new QGridLayout();

    layout->addWidget(lLegajo,      0,0,1,1);
    layout->addWidget(lNombre,      1,0,1,1);
    layout->addWidget(lApellido,    2,0,1,1);
    layout->addWidget(leLegajo,     0,1,1,2);
    layout->addWidget(leNombre,     1,1,1,2);
    layout->addWidget(leApellido,   2,1,1,2);
    layout->addWidget(pbInsert,     3,1,1,1);

    this->setLayout(layout);
}
