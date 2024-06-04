#ifndef VIENTO_H
#define VIENTO_H
#include "instrumento.h"


class Viento : public Instrumento
{
public:
    Viento(std::string marca, int precio, std::string metal_usado);
    void setMetalUsado(std::string);
    std::string getMetalUsado();
    void afinar() override;
private:
    std::string metal_usado;
};

#endif // VIENTO_H
