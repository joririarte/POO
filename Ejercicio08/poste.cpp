#include "poste.h"

Poste::Poste(){
    this->altura = 0;
    this->seccion = 0;
}

Poste::Poste( int altura, int seccion ) : altura( altura ), seccion( seccion )  {

}

void Poste::getDatos( int & altura, int & seccion )  {
    altura = this->altura;
    seccion = this->seccion;
}

void Poste::setDatos( int altura, int seccion )  {
    this->altura = altura;
    this->seccion = seccion;
}

std::string Poste::Descripcion()
{
    return "Poste con altura " + std::to_string(this->altura)
           + " metros y " + std::to_string(this->seccion)
           + " cm de diametro.-";
}
