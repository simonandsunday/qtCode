!contains(INCLUDEDFILES, JsonToHash.pri) {
INCLUDEDFILES += JsonToHash.pri

INCLUDEPATH += $$PWD
unix{
LIBS += -L/home/work_dir/AIP-build$${RELDIR}/AIP/bin -lJsonLib
}else{
LIBS += -L$$PWD/../../output/$${RELDIR}/bin -lJsonLib
}
SOURCES += \
    $$PWD/JsonToHash.cpp

HEADERS  +=  \
    $$PWD/JsonToHash.h
}
