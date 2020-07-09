QT -= gui
QT += core sql
CONFIG += c++11
TEMPLATE = lib

DEFINES += BUILD_TESTS

DESTDIR = $$PWD/../shared/lib

INCLUDEPATH += $$PWD/include

HEADERS += \
    include/ConnectionManager.h \
    include/Executor.h \
    include/Selector.h \
    include/dbtypes.h

SOURCES += \
    src/ConnectionManager.cpp \
    src/Executor.cpp \
    src/Selector.cpp

