#-------------------------------------------------
#
# Project created by QtCreator 2016-05-06T20:46:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mineSweeperQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Field.cpp \
    functor.cpp \
    Square.cpp \
    gamemanager.cpp \
    Exceptions.cpp

HEADERS  += mainwindow.h \
    Field.h \
    functor.h \
    Square.h \
    gamemanager.h \
    Exceptions.h

FORMS    += mainwindow.ui
