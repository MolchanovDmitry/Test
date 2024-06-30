#ifndef WEATHERPARSER_H
#define WEATHERPARSER_H

#include <QObject>
#include "weatherdata.h"

class WeatherParser : public QObject
{
    Q_OBJECT
public:
    explicit WeatherParser(QObject *parent = nullptr);

    static WeatherData* getWeekData(const QString &jsonString);

signals:

};

#endif // WEATHERPARSER_H
