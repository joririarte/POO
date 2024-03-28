#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Crear un objeto QLabel
    QLabel label;

    // Cargar la imagen desde un archivo JPG
    QPixmap image("C:/Users/jor_i/OneDrive/Fotos/Imágenes guardadas/volkswagen-polo-wrc-rally-4324-556570af738de.jpg");
    label.setPixmap(image);
    label.setScaledContents(true);
    // Mostrar el QLabel maximizado
    label.showMaximized();

    // Configurar un temporizador para cerrar la aplicación después de 3 segundos
    QTimer::singleShot(3000, &a, SLOT(quit()));

    return a.exec();
}
