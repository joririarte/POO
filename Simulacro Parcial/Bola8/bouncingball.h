#ifndef BOUNCINGBALL_H
#define BOUNCINGBALL_H

#include <QGraphicsPixmapItem>

class BouncingBall : public QGraphicsPixmapItem {
public:
    BouncingBall(QGraphicsScene* scene, const QPixmap &pixmap);
    void advance(int step);
    void setDiameter(int newDiameter);
    void setVelocity(qreal newVelocity);

private:
    int diameter;
    qreal velocity;
    qreal dx;
};

#endif // BOUNCINGBALL_H
