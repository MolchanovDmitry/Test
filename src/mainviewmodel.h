#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include <QFutureWatcher>
#include "weatherrepository.h"
#include "weathermodel.h"

class MainViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MainViewModel(QObject *parent = nullptr, WeatherRepository* weatherRepository = nullptr);

    const WeatherModel* getWeatherModel() const {
        return weatherModel;
    }

private:

    WeatherModel *weatherModel = new WeatherModel(this);

    QFutureWatcher<WeatherData*> *watcher = new QFutureWatcher<WeatherData*>(this);

    QFuture<WeatherData*> weatherDataFuture;

    WeatherRepository *weatherRepository;

};

#endif // MAINVIEWMODEL_H
