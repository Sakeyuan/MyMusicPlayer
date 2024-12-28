#include "lyricsparsetask.h"
#include <QDebug>
#include "lyrices.h"

LyricsParseTask::LyricsParseTask(const QString &filePath, QObject *parent)
    : QObject(parent), m_filePath(filePath) {}

void LyricsParseTask::run()
{
    Lyrices parser;
    LyricResult result;
    QString lrcPath = m_filePath;
    lrcPath.replace("mp3", "lrc");

    qDebug() << "Running lyrics parse task, filePath = " << lrcPath << "  Thread ID = " << QThread::currentThreadId();

    if (parser.loadFromFile(lrcPath, result)) {
        emit lyricParseFinish(result);
    } else {
        emit lyricParseFailed(lrcPath);
    }
}
