#include "downloader.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QNetworkRequest>
#include <QDebug>

Downloader::Downloader(QObject *parent)
    : QObject(parent), file(nullptr), reply(nullptr), totalDownloads(0), downloadsCompleted(0)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_downloadReady(QNetworkReply*)));
}

void Downloader::download(const QString &url, const QString &outPath)
{
    if (!url.isEmpty() && !outPath.isEmpty()) {
        downloadQueue.enqueue(qMakePair(url, outPath)); // Agregar a la cola
        totalDownloads++;
        startDownloads();
        emit globalDownloadProgress(downloadsCompleted, totalDownloads);
    } else {
        qDebug() << "Invalid URL or output path.";
    }
}

void Downloader::startDownloads()
{
    if (!reply) {
        startNextDownload(); // Iniciar la descarga si no hay descargas en progreso
    }
}

void Downloader::startNextDownload()
{
    if (downloadQueue.isEmpty()) {
        return; // No hay más descargas en la cola
    }

    auto nextDownload = downloadQueue.dequeue(); // Obtener el siguiente par URL, ruta de salida
    QString url = nextDownload.first;
    outputPath = nextDownload.second;

    reply = manager->get(QNetworkRequest(QUrl(url)));
    connect(reply, SIGNAL(readyRead()), this, SLOT(slot_onReadyRead()));
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(slot_downloadProgress(qint64,qint64)));
    emit downloadStarted();
    emit currentDownloadURL(url);
}

void Downloader::slot_onReadyRead()
{
    if (!file) {
        file = new QFile(outputPath);
        if (!file->open(QIODevice::WriteOnly)) {
            qDebug() << "Could not open file for writing:" << outputPath;
            reply->abort();
            return;
        }
    }
    file->write(reply->readAll());
}

void Downloader::slot_downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    emit downloadProgress(bytesReceived, bytesTotal);
}

void Downloader::slot_downloadReady(QNetworkReply *dwReply)
{
    if (file) {
        if (dwReply->error()) {
            qDebug() << "Download failed:" << dwReply->errorString();
            file->remove();
        } else {
            qDebug() << "Download succeeded.";
        }
        file->close();
        delete file;
        file = nullptr;
    }

    dwReply->deleteLater();
    reply->deleteLater();
    reply = nullptr;

    downloadsCompleted++;
    emit downloadFinished();
    emit globalDownloadProgress(downloadsCompleted, totalDownloads);

    // Iniciar la siguiente descarga en la cola
    startNextDownload();
}
