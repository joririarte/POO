// editor.h

#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class Editor : public QWidget
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);
    ~Editor();

private:
    QTextEdit *teEditorDeTexto;
    QLineEdit *lePatronDeBusqueda, *leNombreDeArchivo;
    QPushButton *pbBuscar, *pbGuardar;
    QLabel *lResultado;
private slots:
    void buscar_coincidencias();
    void guardar_texto();
};

#endif // EDITOR_H
