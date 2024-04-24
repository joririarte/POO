#include "login.h"
#include "formulario.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

Login::Login()
{
    this->setWindowTitle("Login");

    lUsername = new QLabel("Usuario");
    lPassword = new QLabel("Contraseña");
    leUsername = new QLineEdit();
    lePassword = new QLineEdit();
    pbValidate = new QPushButton("Iniciar Sesion");

    form = new Formulario();

    layout = new QGridLayout();


    layout->addWidget(lUsername, 0, 0, 1, 1);
    layout->addWidget(lPassword, 1, 0, 1, 1);
    layout->addWidget(leUsername, 0, 1, 1, 3);
    layout->addWidget(lePassword, 1, 1, 1, 3);
    layout->addWidget(pbValidate, 2, 2, 1, 1);

    lePassword->setEchoMode(QLineEdit::Password);

    this->setLayout(layout);

    connect(pbValidate, SIGNAL(pressed()), this, SLOT( slot_validarUsuario() ));
    connect(lePassword, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
}

void Login::slot_validarUsuario(){
    if(leUsername->text() == "admin" && lePassword->text() == "1111"){
        //Do Stuff
        form->show();
        this->hide();
    }
    else{
        lePassword->clear();
    }
}
