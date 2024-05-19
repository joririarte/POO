#include "boton.h"
#include <QPainter>

Boton::Boton(QWidget *parent, Color color) : QPushButton(parent), color(color)
{
    this->setMinimumSize(0,45);
}

void Boton::colorear(Color color)
{
    this->color = color;
    this->repaint();
}

void Boton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    switch (color) {
    case Azul:
            painter.fillRect(this->rect(),QColor(0,0,255,200));
        break;
    case Verde:
            painter.fillRect(this->rect(),QColor(0,255,0,200));
        break;
    case Magenta:
            painter.fillRect(this->rect(),QColor(251,22,72,200));
        break;
    case Purpura:
            painter.fillRect(this->rect(),QColor(153,22,136,200));
        break;
    case Violeta:
        painter.fillRect(this->rect(),QColor(105,85,147,200));
        break;
    case Acqua:
        painter.fillRect(this->rect(),QColor(0,181,120,200));
        break;
    case PurpuraOscuro:
        painter.fillRect(this->rect(),QColor(151,37,138,200));
        break;
    }
    painter.setPen(Qt::white);
    painter.setFont(QFont("Ink Free",14,QFont::Bold));
    painter.drawText(rect(), Qt::AlignLeft | Qt::AlignVCenter, this->text());
}
