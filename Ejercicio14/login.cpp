#include "login.h"
#include "formulario.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "weatherfetcher.h"

Login::Login()
{
    this->setWindowTitle("Login");

    lUsername = new QLabel("Usuario");
    lPassword = new QLabel("Contraseña");
    leUsername = new QLineEdit();
    lePassword = new QLineEdit();
    pbValidate = new QPushButton("Iniciar Sesion");
    pbShowTemp = new QPushButton("Ocultar Temperatura");
    pbShowPassword = new QPushButton("Mostrar Contraseña");

    form = new Formulario();

    layout = new QGridLayout();
    weather = new WeatherFetcher();
    weather->fetchWeather();
    lWeather = new QLabel("Not Set");

    layout->addWidget(lUsername, 0, 0, 1, 1);
    layout->addWidget(lPassword, 1, 0, 1, 1);
    layout->addWidget(leUsername, 0, 1, 1, 3);
    layout->addWidget(lePassword, 1, 1, 1, 3);
    layout->addWidget(pbValidate, 2, 2, 1, 1);
    layout->addWidget(pbShowPassword, 2, 3, 1, 1);

    layout->addWidget(lWeather, 3, 0, 1, 1);
    layout->addWidget(pbShowTemp, 3, 1, 1, 1);

    lePassword->setEchoMode(QLineEdit::Password);

    this->setLayout(layout);

    connect(pbValidate, SIGNAL(pressed()), this, SLOT( slot_validarUsuario() ));
    connect(lePassword, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
    connect(weather, SIGNAL(signal_temperaturaLista(QString)), this, SLOT(slot_publicarTemperatura(QString)));
    connect(pbShowTemp, SIGNAL(pressed()), this, SLOT(slot_mostrarTemp()));
    connect(pbShowPassword, SIGNAL(pressed()), this, SLOT(slot_mostrarPassword()));
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

void Login::slot_publicarTemperatura(QString temp){
    lWeather->setText("Temp: "+ temp +"°C");
}
void Login::slot_mostrarTemp(){
    lWeather->setHidden(!lWeather->isHidden());
    if(lWeather->isHidden()){
        pbShowTemp->setText("Mostrar Temperatura");
    }
    else{
        pbShowTemp->setText("Ocultar Temperatura");
    }
}
void Login::slot_mostrarPassword(){
    if(lePassword->echoMode()==QLineEdit::Password){
        lePassword->setEchoMode(QLineEdit::Normal);
        pbShowPassword->setText("Ocultar Contraseña");
    }
    else {
        lePassword->setEchoMode(QLineEdit::Password);
        pbShowPassword->setText("Mostrar Contraseña");
    }
}
