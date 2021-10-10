QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        handler.cpp \
        main.cpp \
        socket.cpp \
        user.cpp

HEADERS += \
    handler.h \
    socket.h \
    user.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


//command
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Command/release/ -lCommand
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Command/debug/ -lCommand
else:unix: LIBS += -L$$OUT_PWD/../Command/ -lCommand

INCLUDEPATH += $$PWD/../Command
DEPENDPATH += $$PWD/../Command

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Command/release/libCommand.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Command/debug/libCommand.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Command/release/Command.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Command/debug/Command.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Command/libCommand.a




//storage
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Storage/release/ -lStorage
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Storage/debug/ -lStorage
else:unix:!macx: LIBS += -L$$OUT_PWD/../Storage/ -lStorage

INCLUDEPATH += $$PWD/../Storage
DEPENDPATH += $$PWD/../Storage

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Storage/release/libStorage.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Storage/debug/libStorage.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Storage/release/Storage.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Storage/debug/Storage.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../Storage/libStorage.a
