#ifndef LYRICSPARSETASK_H
#define LYRICSPARSETASK_H

#include <QObject>
#include <QRunnable>
#include "lyrices.h"

class LyricsParseTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit LyricsParseTask(const QString &filePath, QObject *parent = nullptr);

signals:
    void lyricParseFinish(const LyricResult &lyricResult);
    void lyricParseFailed(const QString &filePath);

protected:
    void run() override;

private:
    QString m_filePath;
};

#endif // LYRICSPARSETASK_H
