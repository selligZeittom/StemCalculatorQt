#-------------------------------------------------
#
# Project created by QtCreator 2018-11-03T20:59:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StemCalculator
TEMPLATE = app


SOURCES += main.cpp \
    Model/bike.cpp \
    UserInterface/gui_drawing.cpp \
    UserInterface/gui_menu.cpp

HEADERS  += \
    Model/bike.h \
    UserInterface/gui_drawing.h \
    UserInterface/gui_menu.h
