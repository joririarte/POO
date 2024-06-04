#ifndef GUITARRA_H
#define GUITARRA_H
#include "instrumento.h"

class Guitarra : public Instrumento
{
public:
    Guitarra(std::string marca, int precio, int cantidad_de_cuerdas);
    void setCuerdas(int);
    int getCuerdas() const;
    void afinar() override;
private:
    int cantidad_de_cuerdas;
};

#endif // GUITARRA_H
