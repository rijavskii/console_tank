TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bullet.cpp \
    tank.cpp \
    win_console.cpp

DISTFILES += \
    qt_tank.pro.user \
    .gitignore \
    README.md

HEADERS += \
    bullet.h \
    tank.h \
    win_console.h

