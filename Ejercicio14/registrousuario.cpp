#include "registrousuario.h"
#include "ui_registrousuario.h"
#include "admindb.h"
#include "login.h"
#include <QDebug>
#include <QMessageBox>

RegistroUsuario::RegistroUsuario(QWidget *parent) : QWidget(parent), ui(new Ui::RegistroUsuario)
{
    ui->setupUi(this);
    ui->leUsuario->setFocus();
    connect(this->ui->pbRegistrarse,SIGNAL(pressed()),this,SLOT(slot_registarUsuario()));
    connect(this->ui->pbMostrarClave, SIGNAL(pressed()),this, SLOT(slot_mostrarClave()));
}

RegistroUsuario::~RegistroUsuario()
{
    delete ui;
}

void RegistroUsuario::setCaller(QWidget *widget)
{
    this->caller = (Login*)widget;
}

void RegistroUsuario::slot_registarUsuario()
{
    if(this->caller->database->insertarUsuario( this->ui->leUsuario->text(),
                                                this->ui->leClave->text(),
                                                this->ui->leNombre->text(),
                                                this->ui->leApellido->text(),
                                                this->ui->leMail->text()
                                                )){
        QMessageBox::information(this,"Registro Exitoso","Usted se ha registrado con éxito!");
        this->close();
    }
    this->caller->show();

}

void RegistroUsuario::slot_mostrarClave()
{
    if(this->ui->leClave->echoMode() != QLineEdit::Password)
        this->ui->leClave->setEchoMode(QLineEdit::Password);
    else
        this->ui->leClave->setEchoMode(QLineEdit::Normal);

}
