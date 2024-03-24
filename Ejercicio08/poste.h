#ifndef POSTE_H
#define POSTE_H
#include <iostream>
#include <string>

class Poste
{
private:
    int altura;
    int seccion;

public:
    Poste();
    Poste( int altura, int seccion );

    void getDatos( int & altura, int & seccion );
    void setDatos( int altura, int seccion );
    std::string Descripcion();
};

#endif // POSTE_H
