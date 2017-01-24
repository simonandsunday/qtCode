#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T17:21:04
#
#-------------------------------------------------

QT       -= gui

TARGET = rpcServer
TEMPLATE = app

DEFINES += RPCSERVER_LIBRARY

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

SOURCES += RpcServer.cpp \
    main.cpp \
    RpcServerCoreImplementTest.cpp \
    testRpcServer.cpp

HEADERS += RpcServer.h\
        rpcserver_global.h \
    RpcServerCoreImplementTest.h \
    testRpcServer.h \
    RestfulFunctionId.h


include($$PWD/rpcServer.pri)
include($$PWD/../log/log.pri)
include($$PWD/../DatabaseModule/DatabaseModule.pri)
include($$PWD/../JsonToHash/JsonToHash.pri)
