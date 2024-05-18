#ifndef HTMLFETCHER_H
#define HTMLFETCHER_H

#include <QObject>

class HtmlFetcher : public QObject
{
    Q_OBJECT
public:
    explicit HtmlFetcher(QObject *parent = nullptr);
    class QNetworkAccessManager* manager;
    void getHtml(QString url);
private slots:
    void slot_urlFetched( class QNetworkReply*);

signals:
    void signal_htmlReady(QString);
};

#endif // HTMLFETCHER_H
