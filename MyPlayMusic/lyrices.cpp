#include "lyrices.h"
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QDebug>

Lyrices::Lyrices() : offset(0) {}

bool Lyrices::loadFromFile(const QString &filePath)
{
    QFile file(filePath);
    // 检查文件是否存在
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

    const QRegularExpression timestampRegex(R"(\[(\d{2}):(\d{2})\.(\d{2,3})\](.+))");

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        if (line.isEmpty()) {
            continue;
        }

        // 尝试解析元信息行
        if (parseMetaInfo(line)) {
            continue;
        }

        // 尝试解析歌词时间戳行
        QString text;
        qint64 timestamp;
        if (parseTimestampLine(line, text, timestamp)) {
            lyrics.append({timestamp, text});
        }
    }

    file.close();

    return !lyrics.isEmpty();
}

bool Lyrices::parseMetaInfo(const QString &line)
{
    if (line.startsWith("[ti:")) {
        title = line.mid(4, line.length() - 5);
        return true;
    }
    if (line.startsWith("[ar:")) {
        artist = line.mid(4, line.length() - 5);
        return true;
    }
    if (line.startsWith("[al:")) {
        album = line.mid(4, line.length() - 5);
        return true;
    }
    if (line.startsWith("[by:")) {
        by = line.mid(4, line.length() - 5);
        return true;
    }
    if (line.startsWith("[offset:")) {
        bool ok;
        offset = line.mid(8, line.length() - 9).toInt(&ok);
        if (ok) {
            qDebug() << "Offset:" << offset;
        }
        return true;
    }

    return false;
}

bool Lyrices::parseTimestampLine(const QString &line, QString &text, qint64 &timestamp) const
{
    const QRegularExpression timestampRegex(R"(\[(\d{2}):(\d{2})\.(\d{2,3})\](.+))");
    QRegularExpressionMatch match = timestampRegex.match(line);

    if (match.hasMatch()) {
        QString minStr = match.captured(1);
        QString secStr = match.captured(2);
        QString msecStr = match.captured(3);
        text = match.captured(4);

        timestamp = parseTimestamp(minStr + ":" + secStr + "." + msecStr);
        return true;
    }
    return false;
}

qint64 Lyrices::parseTimestamp(const QString &timeStr) const
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

QString Lyrices::getLyricAtTime(qint64 time) const
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

QList<Lyrices::LyricLine> Lyrices::getAllLyrics() const
{
    return lyrics;
}
