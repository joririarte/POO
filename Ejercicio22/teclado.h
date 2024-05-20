#ifndef TECLADO_H
#define TECLADO_H
#include "instrumento.h"
#include "electrico.h"

class Teclado : public Instrumento, public Electrico
{
public:
    Teclado();
    virtual std::string sonar() override;
    void setTeclas(int);
    int getTeclas() const;
private:
    int teclas;
};

#endif // TECLADO_H
