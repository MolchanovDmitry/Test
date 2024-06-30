#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>

struct Temperatures {
    int morning;
    int afternoon;
    int evening;
};

struct WeekTemperatures{
    QString weekName;
    Temperatures temperatures;
};

struct WeatherData {
    QList<WeekTemperatures> weekTemperatures;
};



#endif // WEATHERDATA_H
