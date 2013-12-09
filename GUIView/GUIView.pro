#-------------------------------------------------
#
# Project created by QtCreator 2013-11-18T14:33:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIView
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    GUIView.cpp \
    ../Passenger.cpp \
    ../Model.cpp \
    ../Flight.cpp \
    ../Controller.cpp \
    ../CLIView.cpp \
    main.cpp

INCLUDEPATH += ../

HEADERS  += mainwindow.h \
    AbstractView.h \
    GUIView.h \
    ../Passenger.h \
    ../Model.h \
    ../Flight.h \
    ../Controller.h \
    ../CLIView.h \
    ../AbstractView.h

FORMS    += mainwindow.ui
