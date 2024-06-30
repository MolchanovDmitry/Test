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

    WeatherModel *weatherModel;

    QFutureWatcher<WeatherData*> watcher;

};

#endif // MAINVIEWMODEL_H
