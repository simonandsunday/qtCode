#-------------------------------------------------
#
# Project created by QtCreator 2016-12-22T15:10:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testWidget
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
    testToolBox.cpp \
    phone.cpp \
    teststyle.cpp

HEADERS  += MainWindow.h \
    testToolBox.h \
    phone.h \
    teststyle.h

FORMS    += MainWindow.ui \
    testToolBox.ui \
    phone.ui \
    teststyle.ui
