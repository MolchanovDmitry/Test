#include <auroraapp.h>
#include <QtQuick>
#include "mainviewmodel.h"
#include "weatherrepository.h"
#include "weatherparser.h"

int main(int argc, char *argv[])
{
    qDebug()<<"main thread "<<QThread::currentThreadId();
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.auroraos"));
    application->setApplicationName(QStringLiteral("Weather"));

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/Weather.qml")));
    view->show();

    WeatherRepository *repository;
    MainViewModel mainViewModel(repository);
    WeatherModel *weatherModel = mainViewModel.weatherModel;

    // Добавляем в контекст QML модели.
    view->rootContext()->setContextProperty("weatherModel", QVariant::fromValue(weatherModel));

    return application->exec();
}
