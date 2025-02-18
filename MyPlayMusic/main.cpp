#include "mymusicplayer.h"
#include "playmusiclistform.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QPushButton>
#include <QStandardPaths>
#include "fsearchbox.h"
#include "localmusicwidget.h"
#include "fplayer.h"
#include "lyriccardwidget.h"
#include "lyrices.h"
#include "test.h"
#include <spdlog/spdlog.h>
#include "logger.h"

void initLogger(){
    Logger::instance().init();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMusicPlayer w;

    // 初始化日志
    initLogger();

    spdlog::get("MyMusicPlayer")->info("程序启动");

    qRegisterMetaType<LyricResult>("LyricResult");
    // FSearchBox w;
    // FPlayer::instance();
    //LocalMusicWidget w;
    // LyricCardWidget w;
    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/music.db";
    w.show();
    return a.exec();
}




