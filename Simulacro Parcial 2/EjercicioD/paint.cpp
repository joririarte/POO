#include "paint.h"
#include "ui_paint.h"

Paint::Paint(QWidget *parent) : QWidget(parent), ui(new Ui::Paint)
{
    ui->setupUi(this);
    QStringList items;
    items << "Fino" << "Mediano" << "Grueso";
    this->ui->cbTrazo->addItems(items);
    this->ui->cbTrazo->setCurrentIndex(0);

    connect(this->ui->cbTrazo,SIGNAL(currentTextChanged(QString)),this, SLOT(slot_cambiarTrazo(QString)));
    connect(this->ui->lBorrar,SIGNAL(signal_pressed()),this,SLOT(slot_borrarPintura()));
}

Paint::~Paint()
{
    delete ui;
}

void Paint::slot_cambiarTrazo(QString trazo)
{
    if(trazo == "Fino"){
        this->ui->lienzo->seleccionarTrazo(Lienzo::TrazoFino);
    }
    else if(trazo == "Mediano"){
        this->ui->lienzo->seleccionarTrazo(Lienzo::TrazoMediano);
    }
    else{
        this->ui->lienzo->seleccionarTrazo(Lienzo::TrazoGrueso);
    }
}

void Paint::slot_borrarPintura()
{
    this->ui->lienzo->borrar();
}
