#include "login.h"
#include "ui_login.h"

Login* Login::instance = nullptr;

Login::Login(QWidget *parent): QWidget(parent), ui(new Ui::Login)
{
    this->ui->setupUi(this);
    this->ui->leUsuario->setFocus();

    connect(this->ui->pbValidar, SIGNAL(pressed()), this, SLOT(slot_solicitarValidacion()));
    connect(this->ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_solicitarValidacion()));
}

Login::~Login()
{
    delete ui;
}

Login *Login::getInstance()
{
    instance = instance ? instance : new Login();
    return instance;
}

void Login::slot_solicitarValidacion()
{
    emit signal_solicitarValidacion(this->ui->leUsuario->text(),this->ui->leClave->text());
}
