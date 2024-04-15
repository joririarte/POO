#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

class Ventana : public QWidget{
    Q_OBJECT
private:
    class QGroupBox *group;
    class QLabel *lDiametro, *lVelocidad;
    class QLineEdit *leDiametro, *leVelocidad;
    class QPushButton *pbActualizarBola;
    class QVBoxLayout* vblMainVerticalLayout;
    class QHBoxLayout* hblHorizontalLayout;
    class QPixmap* pixBallPixmap;
    class QGraphicsScene* gsScene;
    class QGraphicsView* gvView;
    class BouncingBall* bbBall;
    class QTimer* tTimer;
public:
    Ventana();
private slots:
    void onActualizarPressed();
};

#endif // VENTANA_H
