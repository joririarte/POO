#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) : QWidget(parent), ui(new Ui::Ventana)
{
    ui->setupUi(this);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::slot_setLabelText(QString text)
{
    this->ui->lRespuesta->setText(text);
}
