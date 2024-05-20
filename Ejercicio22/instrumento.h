#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H
#include <string>

class Instrumento
{
public:
    Instrumento();
    virtual std::string sonar()=0;
    virtual std::string verlo();
    void setMarca(std::string marca);
protected:
    std::string marca;
};

#endif // INSTRUMENTO_H
