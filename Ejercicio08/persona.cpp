#include "persona.h"

Persona::Persona()
{

}

std::string Persona::Descripcion()
{
    return "Me llamo " + this->nombre
           + " y mi edad es " + std::to_string(this->edad);
}
