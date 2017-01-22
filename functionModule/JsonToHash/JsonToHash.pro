#-------------------------------------------------
#
# Project created by QtCreator 2016-06-15T10:50:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JsonToHash
TEMPLATE = app

CONFIG(release, debug|release){
RELDIR = release
}else{
greaterThan(QT_MAJOR_VERSION, 4): RELDIR = -debug-5
}

unix{
DESTDIR = /home/work_dir/AIP-build$${RELDIR}/AIP/bin
}else{
DESTDIR = $$PWD/../../output/$${RELDIR}/bin
}


win32{
UI_DIR = $$PWD/ui_dir_win32
MOC_DIR = $$PWD/ui_dir_win32
}else{
UI_DIR = ./ui_dir_unix
MOC_DIR = ./ui_dir_unix
}

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui

include($$PWD/JsonToHash.pri)
include($$PWD/../log/log.pri)
