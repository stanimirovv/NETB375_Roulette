#-------------------------------------------------
#
# Project created by QtCreator 2014-10-30T16:05:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = netb375_roulette
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    roulette_logic.cpp \
    game_loader.cpp \
    startwindow.cpp \
    setprofile.cpp \
    loadgame.cpp


HEADERS  += mainwindow.h \
    roulette_logic.h \
    game_loader.h \
    startwindow.h \
    setprofile.h \
    loadgame.h

FORMS    += mainwindow.ui \
    startwindow.ui \
    setprofile.ui \
    loadgame.ui

RESOURCES += \
    res.qrc

