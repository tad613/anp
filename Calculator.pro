#-------------------------------------------------
#
# Project created by QtCreator 2017-10-03T20:21:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp \
    packet.cpp \
    file.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    packet.h \
    file.h

FORMS    += mainwindow.ui \
    calculator.ui \
    file.ui

RESOURCES += \
    Enot.qrc \
    Fenix.qrc
