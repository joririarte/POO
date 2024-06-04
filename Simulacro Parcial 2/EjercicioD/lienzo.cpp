#include "lienzo.h"
#include "ui_lienzo.h"
#include <QDebug>

Lienzo::Lienzo(QWidget *parent) : QWidget(parent), ui(new Ui::Lienzo)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StaticContents);//StaticContents sirve para dibujos estaticos como los de este proyecto
    setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
    painting = false;//bandera para saber si se esta pintando o no
    myPenWidth = 1;//ancho del lapiz
    image = QImage(size(), QImage::Format_RGB32);//image sera el canvas sbre el que se va a pintar
    image.fill(Qt::white);//pinta el canvas de blanco
}

Lienzo::~Lienzo()
{
    delete ui;
}

void Lienzo::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

void Lienzo::seleccionarTrazo(Lienzo::Trazo trazo)
{
    switch (trazo) {
    case TrazoFino:
        setPenWidth(1);
        break;
    case TrazoMediano:
        setPenWidth(4);
        break;
    case TrazoGrueso:
        setPenWidth(6);
        break;
    }
}

void Lienzo::borrar()
{
    image.fill(Qt::white);
    update();
}

void Lienzo::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void Lienzo::mouseMoveEvent(QMouseEvent *event)
{
    if (painting)//verifica si se esta presionando el click izquierdo y si se esta pintando
        drawLineTo(event->pos());//llama a dibujar una linea hasta la posicion actual
    lastPoint = event->pos();
}

void Lienzo::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_A:
        painting = true;
        break;
    case Qt::Key_D:
        painting = false;
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}

void Lienzo::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(Qt::black,
                        myPenWidth,
                        Qt::SolidLine,
                        Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}
