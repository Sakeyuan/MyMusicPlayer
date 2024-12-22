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
    LyricResult result;
    QString filePath = "D:/Qt-Project/MyMusicPlayer/MyPlayMusic/Music/龙卷风-G.E.M.邓紫棋.128.lrc";
    QVERIFY(lyricParser.loadFromFile(filePath,result));
}

QTEST_APPLESS_MAIN(TestMyMusicPlayer)

#include "tst_testmymusicplayer.moc"
