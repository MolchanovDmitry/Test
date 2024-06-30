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
    explicit WeatherRepository(QObject *parent = nullptr);

    QFuture<WeatherData*> getWeatherData();

};

#endif // WEATHERREPOSITORY_H
