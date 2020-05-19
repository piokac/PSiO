TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        tictactoe.cpp \
        tictactoeabstractplayer.cpp \
        tictactoebot.cpp

HEADERS += \
    common_defs.h \
    tictactoe.h \
    tictactoeabstractplayer.h \
    tictactoebot.h

DISTFILES += \
    abcd.qmodel \
    tictactoemodel.qmodel

STATECHARTS += \
    sate.scxml
