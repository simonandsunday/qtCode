!contains(INCLUDEDFIES, simpleSDK.pri) {
INCLUDEDFIES += simpleSDK.pri


unix{
LIBS += -L/home/work_dir/AIP-build$${RELDIR}/AIP/bin -lavt_std
}else{
win32: LIBS += -L$$PWD/ -lavt_std
#LIBS += -LE:/avtrace/Project/STD_SDK/SW/SRC/bin_debug -lavt_std
}

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
HEADERS += \
    $$PWD/simpleSDK.h

SOURCES += \
    $$PWD/simpleSDK.cpp
HEADERS += \
    $$PWD/avt_func_id.h

HEADERS += \
    $$PWD/avt_std.h

HEADERS += \
    $$PWD/testSimpleSDK.h

SOURCES += \
    $$PWD/testSimpleSDK.cpp

HEADERS +=

SOURCES +=
}

HEADERS += \
    $$PWD/XMLString.h




