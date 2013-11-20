#-------------------------------------------------
#
# Project created by QtCreator 2013-11-18T14:33:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIView
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GUIView.cpp

HEADERS  += mainwindow.h \
    AbstractView.h \
    GUIView.h

FORMS    += mainwindow.ui
