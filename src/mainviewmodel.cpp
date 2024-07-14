#include "mainviewmodel.h"
#include <QFutureWatcher>
#include <QDebug>

MainViewModel::MainViewModel(QObject *parent, WeatherRepository *weatherRepository) : QObject(parent), weatherRepository(weatherRepository)
{
    qDebug() << "check 1";

    QObject::connect(this->watcher, &QFutureWatcher<WeatherData*>::finished, [this](){
        qDebug() << "check 2";
        WeatherData *weatherData = this->watcher->result();
        qDebug() << "check 3";

        qDebug() << weatherData->weekTemperatures.first().weekName;
        qDebug() << "check 4";
        this->weatherModel->setWeatherData(*weatherData);
        qDebug() << "check 5";
    });
    this->weatherDataFuture = this->weatherRepository->getWeatherData();
    qDebug() << "check 3";
    this->watcher->setFuture(weatherDataFuture);
}
