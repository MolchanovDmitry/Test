#ifndef WEATHERREPOSITORY_H
#define WEATHERREPOSITORY_H

#include <QObject>
#include <QFuture>
#include <QNetworkAccessManager>
#include "weatherdata.h"

class WeatherRepository : public QObject
{
    Q_OBJECT
public:
    explicit WeatherRepository(QObject *parent = nullptr, QNetworkAccessManager *netMan = nullptr);

    QFuture<WeatherData*> getWeatherData();

private:
    QNetworkAccessManager *netMan;

};

#endif // WEATHERREPOSITORY_H
