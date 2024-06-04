#include "viento.h"
#include <QDebug>

Viento::Viento(std::string marca, int precio, std::string metal_usado) : Instrumento("Viento", marca, precio), metal_usado(metal_usado)
{

}

void Viento::setMetalUsado(std::string metal_usado)
{
    this->metal_usado = metal_usado;
}

std::string Viento::getMetalUsado()
{
    return this->metal_usado;
}

void Viento::afinar()
{
    qDebug() << "Afinando Viento...";
}
