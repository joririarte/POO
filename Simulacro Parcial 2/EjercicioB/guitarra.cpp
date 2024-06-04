#include "guitarra.h"
#include <QDebug>

Guitarra::Guitarra(std::string marca, int precio, int cantidad_de_cuerdas) : Instrumento("Guitarra", marca, precio), cantidad_de_cuerdas(cantidad_de_cuerdas)
{

}

void Guitarra::setCuerdas(int cuerdas)
{
    this->cantidad_de_cuerdas = cuerdas;
}

int Guitarra::getCuerdas() const
{
    return this->cantidad_de_cuerdas;
}

void Guitarra::afinar()
{
    qDebug() << "Afinando guitarra";
}
