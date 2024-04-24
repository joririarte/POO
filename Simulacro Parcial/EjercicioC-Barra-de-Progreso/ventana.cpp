// Ventana.cpp

#include "ventana.h"
#include "barra.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMessageBox>


Ventana::Ventana(QWidget* parent): QWidget(parent)
{
    // Configura la ventana
    setWindowTitle("Descarga de Archivos");

    // Crea los widgets
    urlLineEdit = new QLineEdit(this);
    downloadButton = new QPushButton("Descargar", this);
    progressBar = new Barra(this);

    // Diseño de la ventana
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(urlLineEdit);
    layout->addWidget(downloadButton);
    layout->addWidget(progressBar);
    setLayout(layout);

    // Conecta el botón a la función de inicio de descarga
    connect(downloadButton, SIGNAL(pressed()), this, SLOT(startDownload()));
}

Ventana::~Ventana()
{
    // Limpieza (si es necesario)
}

void Ventana::startDownload()
{
    // Obtiene la URL ingresada en el QLineEdit
    QString url = urlLineEdit->text();

    // Inicia la descarga (reemplaza con tu lógica de descarga)
    // Aquí deberías usar la clase Barra para mostrar el progreso
    // Ejemplo: progressBar->startDownload(url);

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(descargaFinalizada(QNetworkReply*)));
    QNetworkReply* reply = manager->get(QNetworkRequest(QUrl(url)));
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),progressBar,SLOT(actualizarBarra(qint64,qint64)));
}

void Ventana::descargaFinalizada(QNetworkReply *)
{
    QMessageBox::warning(this,"FIN!", "Descarga Finalizada");
}
