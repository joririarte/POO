#include "imagefetcher.h"
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

ImageFetcher::ImageFetcher(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    apiManager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_imagenLista(QNetworkReply*)));
    connect(apiManager, SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_apiResponse(QNetworkReply*)));
}

//Obtiene una imagen de una url directa
void ImageFetcher::getImage(QString url)
{
    if(url != ""){
        QNetworkReply* reply = manager->get(QNetworkRequest(QUrl(url)));
        connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(slot_downloadProgress(qint64,qint64)));
        qDebug()<<"image request sent";
    }
}

//Obtiene una imagen a traves de una API
void ImageFetcher::getImageFromApi(QString url)
{
    if(url != ""){
        QNetworkReply* reply = apiManager->get(QNetworkRequest(QUrl(url)));
        connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(slot_downloadProgress(qint64,qint64)));
        qDebug()<<"api request sent";
    }
}

void ImageFetcher::slot_imagenLista(QNetworkReply *reply)
{
    image = QImage::fromData(reply->readAll());
    qDebug()<<"emiting signal image ready";
    emit signal_imagenLista(image);
}


void ImageFetcher::slot_apiResponse(QNetworkReply * reply)
{
    if(reply->error()==QNetworkReply::NoError){
        QByteArray response_data = reply->readAll();
        QJsonDocument json = QJsonDocument::fromJson(response_data);
        QJsonObject object = json.object();
        QString imageUrl = object["url"].toString();
        qDebug()<<"getting image from: "<<imageUrl;
        this->getImage(imageUrl);
    }
    else {
        qDebug()<<"Error: "<<reply->errorString();
    }
}

void ImageFetcher::slot_downloadProgress(qint64 actual, qint64 total)
{
    if(total > 0)
        qDebug()<<"Downloaded: " << ((float)actual/total) * 100.f;
    else
        qDebug() << "Unknown total size. Downloading: " << actual;
}
