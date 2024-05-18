#include "ventana.h"
#include "ui_ventana.h"
#include "imagefetcher.h"
#include <QPainter>

Ventana::Ventana(QWidget *parent) : QWidget(parent), ui(new Ui::Ventana)
{
    this->ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);

    this->imgFetcher = new ImageFetcher(this);
    imgFetcher->getImage("https://wallpapercave.com/wp/wp9096542.jpg");

    connect(this->imgFetcher, SIGNAL(signal_imagenLista(QImage)), this, SLOT(slot_publicarImagen(QImage)));
}

Ventana::~Ventana()
{
    delete this->ui;
}

void Ventana::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!imgFondo.isNull()){
        painter.drawImage(0,0,imgFondo.scaled(this->width(),this->height(),Qt::KeepAspectRatioByExpanding));
    }
}

void Ventana::slot_publicarImagen(QImage imgDescargada)
{
    this->imgFondo = imgDescargada;
    this->repaint();
    emit signal_imagenLista();
}
