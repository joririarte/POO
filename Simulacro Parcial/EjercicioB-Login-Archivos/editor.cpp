// editor.cpp

#include "editor.h"
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


Editor::Editor(QWidget *parent) : QWidget(parent)
{
    // Crear los widgets
    teEditorDeTexto = new QTextEdit();
    lePatronDeBusqueda = new QLineEdit();
    pbBuscar = new QPushButton("Buscar");
    lResultado = new QLabel("Coincidencias: 0");
    leNombreDeArchivo = new QLineEdit();
    pbGuardar = new QPushButton("Guardar");

    // layout patron de busqueda
    QHBoxLayout *layout = new QHBoxLayout; // Crea un QHBoxLayout
    layout->addWidget(lePatronDeBusqueda);
    layout->addWidget(pbBuscar);
    layout->addWidget(lResultado);

    // layout guardar archivo
    QHBoxLayout *layout2 = new QHBoxLayout; // Crea un QHBoxLayout
    layout2->addWidget(leNombreDeArchivo);
    layout2->addWidget(pbGuardar);


    // Configurar el diseño vertical
    QVBoxLayout *mainLayout = new QVBoxLayout; // Crea un QVBoxLayout
    mainLayout->addLayout(layout); // Agrega el layout del patron de busqueda
    mainLayout->addWidget(teEditorDeTexto);// agrega el editor
    mainLayout->addLayout(layout2);//agrega el layout guardar archivo
    setLayout(mainLayout);


    // Conectar la señal del botón a una ranura (slot) para procesar la búsqueda
    connect(this->pbBuscar, SIGNAL(pressed()), this, SLOT(buscar_coincidencias()));
    connect(this->lePatronDeBusqueda, SIGNAL(returnPressed()), this, SLOT(buscar_coincidencias()));

    // Conectar la señal del botón a una ranura (slot) para gaurdar archivo
    connect(this->pbGuardar, SIGNAL(pressed()), this, SLOT(guardar_texto()));
    connect(this->leNombreDeArchivo, SIGNAL(returnPressed()), this, SLOT(guardar_texto()));
}

Editor::~Editor()
{
    // Liberar memoria
    delete teEditorDeTexto;
    delete lePatronDeBusqueda;
    delete pbBuscar;
    delete lResultado;
    delete pbGuardar;
    delete leNombreDeArchivo;
}

void Editor::buscar_coincidencias()
{
    //busqueda de coincidencias
    QString coincidencias = QString::number(this->teEditorDeTexto->toPlainText().count(this->lePatronDeBusqueda->text()));
    this->lResultado->setText("Coincidencias: " + coincidencias);
}

void Editor::guardar_texto()
{
    //chequeo la extension del nombre de archivo sino la agrego
    QString nombreArchivo = this->leNombreDeArchivo->text().contains(".txt") ? leNombreDeArchivo->text() : leNombreDeArchivo->text()+".txt";

    //apertura y escritura de archivo
    QFile archivo(nombreArchivo);
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&archivo);
        out << this->teEditorDeTexto->toPlainText();
        archivo.close();
        QMessageBox::warning(this,"Exito!","Se guardó el archivo con éxito");
    }
    else {
        QMessageBox::warning(this,"Error!","No se pudo abrir el archivo para escritura!");
    }
}
