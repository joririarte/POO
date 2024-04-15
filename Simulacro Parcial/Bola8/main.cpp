/*
 * Ejercicio E
 * Definir la clase Ventana que herede de QWidget
 * Usar desde el disco una imagen de una bola 8 con formato PNG (para usar transparencias).
 * Ventana tendrá un QGroupBox con los siguientes parámetros:
 * Diámetro de la bola (en píxeles)
 * Velocidad (segundos para ir de lado a lado)
 * QPushButton para actualizar estos parámetros en la bola
 * La bola irá golpeando de izquierda a derecha en la Ventana.
*/
#include <QApplication>
#include "ventana.h"

int main(int argc, char** argv){
    QApplication app(argc, argv);
    Ventana v;
    v.show();
    return app.exec();
}
