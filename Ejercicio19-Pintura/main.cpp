#include "pintura.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Pintura ventanaPrincipal;
    ventanaPrincipal.show();
    return app.exec();
}
