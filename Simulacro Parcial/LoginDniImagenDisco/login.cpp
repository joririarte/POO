#include "login.h"
#include "ui_login.h"
#include "ventana.h"

Login::Login(QWidget *parent) : QWidget(parent), ui(new Ui::Login), intentos(0)
{
    ui->setupUi(this);
    ui->leUsuario->setFocus();
    connect(this->ui->pbValidar, SIGNAL(pressed()), this, SLOT(validarUsuario()));
    connect(this->ui->leClave, SIGNAL(returnPressed()), this, SLOT(validarUsuario()));
}

Login::~Login()
{
    delete ui;
}

void Login::validarUsuario()
{
    if(++intentos >= 3) this->close();
    //obtengo los ultimos 3 numeros del dni
    QString user = this->ui->leUsuario->text().right(3);
    QString clave = this->ui->leClave->text();

    if(user == clave){
        ventana = new Ventana();
        ventana->show();
        this->hide();
    }
    else{
        this->ui->leClave->setText("");
    }

}

