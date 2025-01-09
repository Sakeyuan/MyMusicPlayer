#include "mymusicplayer.h"
#include "playmusiclistform.h"
#include <QApplication>
#include <QPushButton>
#include <QStandardPaths>
#include "fsearchbox.h"
#include "localmusicwidget.h"
#include "fplayer.h"
#include "lyriccardwidget.h"
#include "lyrices.h"
#include "test.h"
#include <spdlog/spdlog.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    spdlog::info("Hello, Qt with spdlog!");
    MyMusicPlayer w;
    // Test w;

    qRegisterMetaType<LyricResult>("LyricResult");
    // FSearchBox w;
    // FPlayer::instance();
    //LocalMusicWidget w;
    // LyricCardWidget w;

    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/music.db";

    w.show();
    return a.exec();
}




