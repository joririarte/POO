// Barra.cpp

#include "barra.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>

Barra::Barra(QWidget* parent) : QProgressBar(parent)
{
    setMinimum(0);
    setMaximum(100);
    setValue(0);
    // Estilo personalizado para la barra de progreso
    setStyleSheet("QProgressBar {"
                  "    border: 1px solid #ccc;"
                  "    border-radius: 5px;"
                  "    text-align: center;"
                  "}"
                  "QProgressBar::chunk {"
                  "    background-color: #0074D9;"
                  "    width: 10px;"
                  "}");
}

Barra::~Barra()
{
    // Limpieza (si es necesario)
}

void Barra::actualizarBarra(qint64 recibido, qint64 total)
{
    this->setValue((recibido/total)*100);
}
