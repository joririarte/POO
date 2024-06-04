#ifndef LIENZO_H
#define LIENZO_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class Lienzo; }
QT_END_NAMESPACE

class Lienzo : public QWidget
{
    Q_OBJECT

public:
    Lienzo(QWidget *parent = nullptr);
    ~Lienzo();
    enum Trazo{TrazoFino, TrazoMediano, TrazoGrueso};
    void seleccionarTrazo(Trazo);
    void borrar();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::Lienzo *ui;
    void drawLineTo(const QPoint &endPoint);
    void setPenWidth(int newWidth);
    bool painting;
    int myPenWidth;
    QImage image;
    QPoint lastPoint;
};
#endif // LIENZO_H
