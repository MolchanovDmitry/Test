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

    auto parent = application.data();

    WeatherRepository *repository = new WeatherRepository(parent, new QNetworkAccessManager(parent));
    MainViewModel *mainViewModel = new MainViewModel(parent, repository);
    WeatherModel *weatherModel = mainViewModel->getWeatherModel();

    // Добавляем в контекст QML модели.
    view->rootContext()->setContextProperty("weatherModel", weatherModel);

    return application->exec();
}
