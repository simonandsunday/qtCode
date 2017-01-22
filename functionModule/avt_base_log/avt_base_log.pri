!contains(INCLUDEDFILES, avt_base_log.pri) {
INCLUDEDFILES += avt_base_log.pri

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD


INCLUDEPATH += $$PWD/log4cpp/include
DEPENDPATH += $$PWD/log4cpp/include

HEADERS += $$PWD/avt_base_log.h \
    $$PWD/avt_base_log_global.h

SOURCES += $$PWD/avt_base_log.cpp

win32:LIBS += -luser32 -lWs2_32
win32{
LIBS += -L$$PWD/log4cpp/lib/win -llog4cpp
}

unix{
LIBS += -L$$DESTDIR -llog4cpp
}


}
