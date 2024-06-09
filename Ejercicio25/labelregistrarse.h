
#ifndef LABELREGISTRARSE_H
#define LABELREGISTRARSE_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>


class LabelRegistrarse : public QLabel {
    Q_OBJECT

public:
    LabelRegistrarse( QWidget * parent = nullptr );

protected:
    void mousePressEvent( QMouseEvent * e );

signals:
    void signal_pressed();

};


#endif // LABELREGISTRARSE_H
