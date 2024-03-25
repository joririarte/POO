#include "jugador.h"

Jugador::Jugador()
{
    this->velocidad = 0;
    this->fuerza    = 0;
    this->nombre    = "sin nombre";
}

int Jugador::GetVelocidad() const
{
    return this->velocidad;
}

void Jugador::SetVelocidad(int velocidad)
{
    this->velocidad = velocidad;
}

int Jugador::GetFuerza() const
{
    return this->fuerza;
}

void Jugador::SetFuerza(int fuerza)
{
    this->fuerza = fuerza;
}

std::string Jugador::GetNombre() const
{
    return this->nombre;
}

void Jugador::SetNombre(std::string nombre)
{
    this->nombre = nombre;
}
