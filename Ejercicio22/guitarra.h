#ifndef GUITARRA_H
#define GUITARRA_H
#include "instrumento.h"

class Guitarra : public Instrumento
{
public:
    Guitarra();
    virtual std::string sonar() override;
    void setCuerdas(int);
    int getCuerdas() const;
private:
    int cuerdas;
};

#endif // GUITARRA_H
