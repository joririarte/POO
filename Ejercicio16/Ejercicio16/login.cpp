#include "login.h"
#include "ui_login.h"
#include <QNetworkReply>
#include <QMessageBox>

Login::Login(QWidget *parent): QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    this->ui->leUsuario->setFocus();
    manager = new QNetworkAccessManager(this);
    connect(this->ui->pbIngresar,SIGNAL(pressed()),this, SLOT(slot_validarUsuario()));
    connect(this->ui->leClave,SIGNAL(returnPressed()),this,SLOT(slot_validarUsuario()));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_apiResponse(QNetworkReply*)));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validarUsuario()
{
    QString usuario= this->ui->leUsuario->text();
    QString clave= this->ui->leClave->text();
    if(!usuario.isEmpty() && !clave.isEmpty()){
        QByteArray arr;
        manager->post(QNetworkRequest(QUrl("http://127.0.0.1:8000/consultar/usuario=" + usuario + "&clave=" + clave)), arr);
    }
}

void Login::slot_apiResponse(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response_data = reply->readAll();
        QString response_string(response_data);
        //QMessageBox::information(nullptr,"Response",response_string);
        emit signal_usuarioValidado(response_string);
    }
    else{
        QMessageBox::critical(nullptr,"Error",reply->errorString());
    }
    reply->deleteLater();
}

