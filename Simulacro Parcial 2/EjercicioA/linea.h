#ifndef LINEA_H
#define LINEA_H

#include <QPoint>
class Linea
{
public:
    Linea(int x_inicial=0, int y_inicial=0, int x_final=0, int y_final=0);
private:
    int x_inicial, x_final, y_inicial, y_final;
public:
    void setInicio(int x, int y);
    void setFinal(int x, int y);
    QPoint getInicio() const;
    QPoint getFinal() const;
};

#endif // LINEA_H
