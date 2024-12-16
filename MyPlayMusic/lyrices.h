#ifndef LYRICES_H
#define LYRICES_H

#include <QString>
#include <QList>

class Lyrices
{
public:
    struct LyricLine {
        qint64 timestamp;
        QString text;
    };

    Lyrices();

    bool loadFromFile(const QString &filePath);
    QString getLyricAtTime(qint64 time) const;
    QList<LyricLine> getAllLyrics() const;

    // 元信息
    QString title;  // 歌曲标题
    QString artist; // 演唱者
    QString album;  // 所属专辑
    QString by;     // 歌词制作组
    int offset;     // 歌词开始处

private:
    QList<LyricLine> lyrics;

    bool parseMetaInfo(const QString &line);
    bool parseTimestampLine(const QString &line, QString &text, qint64 &timestamp) const;
    qint64 parseTimestamp(const QString &timeStr) const;
};

#endif // LYRICES_H
