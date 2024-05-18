#include "login.h"
#include "ui_login.h"
#include "imagefetcher.h"
#include "ventana.h"
#include <QPainter>

Login::Login(QWidget *parent): QWidget(parent), ui(new Ui::Login)
{
    this->ui->setupUi(this);
    this->ui->leUsuario->setFocus();

    this->imageFetcher = new ImageFetcher(this);
    //imageFetcher->getImage("");
    imageFetcher->getImageFromApi("https://api.nasa.gov/planetary/apod?api_key=mKhH47B5v6JrXlFeFmB04Qp5rVbqzsOXV9AbADrG");

    connect(this->ui->pbValidar, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));
    connect(this->ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
    connect(this->imageFetcher, SIGNAL(signal_imagenLista(QImage)), this, SLOT(slot_publicarImagen(QImage)));
}

Login::~Login()
{
    delete ui;
}

void Login::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!this->imgFondo.isNull()){
        painter.drawImage(0,0,imgFondo.scaled(this->width(),this->height(),Qt::KeepAspectRatioByExpanding));
    }
}

void Login::slot_validarUsuario()
{
    if( this->ui->leUsuario->text() == "admin" &&
        this->ui->leClave->text()   == "1234" ){
        //abrir ventana cuando esté lista la imagen
        ventana = new Ventana();
        connect(this->ventana, SIGNAL(signal_imagenLista()), this->ventana, SLOT(show()));
        connect(this->ventana, SIGNAL(signal_imagenLista()), this, SLOT(hide()));
    }
}

void Login::slot_publicarImagen(QImage imgDescargada)
{
    this->imgFondo = imgDescargada;
    this->repaint();
}

