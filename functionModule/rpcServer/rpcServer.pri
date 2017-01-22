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

}
