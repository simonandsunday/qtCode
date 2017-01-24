!contains(INCLUDEDFILES, rpcServer.pri) {
    INCLUDEDFIES += rpcServer.pri
    INCLUDEPATH += $$PWD
    DEPENDPATH += $$PWD
SOURCES += \
    $$PWD/RpcServerCore.cpp \
    $$PWD/RpcServerHandler.cpp

HEADERS += \
    $$PWD/RpcServerCore.h \
    $$PWD/RpcServerHandler.h

include($$PWD/../thrift/thrift.pri)

HEADERS += \
    $$PWD/MobileAlarmHandler.h \
    $$PWD/HanderInterface.h

SOURCES += \
    $$PWD/MobileAlarmHandler.cpp \
    $$PWD/HanderInterface.cpp
}



