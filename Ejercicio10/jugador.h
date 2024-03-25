#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

class Jugador
{
private:
    int velocidad;
    int fuerza;
    std::string nombre;

public:
    //Constructors
    Jugador();
    Jugador(int velocidad, int fuerza, std::string nombre) : velocidad(velocidad), fuerza(fuerza), nombre(nombre){}

    //Getters & Setters
    int GetVelocidad() const;
    void SetVelocidad(int velocidad);

    int GetFuerza() const;
    void SetFuerza(int fuerza);

    std::string GetNombre() const;
    void SetNombre(std::string nombre);
};

#endif // JUGADOR_H
