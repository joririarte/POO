#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

class Ventana : public QWidget
{
    Q_OBJECT
private:
    class QImage* imagen;
protected:
    void paintEvent(QPaintEvent *event) override;
public:
    explicit Ventana(QWidget *parent = nullptr);

signals:

};

#endif // VENTANA_H
