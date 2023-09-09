QT       += core gui
QT += network
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filedownloader.cpp \
    main.cpp \
    mainwindow.cpp \
    oknodiagram.cpp

HEADERS += \
    filedownloader.hh \
    mainwindow.hh \
    oknodiagram.hh

FORMS += \
    mainwindow.ui \
    oknodiagram.ui

TRANSLATIONS += \
    wds_2_en_150.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    zasoby.qrc

DISTFILES += \
    ../mgla.svg \
    ../sniezynka.png.svg \
    rysunek.svg \
    rysunek2.svg \
    slonce_2.svg \
    snieg_d.svg \
    sniezynka.svg
