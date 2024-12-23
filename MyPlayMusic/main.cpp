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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMusicPlayer w;
    // FSearchBox w;
    // FPlayer::instance();
    //LocalMusicWidget w;
    // LyricCardWidget w;

    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/music.db";

    w.show();
    return a.exec();
}
