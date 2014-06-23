QT += core gui widgets

CONFIG += c++11

win32{
    LIBS += -lbass
}

linux{
    LIBS += -lbass
}

macx{
    QMAKE_LFLAGS += -framework CoreFoundation
    LIBS += /usr/lib/libbass.dylib
}

unix{
    LIBS += -ldl
}


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    bass/knlibbass.cpp

HEADERS += \
    mainwindow.h \
    bass/knlibbass.h
