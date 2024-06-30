#include "weathermodel.h"
#include <QDebug>
#include <QThread>

void WeatherModel::setWeatherData(const WeatherData &data) {
    qDebug()<<"current thread "<<QThread::currentThreadId();
    beginResetModel();
    weatherData = data;
    endResetModel();
}

int WeatherModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return weatherData.weekTemperatures.count();
}

QVariant WeatherModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= weatherData.weekTemperatures.count())
        return QVariant();

    const WeekTemperatures &weekTemp = weatherData.weekTemperatures.at(index.row());

    switch (role) {
    case WeekNameRole:
        return weekTemp.weekName;
    case MorningTempRole:
        return weekTemp.temperatures.morning;
    case AfternoonTempRole:
        return weekTemp.temperatures.afternoon;
    case EveningTempRole:
        return weekTemp.temperatures.evening;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> WeatherModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[WeekNameRole] = "weekName";
    roles[MorningTempRole] = "morningTemp";
    roles[AfternoonTempRole] = "afternoonTemp";
    roles[EveningTempRole] = "eveningTemp";
    return roles;
}
