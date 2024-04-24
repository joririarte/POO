#include "login.h"
#include "editor.h"
#include "ui_login.h"

Login::Login(QWidget *parent) : QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    this->ui->leUsuario->setFocus();
    connect(this->ui->pbValidar, SIGNAL(pressed()), this, SLOT( slot_validarUsuario() ));
    connect(this->ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validarUsuario()
{
    if(this->ui->leUsuario->text() == "admin" && this->ui->leClave->text() == "123"){
        //Do Stuff
        this->edit = new Editor();
        edit->show();
        this->hide();
    }
    else{
        this->ui->leClave->clear();
    }
}

