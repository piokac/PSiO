TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += $$PWD/..
INCLUDEPATH += $$PWD/../clients
INCLUDEPATH += $$PWD/../model


SOURCES += \
        ../clients/tictactoeabstractplayer.cpp \
        ../clients/tictactoebot.cpp \
        ../model/tictactoe.cpp \
        main.cpp \


HEADERS += \
    ../clients/tictactoeabstractplayer.h \
    ../clients/tictactoebot.h \
    ../common_defs.h \
    ../model/tictactoe.h \


