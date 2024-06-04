#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H
#include <string>

class Instrumento
{
public:
    Instrumento(std::string tipo, std::string marca, int precio);

    virtual void afinar() = 0;

    std::string getMarca() const;
    void setMarca(std::string marca);

    void setPrecio(int precio);
    int getPrecio() const ;

    std::string getTipo() const;
    void setTipo(std::string tipo);

protected:
    std::string marca;
    int precio;
    std::string tipo;
};

#endif // INSTRUMENTO_H
