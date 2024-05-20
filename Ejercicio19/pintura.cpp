#include "pintura.h"
#include <QPainter>

//constructor
Pintura::Pintura(QWidget *parent) : QWidget(parent) {
    setAttribute(Qt::WA_StaticContents);//StaticContents sirve para dibujos estaticos como los de este proyecto
    painting = false;//bandera para saber si se esta pintando o no
    myPenWidth = 1;//ancho del lapiz
    myPenColor = Qt::black;//color del lapiz
    image = QImage(size(), QImage::Format_RGB32);//image sera el canvas sbre el que se va a pintar
    image.fill(Qt::white);//pinta el canvas de blanco
}

//setea el color del lapiz
void Pintura::setPenColor(const QColor &newColor) {
    myPenColor = newColor;
}

//setea el ancho del lapiz
void Pintura::setPenWidth(int newWidth) {
    myPenWidth = newWidth;
}

//evento de presion de boton
void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {//verifica si se presiona el click izquierdo
        lastPoint = event->pos();//asigna a lastPoint la posicion actual del mouse
        painting = true;//la bandera de pintando pasa a true
    }
}

//evento de movimiento del mouse
void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && painting)//verifica si se esta presionando el click izquierdo y si se esta pintando
        drawLineTo(event->pos());//llama a dibujar una linea hasta la posicion actual
}

//evento de soltar el boton
void Pintura::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && painting) {//verifica si se levanta el click izquierdo y si se esta pintando
        drawLineTo(event->pos());//llama a dibujar una linea hasta la posicion actual
        painting = false;//setea la bandera de dibujando en falso
    }
}

//evento de pintar
void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);

//    QImage im;
//    QPainter painter_sobre_im(&im);
//    painter_sobre_im.drawLine(0,0, 8, 8);
}

void Pintura::wheelEvent(QWheelEvent *event)
{
    // Ajusta el ancho del pincel basado en la dirección del scroll
    // Cada 'tick' del scroll es usualmente 120
    myPenWidth += event->angleDelta().y() / 120;
    if (myPenWidth < 1)
        myPenWidth = 1;

    event->accept();
}

void Pintura::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_R:
            setPenColor(Qt::red);
            break;
        case Qt::Key_G:
            setPenColor(Qt::green);
            break;
        case Qt::Key_B:
            setPenColor(Qt::blue);
            break;
        case Qt::Key_Escape:
            image.fill(Qt::white);
            update();
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}

void Pintura::drawLineTo(const QPoint &endPoint) {
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor,
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
