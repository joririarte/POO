#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear objetos
    QWidget widget;
    QLabel label("¡Hola, mundo!");
    QPushButton button("Haz clic");
    QLineEdit lineEdit;

    // Mostrar los objetos
    widget.show();
    label.show();
    button.show();
    lineEdit.show();

    return app.exec();
}
