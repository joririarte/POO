
#ifndef MILABEL_H
#define MILABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>


class MiLabel : public QLabel {
    Q_OBJECT

public:
    MiLabel( QWidget * parent = nullptr );

protected:
    void mousePressEvent( QMouseEvent * e );

signals:
    void signal_pressed();

};


#endif // MILABEL_H
