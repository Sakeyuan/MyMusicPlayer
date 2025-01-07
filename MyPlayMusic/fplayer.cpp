#include "fplayer.h"
#include <QDebug>
#include <QFileInfo>

FPlayer* FPlayer::m_instance = nullptr;

FPlayer *FPlayer::instance()
{
    if(!m_instance){
        m_instance = new FPlayer();
    }
    return m_instance;
}

FPlayer::FPlayer(QObject *parent) : QObject(parent)
{
    m_mediaPlayer = new QMediaPlayer(this);
    m_playlist = new QMediaPlaylist(this);

    m_mediaPlayer->setPlaylist(m_playlist);

    connect(m_playlist,&QMediaPlaylist::currentMediaChanged,this,&FPlayer::onMediaChanged);
    connect(m_mediaPlayer, &QMediaPlayer::stateChanged, this, &FPlayer::onPlaybackStateChanged);
    connect(m_playlist,&QMediaPlaylist::playbackModeChanged,&FPlayer::playbackModeChanged);
}

FPlayer::~FPlayer()
{
    delete m_mediaPlayer;
    delete  m_playlist;
}

void FPlayer::next()
{
    qDebug() << "下一首";
    this->m_playlist->next();
    this->play();
}

void FPlayer::previous()
{
    qDebug() << "前一首";
    this->m_playlist->previous();
    this->play();
}

void FPlayer::play()
{
    if(m_playlist->isEmpty()){
        qWarning() << "Playlist is empty";
        return;
    }
    m_mediaPlayer->play();
}

void FPlayer::pause()
{
    if(m_mediaPlayer->state() == QMediaPlayer::PlayingState){
        m_mediaPlayer->pause();
    }
}

void FPlayer::stop()
{
    m_mediaPlayer->stop();
}

void FPlayer::setPosition(qint64 newPosition)
{
    this->m_mediaPlayer->setPosition(newPosition);
}

void FPlayer::setVolume(int volume)
{
    m_mediaPlayer->setVolume(volume);
}

void FPlayer::setPlaybackMode(QMediaPlaylist::PlaybackMode mode)
{
    m_playlist->setPlaybackMode(mode);
}

void FPlayer::addMedia(const QString &filePath)
{
    if(!QFileInfo::exists(filePath)){
        qWarning() << "file is not exits: " << filePath;
        return;
    }
    m_playlist->addMedia(QUrl::fromLocalFile(filePath));
}

void FPlayer::setMedia(const QString &filePath)
{
    m_mediaPlayer->setMedia(QUrl::fromLocalFile(filePath));
}

void FPlayer::setCurrentIndex(int index)
{
    m_playlist->setCurrentIndex(index);
}

QMediaPlayer *FPlayer::getMediaPlayer()
{
    return m_mediaPlayer;
}

QMediaPlaylist *FPlayer::getMediaPlayerlist()
{
    return m_playlist;
}

void FPlayer::onMediaChanged()
{
    if(!m_playlist->currentMedia().isNull()){
        QString currentMedia = m_playlist->currentMedia().canonicalUrl().toLocalFile();
        emit mediaChanged(currentMedia);
    }
}

void FPlayer::onPlaybackStateChanged(QMediaPlayer::State state)
{
    if(state == QMediaPlayer::StoppedState && m_playlist->playbackMode() == QMediaPlaylist::CurrentItemOnce){
        emit playbackFinished();
    }
}



