/*
 * Ejercicio D
 * Diseñar una aplicación para una galería de fotos
 * En un archivo .txt almacenar en cada línea, una URL a una imagen
 * Un botón >> y otro botón << para avanzar o retroceder en la galería de fotos
*/

#include<QApplication>
#include "Galeria.h"
int main(int argc, char** argv){
    QApplication app(argc,argv);
    Galeria gal;
    gal.show();
    return app.exec();
}
