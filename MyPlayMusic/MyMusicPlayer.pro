QT       += core gui sql multimedia concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += unicode

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    databasemanager.cpp \
    fplayer.cpp \
    fsearchbox.cpp \
    internalbutton.cpp \
    localmusicwidget.cpp \
    logger.cpp \
    lyriccardwidget.cpp \
    lyrices.cpp \
    lyricsparsetask.cpp \
    main.cpp \
    marqueelabel.cpp \
    musicmessage.cpp \
    mymusicplayer.cpp \
    playmusiclistform.cpp \
    qcarousel.cpp \
    sidehidelabel.cpp \
    test.cpp \
    util.cpp

HEADERS += \
    QLogFormatter.h \
    databasemanager.h \
    fplayer.h \
    fsearchbox.h \
    internalbutton.h \
    localmusicwidget.h \
    logger.h \
    lyriccardwidget.h \
    lyrices.h \
    lyricsparsetask.h \
    marqueelabel.h \
    musicmessage.h \
    mymusicplayer.h \
    playmusiclistform.h \
    qcarousel.h \
    queries.h \
    sidehidelabel.h \
    test.h \
    util.h

FORMS += \
    fsearchbox.ui \
    localmusicwidget.ui \
    lyriccardwidget.ui \
    musicmessage.ui \
    mymusicplayer.ui \
    playmusiclistform.ui \
    test.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/include

INCLUDEPATH += $$PWD/include/ffmpeg/include
LIBS += $$PWD/include/ffmpeg/bin/av*.dll \
        $$PWD/include/ffmpeg/bin/sw*.dll \
        $$PWD/include/ffmpeg/bin/pos*.dll

RESOURCES += \
    res.qrc

DISTFILES += \
    img/lyric.svg \
    img/lyricClicked.svg \
    img/notvoice.svg \
    img/voice.svg \
    sql/music.db



