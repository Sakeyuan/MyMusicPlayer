QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testmymusicplayer.cpp \
    ../MyPlayMusic/lyrices.cpp

HEADERS += \
    ../MyPlayMusic/lyrices.h

