TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "/home/piotr/Downloads/SFML-2.5.1/include"



LIBS += -L"/home/piotr/Downloads/SFML-2.5.1/lib"

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

INCLUDEPATH += $$PWD/..
INCLUDEPATH += $$PWD/../clients
INCLUDEPATH += $$PWD/../model


SOURCES += \
        ../clients/tictactoeabstractplayer.cpp \
        ../clients/tictactoebot.cpp \
        ../clients/tictactoesfmlplayer.cpp \
    ../model/taictactoetcpserver.cpp \
        ../model/tictactoe.cpp \
    ../model/tictactoetcpproxy.cpp \
        client.cpp \


HEADERS += \
    ../clients/tictactoeabstractplayer.h \
    ../clients/tictactoebot.h \
    ../clients/tictactoesfmlplayer.h \
    ../common_defs.h \
    ../model/taictactoetcpserver.h \
    ../model/tictactoe.h \ \
    ../model/tictactoetcpproxy.h


#CONFIG(debug, debug|release) {
#    DESTDIR = "$$ParentDirectory\debug"
#}
#CONFIG(release, debug|release) {
#    DESTDIR = "$$ParentDirectory\release"
#}
