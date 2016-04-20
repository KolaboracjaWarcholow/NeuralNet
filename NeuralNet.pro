#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T18:48:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NeuralNet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    handwritingarea.cpp \
    bitmap.cpp

HEADERS  += mainwindow.h \
    handwritingarea.h \
    bitmap.h

FORMS    += mainwindow.ui
