#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QPushButton>

class Boton : public QPushButton
{
    Q_OBJECT
public:
    enum Color{Azul=1, Verde=2, Magenta=4, Purpura=8, Acqua=16, Violeta=32, PurpuraOscuro=64};
    explicit Boton(QWidget *parent = nullptr, Color color=Azul);
    void colorear(Color color);
private:
    Color color;
protected:
    void paintEvent(QPaintEvent *) override;
signals:
    void signal_clic();
};

#endif // BOTON_H
