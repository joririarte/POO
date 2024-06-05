#include "ventana.h"
#include "ui_ventana.h"
#include "downloader.h"
#include <QHash>
#include <QFileDialog>
#include <QDir>
#include <QDebug>


Ventana::Ventana(QWidget *parent): QWidget(parent), ui(new Ui::Ventana)
{
    ui->setupUi(this);
    this->parser = new Parser;
    downloader = new Downloader(this);
    connect(this->ui->pbObtenerRecursos, SIGNAL(pressed()), this, SLOT(slot_obtenerRecursos()));
    connect(this->parser, SIGNAL(signal_recursosReady(QHash<QString, Parser::Tipo> *)), this, SLOT(slot_publicarRecursos(QHash<QString, Parser::Tipo> *)));
    connect(downloader, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(onDownloadProgress(qint64,qint64)));
    connect(downloader, SIGNAL(globalDownloadProgress(int,int)), this, SLOT(onGlobalDownloadProgress(int,int)));
    connect(downloader, SIGNAL(currentDownloadURL(QString)),this, SLOT(slot_updateLabelURL(QString)));
}

Ventana::~Ventana()
{
    delete ui;
}

bool Ventana::createDir(QString path)
{
    QDir dir;

    // Comprueba si el directorio ya existe
    if (!dir.exists(path)) {
        // Crea el directorio
        if (dir.mkpath(path)) {
            qDebug() << "Directory created successfully:" << path;
            return true;
        } else {
            qDebug() << "Failed to create directory:" << path;
        }
    } else {
        qDebug() << "Directory already exists:" << path;
        return true;
    }
    return false;
}

void Ventana::slot_obtenerRecursos()
{
    directorioRecursos = QFileDialog::getExistingDirectory( this,
                                                            "Select Directory",
                                                            QDir::homePath(),
                                                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
                                                            );
    qDebug()<<directorioRecursos;
    if(!this->ui->leURL->text().isEmpty()){
        parser->setOrigen(this->ui->leURL->text());
        parser->getRecursos();
        qDebug()<<"Recurso pedido";
    }
}

void Ventana::slot_publicarRecursos(QHash<QString, Parser::Tipo> * recursos)
{

    if(!recursos->empty()){
        for(const QString recurso : recursos->keys()){

            QString directorioFinal = directorioRecursos;

            switch (recursos->value(recurso)) {
            case Parser::IMAGEN:
                directorioFinal += "/IMAGENES/";
                break;
            case Parser::JAVASCRIPT:
                directorioFinal += "/JAVASCRIPT/";
                break;
            case Parser::CSS:
                directorioFinal += "/CSS/";
                break;
            }
            //hay que hace algo con signal y slots para que una vez que termine la descarga recién siga con otro.
            if(createDir(directorioFinal)){
                qDebug()<< directorioFinal + QUrl(recurso).fileName();
                downloader->download(recurso, directorioFinal + QUrl(recurso).fileName());
            }
        }
    }
}

void Ventana::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    if (bytesTotal > 0) {
        this->ui->pbProgresoRecurso->setMaximum(bytesTotal);
        this->ui->pbProgresoRecurso->setValue(bytesReceived);
    }
}

void Ventana::onGlobalDownloadProgress(int downloadsCompleted, int totalDownloads)
{
    this->ui->lProgresoGlobal->setText(QString("Descargados %1 de %2 recursos").arg(downloadsCompleted).arg(totalDownloads));
}

void Ventana::slot_updateLabelURL(QString currentURL)
{
    this->ui->lRecurso->setText(currentURL);
}

