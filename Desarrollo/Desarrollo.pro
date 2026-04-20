TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        equipo.cpp \
        jugador.cpp \
        main.cpp \
        partido.cpp \
        resultados.cpp \
        torneo.cpp

HEADERS += \
    equipo.h \
    jugador.h \
    partido.h \
    resultados.h \
    torneo.h
