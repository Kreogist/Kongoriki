QT += core gui widgets

CONFIG += c++11

LIBS += -lbass

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    bass/knlibbass.cpp

HEADERS += \
    mainwindow.h \
    bass/knlibbass.h \
    bass/bass.h \
    bass/bass_ape.h

