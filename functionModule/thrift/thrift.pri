!contains(INCLUDEDFILES, thrift.pri) {
INCLUDEDFILES += thrift.pri

INCLUDEPATH += $$PWD
win32{

INCLUDEPATH += $$PWD/thrift/win32/include
LIBS += -L$$PWD/thrift/win32/lib -lthriftnb -lthrift \
-levent

LIBS += -L$$PWD/../../commonlib/boost_1_55_0/stage/lib \
-lboost_thread-mgw48-mt-s-1_55 \
-lboost_system-mgw48-mt-s-1_55



INCLUDEPATH += $$PWD/../../commonlib/boost_1_55_0

LIBS +=  \
-luser32 \
-lws2_32 \
-ladvapi32

include($$PWD/thrift_windows/thrift_windows.pri)
}

unix{
#INCLUDEPATH += /opt/thrift-0.9.8/include
INCLUDEPATH += $$PWD/../../../../Depends/thrift/linux/include
LIBS += -L$$PWD/../../../../Depends/thrift/linux/lib -lthriftnb -lthrift \
-levent
}

android{
#message("---------hello android---------")
INCLUDEPATH += G:/Qt/libThrift
INCLUDEPATH += G:/Qt/libThrift/thrift
LIBS += G:/Qt/libThrift/bin/libthrift.a \
G:/Qt/libThrift/deps/event/lib/libevent.a

INCLUDEPATH += G:/Qt/libThrift/deps/boost/include/boost-1_55
LIBS += -LG:/Qt/libThrift/deps/boost/lib \
-lboost_thread-gcc-mt-1_55 \
-lboost_system-gcc-mt-1_55

}

HEADERS += \
    $$PWD/MobileAlarm.h \
    $$PWD/MobileAlarmAPI_constants.h \
    $$PWD/MobileAlarmAPI_types.h

SOURCES += \
    $$PWD/MobileAlarm.cpp \
    $$PWD/MobileAlarmAPI_constants.cpp \
    $$PWD/MobileAlarmAPI_types.cpp

OTHER_FILES += \
$$PWD/MobileAlarm_server.skeleton.cpp
}

