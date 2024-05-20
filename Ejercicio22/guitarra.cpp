#include "guitarra.h"

Guitarra::Guitarra() : cuerdas(6)
{

}

std::string Guitarra::sonar()
{
    return "Guitarra suena...";
}

void Guitarra::setCuerdas(int cuerdas)
{
    this->cuerdas = cuerdas;
}

int Guitarra::getCuerdas() const
{
    return this->cuerdas;
}
