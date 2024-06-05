#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QQueue>
#include <QPair>

// Forward declarations
class QNetworkAccessManager;
class QNetworkReply;
class QFile;

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);
    void download(const QString &url, const QString &outPath);
    void startDownloads();

signals:
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void globalDownloadProgress(int downloadsCompleted, int totalDownloads);
    void downloadStarted();
    void downloadFinished();
    void currentDownloadURL(QString);

private slots:
    void slot_onReadyRead();
    void slot_downloadReady(QNetworkReply *reply);
    void slot_downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void startNextDownload();

private:
    QFile *file;
    QString outputPath;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QQueue<QPair<QString, QString>> downloadQueue; // Cola de descargas
    int totalDownloads;
    int downloadsCompleted;
};

#endif // DOWNLOADER_H
