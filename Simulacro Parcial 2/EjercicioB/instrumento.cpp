#include "instrumento.h"

Instrumento::Instrumento(std::string tipo, std::string marca, int precio) : tipo(tipo), marca(marca), precio(precio)
{
}

std::string Instrumento::getMarca() const
{
    return this->marca;
}

void Instrumento::setMarca(std::string marca)
{
    this->marca = marca;
}

void Instrumento::setPrecio(int precio)
{
    this->precio = precio;
}

int Instrumento::getPrecio() const
{
    return this->precio;
}

std::string Instrumento::getTipo() const
{
    return this->tipo;
}

void Instrumento::setTipo(std::string tipo)
{
    this->tipo = tipo;
}
