#include "weatherfetcher.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>

WeatherFetcher::WeatherFetcher(QObject *parent) : QObject(parent), manager(new QNetworkAccessManager(this)) {
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onFinished(QNetworkReply*)));
}

void WeatherFetcher::fetchWeather() {
    QUrl url("http://api.weatherapi.com/v1/current.json?key=ca9f3b777e174eadb9d212652240804&q=Cordoba&aqi=no");
    QNetworkRequest request(url);
    manager->get(request);
}

void WeatherFetcher::onFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response_data = reply->readAll();
        QJsonDocument json = QJsonDocument::fromJson(response_data);
        QJsonObject object = json.object();

        //Localidad
        QJsonObject locationJSON = object["location"].toObject();
        QString location = locationJSON["name"].toString();

        //Temperatura
        QJsonObject current = object["current"].toObject();
        double temp = current["temp_c"].toDouble();

        respuesta = location + " " + QString::number(temp)+"°C";

        qDebug() << respuesta;
        emit signal_temperaturaLista(respuesta);

    }
    else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}
