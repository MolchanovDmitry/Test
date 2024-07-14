#include "weatherrepository.h"
#include <QtConcurrent>
#include <QThread>
#include <QNetworkReply>
#include <QEventLoop>
#include <QDebug>
#include "weatherparser.h"

const static QString url = "https://raw.githubusercontent.com/MolchanovDmitry/Test/master/sample.json";

WeatherRepository::WeatherRepository(QObject *parent, QNetworkAccessManager *netMan) : QObject(parent), netMan(netMan)
{

}

QFuture<WeatherData*> WeatherRepository::getWeatherData()
{
    qDebug()<<"get weather data 1";
    return QtConcurrent::run([this]() {
        qDebug()<<"get weather data 2";
        qDebug()<<"current thread 1 "<<QThread::currentThreadId();
        QNetworkRequest request(url);

        QNetworkReply *reply = this->netMan->get(request);
        qDebug()<<"check 1";

        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        qDebug()<<"check 2";

        QByteArray responseData = reply->readAll();
        //reply->deleteLater();

        qDebug()<<"get weather data 3 "<<QString(responseData);

        qDebug()<<"current thread 2 "<<QThread::currentThreadId();

        return WeatherParser::getWeekData(QString(responseData));
    });;
}
