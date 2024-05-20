#include "electrico.h"
#include <iostream>
Electrico::Electrico() : voltaje(220)
{

}

Electrico::~Electrico()
{
       std::cout<<"Desenchufado";
}
