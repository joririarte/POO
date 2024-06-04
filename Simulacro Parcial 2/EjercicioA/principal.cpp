#include "principal.h"
#include "ui_principal.h"
#include <QVector>
#include <QPainter>
#include <QDebug>

Principal::Principal(QWidget *parent) : QWidget(parent), ui(new Ui::Principal)
{
    ui->setupUi(this);
    qDebug() << "Conectada: " << AdminDB::getInstance()->conectar("../EjercicioA/lineasDB.sqlite");
    lineas = AdminDB::getInstance()->obtenerLineas();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!lineas.isEmpty()){
        for(Linea l : lineas){
            painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));
            painter.drawLine(l.getInicio(), l.getFinal());
        }
    }
}

