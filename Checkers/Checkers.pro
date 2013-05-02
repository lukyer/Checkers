#-------------------------------------------------
#
# Project created by QtCreator 2013-04-29T21:24:03
#
#-------------------------------------------------

QT       += core gui network

TARGET = Checkers
TEMPLATE = app


SOURCES +=\
    checkerswindow.cpp \
    main.cpp \
    move.cpp \
    checkers.cpp \
    realplayer.cpp \
    guiboard.cpp \
    aiplayer.cpp \
    guifigure.cpp \
    guisquare.cpp \
    checkersgame.cpp \
    networkplayer.cpp \
    network.cpp \
    abstractplayer.cpp

HEADERS  += \
    checkerswindow.h \
    move.h \
    checkers.h \
    common.h \
    realplayer.h \
    guiboard.h \
    aiplayer.h \
    guifigure.h \
    guisquare.h \
    checkersgame.h \
    networkplayer.h \
    network.h \
    abstractplayer.h

FORMS    += checkerswindow.ui

OTHER_FILES += \
    ../README.md

QMAKE_CXXFLAGS += -std=c++0x
