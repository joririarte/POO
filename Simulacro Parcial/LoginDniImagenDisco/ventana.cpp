#include "ventana.h"
#include <QPainter>
#include <QImage>
#include <QDebug>



void Ventana::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!imagen->isNull()){
        int x = (this->width() - imagen->width())/2;
        int y = (this->height() - imagen->height())/2;
        painter.drawImage(x,y, *imagen);
        painter.setPen(QPen(Qt::black, 2));
        painter.drawRect(x-3,y-3, imagen->width()+6,imagen->height()+6);
    }
}

Ventana::Ventana(QWidget *parent) : QWidget(parent)
{
    QString ruta = "../LoginA/alonso.jpg";
    imagen = new QImage();
    imagen->load(ruta);
    *imagen = imagen->scaledToWidth(300);
}
