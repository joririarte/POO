#ifndef TECLADO_H
#define TECLADO_H
#include "instrumento.h"

class Teclado : public Instrumento
{
public:
    Teclado(std::string marca, int precio, int cantidad_de_teclas);
    virtual void afinar() override;
    void setTeclas(int);
    int getTeclas() const;
private:
    int cantidad_de_teclas;
};

#endif // TECLADO_H
