#include "lyrices.h"
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QDebug>

Lyrices::Lyrices() {}

bool Lyrices::loadFromFile(const QString &filePath,LyricResult &result)
{
    QFile file(filePath);
    if (!file.exists()) {
        qDebug() << "文件不存在:" << filePath;
        return false;
    }

    if (!file.permissions().testFlag(QFile::ReadUser)) {
        qDebug() << "没有读取权限:" << filePath;
        return false;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件" << filePath;
        return false;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");

    result.lyrics.clear();
    result.offset = 0;

    QMutexLocker locker(&mutex);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        if (line.isEmpty()) {
            continue;
        }

        // 尝试解析元信息行
        if (parseMetaInfo(line,result)) {
            continue;
        }

        // 尝试解析歌词时间戳行
        LyricLine lyricLine;
        if (parseTimestampLine(line, lyricLine)) {
            result.lyrics.append(lyricLine);
        }
    }

    file.close();

    return !result.lyrics.isEmpty();
}

bool Lyrices::parseMetaInfo(const QString &line, LyricResult &result)
{
    QRegularExpression metaRegex(R"(\[(\w+):(.+)\])");
    QRegularExpressionMatch match = metaRegex.match(line);

    if (match.hasMatch()) {
        QString key = match.captured(1).toLower();
        QString value = match.captured(2).trimmed();

        if (key == "ti"){
            result.title = value;
        }
        else if (key == "ar"){
            result.artist = value;
        }
        else if (key == "al"){
            result.album = value;
        }
        else if (key == "by"){
            result.by = value;
        }
        else if (key == "offset"){
            result.offset = value.toInt();
        }
        else{
            return false;
        }
        return true;
    }
    return false;
}

bool Lyrices::parseTimestampLine(const QString &line, LyricLine &lyricLine)
{
    const QRegularExpression timestampRegex(R"(\[(\d{2}):(\d{2})\.(\d{2,3})\](.+))");
    QRegularExpressionMatch match = timestampRegex.match(line);

    if (match.hasMatch()) {
        int minutes = match.captured(1).toInt();
        int seconds = match.captured(2).toInt();
        int milliseconds = match.captured(3).toInt();
        if (milliseconds < 100) milliseconds *= 10;

        lyricLine.timestamp = (minutes * 60 * 1000) + (seconds * 1000) + milliseconds;
        lyricLine.text = match.captured(4).trimmed();
        return true;
    }
    return false;
}

qint64 Lyrices::parseTimestamp(const QString &timeStr)
{
    QRegularExpression regex(R"((\d{2}):(\d{2})\.(\d{2,3}))");
    QRegularExpressionMatch match = regex.match(timeStr);

    if (match.hasMatch()) {
        int minutes = match.captured(1).toInt();
        int seconds = match.captured(2).toInt();
        int milliseconds = match.captured(3).toInt();

        if (milliseconds < 100) {
            milliseconds *= 10;
        }

        return (minutes * 60 * 1000) + (seconds * 1000) + milliseconds;
    }

    return 0;
}

QString Lyrices::getLyricAtTime(qint64 time,const QList<LyricLine> &lyrics)
{
    int left = 0;
    int right = lyrics.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        qint64 value = lyrics[mid].timestamp;
        if(time == value){
            return lyrics[mid].text;
        }
        else if(time > value){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    if(right >= 0){
        return lyrics[right].text;
    }
    return QString();
}

void Lyrices::clearLyricResult(LyricResult &lyricResult)
{
    lyricResult.title = "";
    lyricResult.artist = "";
    lyricResult.album = "";
    lyricResult.by = "";
    lyricResult.offset = 0;
    lyricResult.lyrics.clear();
}

