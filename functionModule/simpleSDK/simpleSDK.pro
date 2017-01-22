#-------------------------------------------------
#
# Project created by QtCreator 2017-01-10T15:05:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simpleSDK
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

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui
include($$PWD/simpleSDK.pri)
