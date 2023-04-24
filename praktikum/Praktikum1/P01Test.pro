GOOGLETEST_DIR = C:/qt/googletest

include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt


HEADERS += \
    p01test.h

SOURCES += \
    p01TestMain.cpp
