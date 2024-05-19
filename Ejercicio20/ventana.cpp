#include "ventana.h"
#include "ui_ventana.h"
#include <QPainter>


Ventana::Ventana(QWidget *parent): QWidget(parent), ui(new Ui::Ventana)
{
    ui->setupUi(this);
    imgFondo.load("../Ejercicio20/Fondo2.jpg");
    this->ui->pbMiDentista->colorear(Boton::Magenta);
    this->ui->pbVisitas->colorear(Boton::PurpuraOscuro);
    this->ui->pbTecnicasHigiene->colorear(Boton::Purpura);
    this->ui->pbHoraCepillarse->colorear(Boton::Acqua);
    this->ui->pbMiBoca->colorear(Boton::Violeta);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!imgFondo.isNull()){
        painter.drawImage(0,0,imgFondo.scaled(this->width(),this->height(),Qt::KeepAspectRatioByExpanding));
    }
}

