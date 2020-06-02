TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "/home/piotr/Downloads/SFML-2.5.1/include"

SOURCES += \
        main.cpp

LIBS += -L"/home/piotr/Downloads/SFML-2.5.1/lib"

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

HEADERS += \
    customrectangleshape.h

DISTFILES += \
    sfml_model.qmodel
