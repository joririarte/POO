#include "formulario.h"
#include "ui_formulario.h"
#include <QDebug>


Formulario::Formulario(QWidget *parent): QWidget(parent), ui(new Ui::Formulario)
{
    this->ui->setupUi(this);
    this->ui->cbInstrumentos->addItem("Guitarra");
    this->ui->cbInstrumentos->addItem("Teclado");
    this->ui->cbInstrumentos->addItem("Viento");
    resetInputs();

    connect(this->ui->cbInstrumentos, SIGNAL(currentIndexChanged(QString)), this, SLOT(slot_cambiarInfoAdicional(QString)));
    connect(this->ui->pbAgregar, SIGNAL(pressed()), this, SLOT(slot_agregarInstrumento()));
    connect(this->ui->pbVerStock, SIGNAL(pressed()), this, SLOT(slot_verStock()));
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::resetInputs()
{
    this->ui->leMarca->setText("");
    this->ui->lePrecio->setText("");
    this->ui->leInfo->setText("");
    this->ui->cbInstrumentos->setCurrentIndex(0);
    this->ui->cbInstrumentos->setFocus();
}

void Formulario::slot_cambiarInfoAdicional(QString info)
{
    if(info == "Guitarra"){
        this->ui->lInfo->setText("Cantidad de Cuerdas");
    }
    else if (info == "Teclado"){
        this->ui->lInfo->setText("Cantidad de Teclas");
    }
    else if(info == "Viento"){
        this->ui->lInfo->setText("Material Usado");
    }

}

void Formulario::slot_agregarInstrumento()
{
    QString marca = this->ui->leMarca->text();
    QString precio = this->ui->lePrecio->text();
    QString info = this->ui->leInfo->text();
    bool ok;

    if(!marca.isEmpty() &&
       !precio.isEmpty() &&
       !info.isEmpty()){

        if(this->ui->cbInstrumentos->currentText() == "Guitarra"){
            instrumentos.push_back(new Guitarra(marca.toStdString(), precio.toInt(&ok), info.toInt(&ok)));
        }
        else if(this->ui->cbInstrumentos->currentText() == "Teclado"){
            instrumentos.push_back(new Teclado(marca.toStdString(), precio.toUInt(&ok), info.toInt(&ok)));
        }
        else if(this->ui->cbInstrumentos->currentText() == "Viento"){
            instrumentos.push_back(new Viento(marca.toStdString(), precio.toInt(&ok), info.toStdString()));
        }
    }
    resetInputs();
}

void Formulario::slot_verStock()
{
    for(Instrumento* instr : instrumentos){
        qDebug() << "\n######################################\n";
        qDebug() << "Instrumento: " << QString::fromStdString(instr->getTipo());
        qDebug() << "Marca:" << QString::fromStdString(instr->getMarca());
        qDebug() << "Precio:" << instr->getPrecio();
        if( instr->getTipo() == "Guitarra" ){
            qDebug() << "Cantidad de Cuerdas: " << static_cast<Guitarra*>(instr)->getCuerdas();
        }
        else if(instr->getTipo() == "Teclado"){
            qDebug() << "Cantidad de Teclas: " << static_cast<Teclado*>(instr)->getTeclas();
        }
        else if(instr->getTipo() == "Viento"){
            qDebug() << "Metal Usado: " << QString::fromStdString(static_cast<Viento*>(instr)->getMetalUsado());
        }
        qDebug() << "\n######################################\n";
    }
}

