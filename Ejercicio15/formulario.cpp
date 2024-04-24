#include "formulario.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QRandomGenerator>
#include <QMessageBox>

bool Formulario::validarCaptcha()
{
    return lCaptcha->text() == leCaptcha->text();
}

bool Formulario::formularioCompleto()
{
    if(leLegajo     && leLegajo->text()!=""     &&
       leNombre     && leNombre->text()!=""     &&
       leApellido   && leApellido->text()!=""   &&
       leCaptcha    && leCaptcha->text()!=""    ){
        return true;
    }
    return false;
}

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

    gbCaptcha = new QGroupBox("Captcha");
    layoutCaptcha = new QGridLayout();
    lCaptcha = new QLabel(QString::number(QRandomGenerator::global()->bounded(1,10000)));
    leCaptcha = new QLineEdit();

    layoutCaptcha->addWidget(lCaptcha, 0,0,1,1);
    layoutCaptcha->addWidget(leCaptcha, 1,0,1,2);
    gbCaptcha->setLayout(layoutCaptcha);

    layout = new QGridLayout();

    layout->addWidget(lLegajo,      0,0,1,1);
    layout->addWidget(lNombre,      1,0,1,1);
    layout->addWidget(lApellido,    2,0,1,1);
    layout->addWidget(leLegajo,     0,1,1,2);
    layout->addWidget(leNombre,     1,1,1,2);
    layout->addWidget(leApellido,   2,1,1,2);
    layout->addWidget(pbInsert,     3,1,1,1);
    layout->addWidget(gbCaptcha, 3,0);

    this->setLayout(layout);
    connect(pbInsert, SIGNAL(pressed()),this,SLOT(alta_persona()));
}

void Formulario::alta_persona()
{
    if(formularioCompleto()){
        if(validarCaptcha()){
            this->close();
        }
        else{
            QMessageBox::warning(this,"Error","Captcha erróneo");
        }
    }
    else{
        QMessageBox::warning(this,"Atención!", "Debes completar todos los campos, no seas imbécil!");
    }
}
