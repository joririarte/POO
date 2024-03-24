#ifndef PERSONA_H
#define PERSONA_H
#include <string>


class Persona
{
private:
    std::string nombre;
    int edad;

public:
    // Constructor
    Persona();
    Persona(const std::string& n, int e) : nombre(n), edad(e) {}

    // Método para obtener el nombre
    std::string getNombre() const { return nombre; }

    // Método para obtener la edad
    int getEdad() const { return edad; }

    std::string Descripcion();
};

#endif // PERSONA_H
