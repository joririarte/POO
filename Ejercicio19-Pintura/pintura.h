#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPoint>

class Pintura : public QWidget {
    Q_OBJECT

public:
    explicit Pintura(QWidget *parent = nullptr);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;


private:
    void drawLineTo(const QPoint &endPoint);
    bool painting;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
};

#endif // PINTURA_H
