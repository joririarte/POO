#include "login.h"
#include "ui_login.h"
#include "weatherfetcher.h"
#include "imagefetcher.h"
#include "admindb.h"
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
    bkgImageFetcher->getImageFromApi("https://api.nasa.gov/planetary/apod?api_key=mKhH47B5v6JrXlFeFmB04Qp5rVbqzsOXV9AbADrG");


    database = new AdminDB(this);
    qDebug()<<"Database status: "<<database->conectar("../Ejercicio23/db.sqlite");

    //Conexiones
    connect(this->ui->pbValidar, SIGNAL(pressed()),this,SLOT(slot_validarUsuario()));
    connect(this->ui->leClave, SIGNAL(returnPressed()),this,SLOT(slot_validarUsuario()));
    connect(this->clima,SIGNAL(signal_temperaturaLista(QString)),this,SLOT(slot_publicarClima(QString)));
    connect(this->bkgImageFetcher,SIGNAL(signal_imagenLista(QImage)),this,SLOT(slot_publicarImagen(QImage)));
}

Login::~Login()
{
    delete ui;
}

void Login::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    if(!bkgImage.isNull()){
        painter.drawImage(0,0,bkgImage.scaled(this->width(),this->height()));
    }
}

void Login::slot_validarUsuario(){
    QStringList respuesta = database->validarUsuario(this->ui->leUsuario->text(),this->ui->leClave->text());
    loggedUser = respuesta.join(" ");
    if(!respuesta.empty() ){
        emit signal_usuarioValidado();
    }
}

void Login::slot_publicarClima(QString clima)
{
    this->ui->lClima->setText(clima);
}

void Login::slot_publicarImagen(QImage img)
{
    bkgImage = img;
    this->repaint();
    emit signal_imgLista();
}


