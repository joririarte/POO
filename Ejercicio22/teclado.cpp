#include "teclado.h"

Teclado::Teclado() : teclas(61)
{

}
std::string Teclado::sonar()
{
    return "Teclado suena...";
}

void Teclado::setTeclas(int teclas)
{
    this->teclas = teclas;
}

int Teclado::getTeclas() const
{
    return this->teclas;
}
