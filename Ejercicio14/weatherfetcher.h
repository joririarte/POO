#ifndef WEATHERFETCHER_H
#define WEATHERFETCHER_H

#include <QObject>
#include <QNetworkAccessManager>

class WeatherFetcher : public QObject {
    Q_OBJECT
public:
    explicit WeatherFetcher(QObject *parent = nullptr);
    void fetchWeather();

private slots:
    void onFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QString respuesta="Not Set";
signals:
    void signal_temperaturaLista(QString);
};

#endif // WEATHERFETCHER_H
