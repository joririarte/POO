#include "instrumento.h"

Instrumento::Instrumento()
{
    this->marca = "Yamaha";
}

std::string Instrumento::verlo()
{
    return this->marca;
}

void Instrumento::setMarca(std::string marca)
{
    this->marca = marca;
}
