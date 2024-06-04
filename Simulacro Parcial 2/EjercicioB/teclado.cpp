#include "teclado.h"
#include <QDebug>

Teclado::Teclado(std::string marca, int precio, int cantidad_de_teclas):Instrumento("Teclado", marca, precio), cantidad_de_teclas(cantidad_de_teclas)
{

}

void Teclado::afinar()
{
    qDebug() << "Afinando Teclado...";
}

void Teclado::setTeclas(int teclas)
{
    this->cantidad_de_teclas = teclas;
}

int Teclado::getTeclas() const
{
    return this->cantidad_de_teclas;
}
