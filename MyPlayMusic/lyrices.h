#ifndef LYRICES_H
#define LYRICES_H

#include <QString>
#include <QList>
#include <QThreadPool>
#include <QMutex>
#include <QMetaType>

struct LyricLine {
    qint64 timestamp; // 时间戳
    QString text;     // 歌词文本
};

struct LyricResult {
    QString title;                // 歌曲标题
    QString artist;               // 演唱者
    QString album;                // 所属专辑
    QString by;                   // 歌词制作者
    int offset = 0;               // 时间偏移量
    QList<LyricLine> lyrics;      // 所有歌词行
    LyricResult() : title("暂无歌词信息"),artist("无"),album("无"),by("无"){
    }
    bool isValid() const {
        return !title.isEmpty() && !artist.isEmpty() && !lyrics.isEmpty();
    }
};

Q_DECLARE_METATYPE(LyricResult)    // 声明 LyricResult 为元类型

class Lyrices
{
public:
    Lyrices();

    bool loadFromFile(const QString &filePath,LyricResult &result);
    static QString getLyricAtTime(qint64 time,const QList<LyricLine> &lyrics);
    static void clearLyricResult(LyricResult& lyricResult);

public:
    QMutex mutex;

private:
    static bool parseMetaInfo(const QString &line,LyricResult &result);
    static bool parseTimestampLine(const QString &line, LyricLine &lyricLine);
    static qint64 parseTimestamp(const QString &timeStr);
};

#endif // LYRICES_H
