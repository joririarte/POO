#include "Galeria.h"
#include <QFile>
#include <QTextStream>

Galeria::Galeria() {
    indiceDeImagenActual = 0;
    // Layout para los botones y la imagen
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // Botón para la imagen anterior
    QPushButton *previousButton = new QPushButton("<<");
    connect(previousButton, SIGNAL(pressed()), this, SLOT(loadPreviousImage()));
    buttonLayout->addWidget(previousButton);

    // Visor de imagen
    lImagen = new QLabel();
    lImagen->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lImagen->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(lImagen);

    // Botón para la siguiente imagen
    QPushButton *nextButton = new QPushButton(">>");
    connect(nextButton, SIGNAL(pressed()), this, SLOT(loadNextImage()));
    buttonLayout->addWidget(nextButton);

    mainLayout->addLayout(buttonLayout);

    loadImageUrlsFromFile("C:/Users/jiriartechamorro/OneDrive - UNIVERSIDAD BLAS PASCAL/Documentos/3 -TERCERO/POO/GaleriaDeFotos/imagenes.txt");

    // Cargar la primera imagen
    if(!qvLinksImagenes.isEmpty()){
        loadImage(indiceDeImagenActual);
    }
    else{
        lImagen->setText("No se encontraron imagenes");
    }
    this->setMinimumSize(QSize(640,320));
}

void Galeria::loadPreviousImage() {
    if (indiceDeImagenActual > 0) {
        loadImage(--indiceDeImagenActual);
    }
    else{
        indiceDeImagenActual = qvLinksImagenes.size() - 1;
        loadImage(indiceDeImagenActual);
    }
}

void Galeria::loadNextImage() {
    if (indiceDeImagenActual < qvLinksImagenes.size() - 1) {
        loadImage(++indiceDeImagenActual);
    }
    else{
        indiceDeImagenActual = 0;
        loadImage(indiceDeImagenActual);
    }
}

void Galeria::loadImage(int index) {
    indiceDeImagenActual = index;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(setImage(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(qvLinksImagenes[index])));
}

void Galeria::setImage(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray imageData = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(imageData);
        lImagen->setPixmap(pixmap.scaled(lImagen->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    reply->deleteLater();
}

void Galeria::loadImageUrlsFromFile(const QString &filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (!line.isEmpty()) {
                qvLinksImagenes.append(line);
            }
        }
        file.close();
    } else {
        // Manejar el error de apertura del archivo
        qDebug() << "No se pudo abrir el archivo:" << filePath;
    }
}
