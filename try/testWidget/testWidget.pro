#-------------------------------------------------
#
# Project created by QtCreator 2016-12-22T15:10:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testWidget
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    testToolBox.cpp \
    phone.cpp

HEADERS  += MainWindow.h \
    testToolBox.h \
    phone.h

FORMS    += MainWindow.ui \
    testToolBox.ui \
    phone.ui
