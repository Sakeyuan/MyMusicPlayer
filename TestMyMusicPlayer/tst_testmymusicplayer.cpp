#include <QtTest>
#include <QStandardPaths>
#include <QDir>
#include <QCoreApplication>
#include "../MyPlayMusic/lyrices.h"
#include "../MyPlayMusic/databasemanager.h"

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
    // #region 歌词解析器测试代码
    //    Lyrices lyricParser;
    //    LyricResult result;
    //    QString filePath = "D:/Qt-Project/MyMusicPlayer/MyPlayMusic/Music/龙卷风-G.E.M.邓紫棋.128.lrc";
    //    QVERIFY(lyricParser.loadFromFile(filePath,result));
    // #endregion 歌词解析器测试代码

    // #region 数据库测试代码
    QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QString dbPath = appDataPath + "/music.db";
    QDir dir(appDataPath);
    if(!dir.exists() && !dir.mkpath(appDataPath)){
        qDebug() << "Failed to create directory:" << appDataPath;
        return;
    }

    DatabaseManager dbManager(dbPath);

    QVERIFY(dbManager.connect());

    // 创建表
    QString createSql = R"(
        CREATE TABLE IF NOT EXISTS MusicLibrary (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            filePath TEXT UNIQUE NOT NULL,
            fileName TEXT NOT NULL,
            artist TEXT,
            album TEXT,
            genre TEXT,
            duration INTEGER,
            fileSize INTEGER,
            bitrate INTEGER
        );
    )";

    dbManager.createTable(createSql);

    // 插入数据
    QVariantMap music1{
        {":filePath", "/path/to/song1.mp3"},
        {":fileName", "Song 1"},
        {":artist", "Artist 1"},
        {":album", "Album 1"}
    };
    dbManager.insertData("INSERT INTO MusicLibrary (filePath, fileName, artist, album) VALUES (:filePath, :fileName, :artist, :album)", music1);

    // 查询数据
    QList<QVariantMap> results = dbManager.queryData("SELECT * FROM MusicLibrary");
    for (const QVariantMap &row : results) {
        qDebug() << "ID:" << row["id"].toInt()
                 << "File Path:" << row["filePath"].toString()
                 << "File Name:" << row["fileName"].toString()
                 << "Artist:" << row["artist"].toString()
                 << "Album:" << row["album"].toString();
    }

    // #endregion 歌词解析器测试代码
}

QTEST_APPLESS_MAIN(TestMyMusicPlayer)

#include "tst_testmymusicplayer.moc"
