QT += testlib sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testmymusicplayer.cpp \
    ../MyPlayMusic/databasemanager.cpp \
    ../MyPlayMusic/lyrices.cpp

HEADERS += \
    ../MyPlayMusic/databasemanager.h \
    ../MyPlayMusic/lyrices.h

RESOURCES += \
    res.qrc

DISTFILES += \
    sql/music.db

