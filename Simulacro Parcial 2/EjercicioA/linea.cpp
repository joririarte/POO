#include "linea.h"

Linea::Linea(int x_inicial, int y_inicial, int x_final, int y_final) :  x_inicial(x_inicial),
                                                                        y_inicial(y_inicial),
                                                                        x_final(x_final),
                                                                        y_final(y_final)
{

}

void Linea::setInicio(int x, int y)
{
    x_inicial = x;
    y_inicial = y;
}

void Linea::setFinal(int x, int y)
{
    x_final = x;
    y_final = y;
}

QPoint Linea::getInicio() const
{
    return QPoint(x_inicial, y_inicial);
}

QPoint Linea::getFinal() const
{
    return QPoint(x_final, y_final);
}
