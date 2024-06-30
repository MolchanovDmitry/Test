#ifndef WEATHERMODEL_H
#define WEATHERMODEL_H

#include <QAbstractListModel>
#include "weatherdata.h"

class WeatherModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit WeatherModel(QObject *parent = nullptr)
        : QAbstractListModel(parent) {}

public:
    enum WeatherRoles {
        WeekNameRole = Qt::UserRole + 1,
        MorningTempRole,
        AfternoonTempRole,
        EveningTempRole
    };

    void setWeatherData(const WeatherData &data);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
    WeatherData weatherData;
};

#endif // WEATHERMODEL_H
