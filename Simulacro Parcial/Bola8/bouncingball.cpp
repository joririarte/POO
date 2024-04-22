#include "bouncingball.h"
#include <QGraphicsScene>

BouncingBall::BouncingBall(QGraphicsScene* scene, const QPixmap &pixmap)
    : diameter(512), velocity(-2), dx(velocity) {
    QImage image;
    // Escalar el QPixmap antes de pasarlo al constructor base
    QPixmap scaledPixmap = pixmap.scaled(diameter, diameter);
    setPixmap(scaledPixmap);

    // Establecer la posición inicial de la bola
    setPos(scene->width() / 2 - diameter / 2, scene->height() / 2 - diameter / 2);
}

void BouncingBall::advance(int step) {
    if (!step)
        return;

    // Mover la bola
    moveBy(dx, 0);

    // Rebotar en los bordes izquierdo y derecho
    if (x() + pixmap().width() >= scene()->width() || x() <= 0) {
        dx = -dx; // Cambiar la dirección
    }
}

void BouncingBall::setDiameter(int newDiameter) {
    diameter = newDiameter;
    setPixmap(pixmap().scaled(diameter, diameter));
}

void BouncingBall::setVelocity(qreal newVelocity) {
    dx = (dx > 0 ? newVelocity : -newVelocity);
}
