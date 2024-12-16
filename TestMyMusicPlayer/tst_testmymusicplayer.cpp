#include <QtTest>
#include "../MyPlayMusic/lyrices.h"

class TestMyMusicPlayer : public QObject
{
    Q_OBJECT

public:
    TestMyMusicPlayer();
    ~TestMyMusicPlayer();

private slots:
    void test_lyricparser();

};

TestMyMusicPlayer::TestMyMusicPlayer()
{

}

TestMyMusicPlayer::~TestMyMusicPlayer()
{

}

void TestMyMusicPlayer::test_lyricparser()
{
    Lyrices lyricParser;
    // 调用方法并验证结果
    QVERIFY(lyricParser.loadFromFile(":/music/lingyu.lrc"));
    QString lyric = lyricParser.getLyricAtTime(12000);
    QVERIFY(!lyric.isEmpty());

    qDebug() << "Lyric at 12000ms:" << lyric;
}

QTEST_APPLESS_MAIN(TestMyMusicPlayer)

#include "tst_testmymusicplayer.moc"
