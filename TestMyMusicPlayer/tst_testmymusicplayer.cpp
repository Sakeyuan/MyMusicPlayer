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

}

QTEST_APPLESS_MAIN(TestMyMusicPlayer)

#include "tst_testmymusicplayer.moc"
