#include "mainviewmodel.h"
#include <QFutureWatcher>
#include <QDebug>

MainViewModel::MainViewModel(QObject *parent, WeatherRepository *weatherRepository) : QObject(parent)
{
    qDebug() << "check 1";

    QObject::connect(&this->watcher, &QFutureWatcher<WeatherData*>::finished, [this](){
        qDebug() << "check 2";
        WeatherData *weatherData = this->watcher.result();

        qDebug() << weatherData->weekTemperatures.first().weekName;
        weatherModel->setWeatherData(*weatherData);
    });
    QFuture<WeatherData*> weatherDataFuture = weatherRepository->getWeatherData();
    qDebug() << "check 3";
    this->watcher.setFuture(weatherDataFuture);
}
