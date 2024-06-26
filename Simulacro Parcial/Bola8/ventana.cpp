#include "ventana.h"
#include "bouncingball.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

Ventana::Ventana()
{
    lVelocidad = new QLabel("Velocidad");
    lDiametro = new QLabel("Diametro");
    leVelocidad = new QLineEdit;
    leDiametro = new QLineEdit;
    pbActualizarBola = new QPushButton("Actualizar");
    connect(pbActualizarBola,SIGNAL(pressed()),this,SLOT(onActualizarPressed()));

    vblMainVerticalLayout = new QVBoxLayout(this);
    hblHorizontalLayout = new QHBoxLayout();

    hblHorizontalLayout->addWidget(lVelocidad);
    hblHorizontalLayout->addWidget(leVelocidad);
    hblHorizontalLayout->addWidget(lDiametro);
    hblHorizontalLayout->addWidget(leDiametro);
    hblHorizontalLayout->addWidget(pbActualizarBola);

    vblMainVerticalLayout->addLayout(hblHorizontalLayout);

    pixBallPixmap = new QPixmap("bola8.png");
    gsScene = new QGraphicsScene;

    gsScene->setSceneRect(0,0,800,600);

    gvView = new QGraphicsView(gsScene);
    gvView->setRenderHint(QPainter::SmoothPixmapTransform);

    bbBall = new BouncingBall(gsScene,*pixBallPixmap);
    gsScene->addItem(bbBall);

    bbBall->setDiameter(150);
    bbBall->setVelocity(4);

    tTimer = new QTimer;

    connect(tTimer,SIGNAL(timeout()),gsScene,SLOT(advance()));
    tTimer->start(1000/60);

    vblMainVerticalLayout->addWidget(gvView);

}

void Ventana::onActualizarPressed()
{
    bbBall->setDiameter(leDiametro->text().toInt());
    bbBall->setVelocity(leVelocidad->text().toInt());
}
