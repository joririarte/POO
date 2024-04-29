#include "pintura.h"
#include <QPainter>

Pintura::Pintura(QWidget *parent) : QWidget(parent) {
    setAttribute(Qt::WA_StaticContents);
    painting = false;
    myPenWidth = 1;
    myPenColor = Qt::black;
    image = QImage(size(), QImage::Format_RGB32);
    image.fill(Qt::white);
}

void Pintura::setPenColor(const QColor &newColor) {
    myPenColor = newColor;
}

void Pintura::setPenWidth(int newWidth) {
    myPenWidth = newWidth;
}

void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        painting = true;
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && painting)
        drawLineTo(event->pos());
}

void Pintura::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && painting) {
        drawLineTo(event->pos());
        painting = false;
    }
}

void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void Pintura::wheelEvent(QWheelEvent *event)
{
    // Ajusta el ancho del pincel basado en la dirección del scroll
    myPenWidth += event->angleDelta().y() / 120; // Cada 'tick' del scroll es usualmente 120
    if (myPenWidth < 1)
        myPenWidth = 1; // El ancho mínimo del pincel es 1

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
