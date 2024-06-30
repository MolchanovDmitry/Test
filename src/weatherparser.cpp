#include "weatherparser.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

WeatherParser::WeatherParser(QObject *parent) : QObject(parent)
{

}

WeatherData* WeatherParser::getWeekData(const QString &jsonString)
{
    WeatherData *weatherData = new WeatherData;

    QJsonDocument document = QJsonDocument::fromJson(jsonString.toUtf8());
    if (!document.isObject()) {
        qWarning() << "Invalid JSON format";
        return weatherData;
    }

    QJsonObject rootObject = document.object();
    QJsonArray weekTemperaturesArray = rootObject.value("week_temperatures").toArray();

    for (const QJsonValue &value : weekTemperaturesArray) {
        QJsonObject weekObject = value.toObject();
        WeekTemperatures weekTemps;
        weekTemps.weekName = weekObject.value("day").toString();

        QJsonObject temperaturesObject = weekObject.value("temperatures").toObject();
        weekTemps.temperatures.morning = temperaturesObject.value("morning").toInt();
        weekTemps.temperatures.afternoon = temperaturesObject.value("afternoon").toInt();
        weekTemps.temperatures.evening = temperaturesObject.value("evening").toInt();

        weatherData->weekTemperatures.append(weekTemps);
    }

    qDebug()<<weatherData->weekTemperatures.first().weekName;

    return weatherData;

}
