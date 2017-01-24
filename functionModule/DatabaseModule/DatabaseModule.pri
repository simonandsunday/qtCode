!contains(INCLUDEDFILES, DatabaseModule.pri) {
INCLUDEDFILES += DatabaseModule.pri
INCLUDEPATH += $$PWD
QT       += sql

HEADERS += \
    $$PWD/DatabaseMoudle.h

SOURCES += \
    $$PWD/DatabaseMoudle.cpp
}

HEADERS += \
    $$PWD/testDatabase.h

SOURCES += \
    $$PWD/testDatabase.cpp


