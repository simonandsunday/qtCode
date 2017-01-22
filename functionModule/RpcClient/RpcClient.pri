!contains(INCLUDEDFILES, RpcClient.pri) {
    INCLUDEPATH += $$PWD
    DEPENDPATH += $$PWD
SOURCES +=  \
    $$PWD/RpcClientCore.cpp \
    $$PWD/RpcClientHandler.cpp

HEADERS += \
    $$PWD/RpcClientCore.h \
    $$PWD/RpcClientHandler.h

include($$PWD/../thrift/thrift.pri)
}
