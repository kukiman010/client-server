QT          -= gui
QT          += network

TARGET      = Command

TEMPLATE    = lib

CONFIG      += staticlib
CONFIG      += c++11

#INCLUDEPATH += $$PWD/Control
#DEPENDPATH  += $$PWD/Control

#INCLUDEPATH += $$PWD/Template
#DEPENDPATH  += $$PWD/Template


SOURCES += \
        command.cpp \
        commandmessage.cpp

HEADERS += \
    command.h \
    commandmessage.h \
    saved_container.h
