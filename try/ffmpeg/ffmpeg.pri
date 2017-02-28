!contains(INCLUDEDFILES, ffmpeg.pri) {
INCLUDEDFILES += ffmpeg.pri

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/../../commonlib/ffmpeg-dev/include
DEPENDPATH += $$PWD/../../commonlib/ffmpeg-dev/include
INCLUDEPATH += $$PWD/../../commonlib/SDL2-2.0.5-dev/i686-w64-mingw32/include
DEPENDPATH += $$PWD/../../commonlib/SDL2-2.0.5-dev/i686-w64-mingw32/include

LIBS += -L$$PWD/../../commonlib/ffmpeg-dev/lib -lavformat
LIBS += -L$$PWD/../../commonlib/ffmpeg-dev/lib -lavdevice
LIBS += -L$$PWD/../../commonlib/ffmpeg-dev/lib -lavcodec
LIBS += -L$$PWD/../../commonlib/ffmpeg-dev/lib -lavfilter
LIBS += -L$$PWD/../../commonlib/ffmpeg-dev/lib -lavutil
LIBS += -L$$PWD/../../commonlib/ffmpeg-dev/lib -lpostproc
LIBS += -L$$PWD/../../commonlib/ffmpeg-dev/lib -lswresample
LIBS += -L$$PWD/../../commonlib/ffmpeg-dev/lib -lswscale

LIBS += -L$$PWD/../../commonlib/SDL2-2.0.5-dev/i686-w64-mingw32/lib -lSDL2main
LIBS += -L$$PWD/../../commonlib/SDL2-2.0.5-dev/i686-w64-mingw32/lib -lSDL2
LIBS += -L$$PWD/../../commonlib/SDL2-2.0.5-dev/i686-w64-mingw32/lib -lSDL2_test
#win32:LIBS += -luser32 -lWs2_32

}
