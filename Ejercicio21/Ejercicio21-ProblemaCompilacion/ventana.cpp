#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) : QWidget(parent), ui(new Ui::Ventana)
{
    this->ui->setupUi(this);
}

Ventana::~Ventana()
{
    delete this->ui;
}

void Ventana::setCaller(Login *callerWidget)
{
    this->login = callerWidget;
}

void Ventana::slot_volver()
{
    this->hide();
    login->show();
}
