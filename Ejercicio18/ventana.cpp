#include "ventana.h"
#include "ui_ventana.h"
#include "imagefetcher.h"
#include "htmlfetcher.h"
#include <QPainter>
#include <QDebug>

Ventana::Ventana(QWidget *parent) : QWidget(parent), ui(new Ui::Ventana)
{
    this->ui->setupUi(this);


    this->ui->leURL->setFocus();

    this->imgFetcher = new ImageFetcher(this);
    imgFetcher->getImage("https://wallpapercave.com/wp/wp9096542.jpg");

    connect(this->imgFetcher, SIGNAL(signal_imagenLista(QImage)), this, SLOT(slot_publicarImagen(QImage)));
    connect(this->ui->pbBuscar, SIGNAL(pressed()), this, SLOT(slot_buscarURL()));
    connect(this->ui->leURL, SIGNAL(returnPressed()), this, SLOT(slot_buscarURL()));
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

void Ventana::slot_buscarURL()
{
    htmlFetcher = new HtmlFetcher(this);
    htmlFetcher->getHtml(this->ui->leURL->text());
    connect(this->htmlFetcher, SIGNAL(signal_htmlReady(QString)), this, SLOT(slot_publicarHtml(QString)));
}

void Ventana::slot_publicarHtml(QString html)
{
    if(html != ""){
        this->ui->teHTML->setHtml(html);
    }
}
