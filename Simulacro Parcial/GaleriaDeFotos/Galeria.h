#ifndef GALLERYWIDGET_H
#define GALLERYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Galeria : public QWidget {
    Q_OBJECT
private:
    QLabel *lImagen;
    QVector<QString> qvLinksImagenes;
    void loadImage(int index);
    int indiceDeImagenActual;
    void loadImageUrlsFromFile(const QString &filePath);

public:
    Galeria();

private slots:
    void loadPreviousImage();
    void loadNextImage();
    void setImage(QNetworkReply *reply);
};

#endif // GALLERYWIDGET_H
