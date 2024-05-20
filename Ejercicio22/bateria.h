#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento
{
public:
    Bateria();
    virtual std::string sonar() override;
    void setTambores(int);
    int getTambores() const;
private:
    int tambores;
};

#endif // BATERIA_H
