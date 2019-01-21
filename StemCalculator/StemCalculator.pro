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
    UserInterface/gui_menu.cpp \
    UserInterface/screenmanager.cpp \
    UserInterface/gui_computing.cpp \
    factory.cpp \
    UserInterface/gui_database.cpp \
    XF/xf.cpp \
    XF/xfevent.cpp \
    XF/xftimer.cpp \
    Controller/databasemanager.cpp

HEADERS  += \
    Model/bike.h \
    UserInterface/gui_drawing.h \
    UserInterface/gui_menu.h \
    UserInterface/screenmanager.h \
    UserInterface/gui_computing.h \
    factory.h \
    UserInterface/gui_database.h \
    XF/ism.h \
    XF/xf.h \
    XF/xfevent.h \
    XF/xftimer.h \
    Controller/databasemanager.h
