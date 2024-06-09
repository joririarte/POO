#include "labelregistrarse.h"

LabelRegistrarse::LabelRegistrarse( QWidget * parent ) : QLabel( parent )  {

}

void LabelRegistrarse::mousePressEvent(QMouseEvent *e)  {
    if (e->button() == Qt::LeftButton )
        emit signal_pressed();
}
