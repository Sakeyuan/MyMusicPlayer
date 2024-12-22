#include "localmusicwidget.h"
#include "ui_localmusicwidget.h"


#include <QFileDialog>
#include <QMediaMetaData>

LocalMusicWidget::LocalMusicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocalMusicWidget)
{
    ui->setupUi(this);
    player = FPlayer::instance();
}

LocalMusicWidget::~LocalMusicWidget()
{
    delete ui;
}

QString LocalMusicWidget::getCurrentFilePath() const
{
    return this->filePath;
}

void LocalMusicWidget::on_addMusicBtn_clicked()
{
    QStringList fileList = QFileDialog::getOpenFileNames(
                this,
                tr("Add music files"),
                "D:\\Qt-Project\\MyMusicPlayer\\MyPlayMusic\\Music",
                tr("Music Files (*.mp3 *.wav *.flac *.ogg)")
                );

    for (const QString &filePath : fileList) {
        QFileInfo fileInfo(filePath);
        QString musicName = fileInfo.completeBaseName();
        QListWidgetItem *item = new QListWidgetItem(musicName, this->ui->localMusicListWidget);
        item->setData(Qt::UserRole,filePath);
        this->ui->localMusicListWidget->addItem(item);
    }
}

void LocalMusicWidget::on_localMusicListWidget_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    QListWidgetItem *item = this->ui->localMusicListWidget->item(index.row());
    filePath = item->data(Qt::UserRole).toString();
    player->addMedia(filePath);

    player->setCurrentIndex(row);
    player->setPlaybackMode(QMediaPlaylist::Loop);

    // 获取音频时长后发射信号
    connect(player->getMediaPlayer(), &QMediaPlayer::durationChanged, this, [this](qint64 duration) {
        emit durationChanged(duration);
    });
    connect(player->getMediaPlayer(), &QMediaPlayer::positionChanged, this, [this](qint64 position) {
            emit positionChanged(position);
        });
    player->play();
}

