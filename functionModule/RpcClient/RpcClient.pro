#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T17:19:35
#
#-------------------------------------------------

QT       -= gui

TARGET = RpcClient
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


DEFINES += RPCCLIENT_LIBRARY

SOURCES += RpcClient.cpp \
    main.cpp \

HEADERS += RpcClient.h\
        rpcclient_global.h \



include($$PWD/RpcClient.pri)
include($$PWD/../JsonToHash/JsonToHash.pri)
