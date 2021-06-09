#-------------------------------------------------
# Qmake fail
#-------------------------------------------------

QT += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    disain.qrc

DISTFILES +=
