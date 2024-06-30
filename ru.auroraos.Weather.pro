TARGET = ru.auroraos.Weather

QT += concurrent

CONFIG += \
    auroraapp

PKGCONFIG += \

SOURCES += \
    src/main.cpp \
    src/mainviewmodel.cpp \
    src/weathermodel.cpp \
    src/weatherrepository.cpp \
    src/weatherparser.cpp

HEADERS += \
    src/mainviewmodel.h \
    src/weatherdata.h \
    src/weathermodel.h \
    src/weatherparser.h \
    src/weatherrepository.h

DISTFILES += \
    rpm/ru.auroraos.Weather.spec \

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.auroraos.Weather.ts \
    translations/ru.auroraos.Weather-ru.ts \
