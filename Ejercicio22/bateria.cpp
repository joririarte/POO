#include "bateria.h"

Bateria::Bateria() : tambores(5)
{

}
std::string Bateria::sonar()
{
    return "Bateria suena...";
}

void Bateria::setTambores(int tambores)
{
    this->tambores = tambores;
}

int Bateria::getTambores() const
{
    return this->tambores;
}
