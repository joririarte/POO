#include "login.h"
#include "ui_login.h"
#include "admindb.h"
#include <QDebug>

Login::Login(QWidget *parent) : QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    this->ui->leUsuario->setFocus();

    connect(this->ui->pbIngresar, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));
    connect(this->ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
    connect(this->ui->lRegistrarse, SIGNAL(signal_pressed()), this, SIGNAL(signal_registrarUsuario()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validarUsuario()
{
    QStringList response = AdminDB::getInstancia()->validarUsuario(this->ui->leUsuario->text(),this->ui->leClave->text());
    if(!response.empty()){
        this->ui->leUsuario->setText("");
        this->ui->leClave->setText("");
        this->ui->leUsuario->setFocus();
        emit signal_usuarioValidado(response[0] + " " + response[1]);
    }
    else{
        this->ui->leClave->setText("");
    }
}
