#-------------------------------------------------
#
# Project created by QtCreator 2016-12-27T16:31:38
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testXml
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
    readXml.cpp \
    InfinovaPage.cpp

HEADERS  += MainWindow.h \
    readXml.h \
    InfinovaPage.h

FORMS    += MainWindow.ui \
    InfinovaPage.ui
