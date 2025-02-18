#ifndef FPLAYER_H
#define FPLAYER_H
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
extern "C" {
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
    #include <libavutil/avutil.h>
    #include <libswscale/swscale.h>
}

class FPlayer : public QObject
{
    Q_OBJECT
public:
    static FPlayer* instance();

    FPlayer(const FPlayer&) = delete;
    FPlayer& operator=(const FPlayer&) = delete;

    // 控制播放
    void play();
    void pause();
    void stop();

    // 设置歌曲播放位置
    void setPosition(qint64 newPosition);

    // 设置音量
    void setVolume(int volume);

    //设置播放模式
    void setPlaybackMode(QMediaPlaylist::PlaybackMode mode);

    // 播放列表管理
    void addMedia(const QString& filePath);
    void setMedia(const QString& filePath);
    void clearPlaylist();
    void setCurrentIndex(int index);

    QMediaPlayer* getMediaPlayer();
    QMediaPlaylist* getMediaPlayerlist();

private:
    explicit FPlayer(QObject *parent = nullptr);
    ~FPlayer();

signals:
    void mediaChanged(const QString& currentMedia);
    void playbackFinished();
    void playbackModeChanged(QMediaPlaylist::PlaybackMode mode);

public slots:
    void next();
    void previous();

private slots:
    void onMediaChanged();
    void onPlaybackStateChanged(QMediaPlayer::State state);

private:
    QMediaPlayer* m_mediaPlayer;
    QMediaPlaylist* m_playlist;
    QString filePath = "";
    static FPlayer* m_instance;
};

#endif // FPLAYER_H
