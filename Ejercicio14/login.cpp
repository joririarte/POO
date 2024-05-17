#include "login.h"
#include "ui_login.h"
#include "formulario.h"
#include "weatherfetcher.h"
#include "imagefetcher.h"
#include "admindb.h"
#include "registrousuario.h"
#include <QPainter>
#include <QImage>
#include <QHash>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QDebug>

Login::Login(QWidget *parent) : QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->leUsuario->setFocus();

    clima = new WeatherFetcher();
    clima->fetchWeather();

    bkgImageFetcher = new ImageFetcher();
    bkgImageFetcher->getImage("https://apod.nasa.gov/apod/image/2405/WrightDobbs_Georgia_Aurora_2.jpg");
    //bkgImageFetcher->getImageFromApi("https://api.nasa.gov/planetary/apod?api_key=mKhH47B5v6JrXlFeFmB04Qp5rVbqzsOXV9AbADrG");

    temporizador = new QTimer(this);
    temporizador->start(1000);

    database = new AdminDB(this);
    qDebug()<<"Database status: "<<database->conectar("../Ejercicio14/db.sqlite");

    //Conexiones
    connect(this->ui->pbValidar, SIGNAL(pressed()),this,SLOT(slot_validarUsuario()));
    connect(this->ui->leClave, SIGNAL(returnPressed()),this,SLOT(slot_validarUsuario()));
    connect(this->clima,SIGNAL(signal_temperaturaLista(QString)),this,SLOT(slot_publicarClima(QString)));
    connect(this->bkgImageFetcher,SIGNAL(signal_imagenLista(QImage)),this,SLOT(slot_publicarImagen(QImage)));
    connect(this->temporizador,SIGNAL(timeout()),this,SLOT(slot_actualizarTiempo()));
    connect(this->ui->pbRegistrarse,SIGNAL(pressed()),this,SLOT(slot_registrarse()));
}

Login::~Login()
{
    delete ui;
}

bool Login::estaBloqueado(QString usuario)
{
    if(intentosPorUsuario.contains(usuario)){
        return intentosPorUsuario.value(usuario) >= 3;
    }
    return false;
}

void Login::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!bkgImage.isNull()){
        painter.drawImage(0,0,bkgImage.scaled(this->width(),this->height()));
    }
}

void Login::slot_validarUsuario(){
    QString usuario = this->ui->leUsuario->text();
    if(!estaBloqueado(usuario) && !database->validarUsuario(usuario,this->ui->leClave->text()).empty()){
        //Algo
        intentosPorUsuario.insert(usuario,0);
        formulario = new Formulario();
        formulario->show();
        this->hide();
        emit signal_usuarioValidado(usuario);
    }
    else if(!estaBloqueado(usuario)){
        intentosPorUsuario.insert(usuario, intentosPorUsuario.value(usuario) + 1);
        QMessageBox::warning(this,"Credenciales Incorrectas!", usuario + " le quedan " +
                             QString::number(3 - intentosPorUsuario.value(usuario)) +
                             " intentos.");
        this->ui->leClave->setText("");
    }
    else {
        if(!tiempoRestantePorUsuario.contains(usuario))
            tiempoRestantePorUsuario.insert(usuario, QTime(0,5,0));
        QMessageBox::warning(this,
                             "Usuario Bloqueado!",
                             usuario + " vuelve a intentar en: " + tiempoRestantePorUsuario.value(usuario).toString("m:ss") + " minutos.");
        this->ui->leClave->setText("");
    }
}

void Login::slot_publicarClima(QString clima)
{
    this->ui->lClima->setText(clima);
}

void Login::slot_publicarImagen(QImage img)
{
    bkgImage = img;
    qDebug()<<"Signal Image ready received";
    this->show();
}

void Login::slot_actualizarTiempo()
{
    Q_FOREACH(const QString &clave, tiempoRestantePorUsuario.keys()){
        tiempoRestantePorUsuario.insert(clave, tiempoRestantePorUsuario.value(clave).addSecs(-1));
        qDebug()<<"Actualizando Tiempo de " << clave << tiempoRestantePorUsuario.value(clave).toString("m:ss");
    }
}

void Login::slot_registrarse()
{
    registro = new RegistroUsuario();
    registro->setCaller(this);
    registro->show();
    this->hide();
}


