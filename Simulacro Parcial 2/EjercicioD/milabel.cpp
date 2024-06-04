#include "milabel.h"

MiLabel::MiLabel( QWidget * parent ) : QLabel( parent )  {

}

void MiLabel::mousePressEvent(QMouseEvent *e)  {
    if (e->button() == Qt::LeftButton )
        emit signal_pressed();
}
