#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T19:53:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Threads3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    threadproducer.cpp \
    threadconsumer.cpp \
    buffershared.cpp

HEADERS  += mainwindow.h \
    threadproducer.h \
    threadconsumer.h \
    buffershared.h

FORMS    += mainwindow.ui
