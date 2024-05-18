#ifndef IMAGEFETCHER_H
#define IMAGEFETCHER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPainter>
#include <QImage>

class ImageFetcher : public QObject
{
    Q_OBJECT
public:
    explicit ImageFetcher(QObject *parent = nullptr);
    void getImage(QString url);
    void getImageFromApi(QString url);
private:
    QImage image;
    QNetworkAccessManager* manager, *apiManager;
private slots:
    void slot_imagenLista(QNetworkReply*);
    void slot_apiResponse(QNetworkReply*);
    void slot_downloadProgress(qint64,qint64);

signals:
    void signal_imagenLista(QImage);

};

#endif // IMAGEFETCHER_H
