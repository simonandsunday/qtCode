!contains(INCLUDEDFILES, log.pri) {
INCLUDEDFILES += log.pri
include($$PWD/../avt_base_log/avt_base_log.pri)
INCLUDEPATH += $$PWD
HEADERS += \
    $$PWD/mobileServiceLog.h
}
