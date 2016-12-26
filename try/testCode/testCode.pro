#-------------------------------------------------
#
# Project created by QtCreator 2016-12-20T16:57:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testCode
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
        MainWindow.cpp \
    testqstringList.cpp \
    testProperty.cpp \
    writeLocalfile.cpp

HEADERS  += MainWindow.h \
    testqstringList.h \
    testProperty.h \
    writeLocalfile.h

FORMS    += MainWindow.ui
