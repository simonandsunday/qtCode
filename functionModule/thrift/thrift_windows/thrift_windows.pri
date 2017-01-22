!contains(INCLUDEDFIES, thrift_windows.pri) {
INCLUDEDFIES += thrift_windows.pri

LIBS += -luser32


HEADERS += \
    $$PWD/config.h \
    $$PWD/GetTimeOfDay.h \
    $$PWD/Operators.h \
    $$PWD/OverlappedSubmissionThread.h \
    $$PWD/SocketPair.h \
    $$PWD/Sync.h \
    $$PWD/TWinsockSingleton.h \
    $$PWD/WinFcntl.h

SOURCES += \
    $$PWD/GetTimeOfDay.cpp \
    $$PWD/OverlappedSubmissionThread.cpp \
    $$PWD/SocketPair.cpp \
    $$PWD/TWinsockSingleton.cpp \
    $$PWD/WinFcntl.cpp
}
