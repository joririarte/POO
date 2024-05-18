#include "htmlfetcher.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>

HtmlFetcher::HtmlFetcher(QObject *parent) : QObject(parent)
{
    this->manager = new QNetworkAccessManager(this);
    connect(this->manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_urlFetched(QNetworkReply*)));
}

void HtmlFetcher::getHtml(QString url)
{
    if(url != ""){
       manager->get(QNetworkRequest(QUrl(url)));
    }
}

void HtmlFetcher::slot_urlFetched(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        QString html = QString::fromUtf8(reply->readAll());
        emit signal_htmlReady(html);
    }
}
