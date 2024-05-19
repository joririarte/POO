#include "ventana.h"
#include "ui_ventana.h"
#include "login.h"

Ventana::Ventana(QWidget *parent) : QWidget(parent), ui(new Ui::Ventana)
{
    this->ui->setupUi(this);
    connect(this->ui->pbVolver,SIGNAL(pressed()),this,SLOT(slot_volver()));
}

Ventana::~Ventana()
{
    delete this->ui;
}

void Ventana::slot_volver()
{
    this->close();
    emit signal_volver();
}
