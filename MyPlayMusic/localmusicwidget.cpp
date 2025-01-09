#include "localmusicwidget.h"
#include "ui_localmusicwidget.h"
#include "databasemanager.h"
#include "queries.h"

#include <QFileDialog>
#include <QMediaMetaData>

LocalMusicWidget::LocalMusicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocalMusicWidget)
{
    ui->setupUi(this);
    player = FPlayer::instance();

    connect(player->getMediaPlayer(), &QMediaPlayer::durationChanged, this, [this](qint64 duration) {
        emit durationChanged(duration);
    });

    connect(player->getMediaPlayer(), &QMediaPlayer::positionChanged, this, [this](qint64 position) {
            emit positionChanged(position);
        });

    player->setPlaybackMode(QMediaPlaylist::Loop);

    connect(player->getMediaPlayerlist(), &QMediaPlaylist::currentIndexChanged, this, [this](int newIndex) {
        if (newIndex < 0 || newIndex >= this->ui->localMusicListWidget->count()) {
            qDebug() << "Invalid index:" << newIndex;
            return;
        }

        QListWidgetItem* currentItem = this->ui->localMusicListWidget->item(newIndex);
        if (currentItem) {
            this->ui->localMusicListWidget->setCurrentItem(currentItem);
            filePath = currentItem->data(Qt::UserRole).toString();
        } else {
            qDebug() << "Item at index" << newIndex << "is null.";
        }
    });

    loadMusicFromDatabase();
}

LocalMusicWidget::~LocalMusicWidget()
{
    delete ui;
}

QString LocalMusicWidget::getCurrentFilePath() const
{
    return this->filePath;
}

void LocalMusicWidget::loadMusicFromDatabase()
{
    DatabaseManager dbManager;
    QList<QVariantMap> musicLists = dbManager.queryData(SqlQueries::SelectAllMusic);
    for(const auto &music : musicLists){
        QString musicName = music.value("fileName").toString();
        QString filePath = music.value("filePath").toString();
        QListWidgetItem *item = new QListWidgetItem(musicName, this->ui->localMusicListWidget);
        item->setData(Qt::UserRole,filePath);
        this->ui->localMusicListWidget->addItem(item);
        this->player->addMedia(filePath);
    }
}

void LocalMusicWidget::on_addMusicBtn_clicked()
{
    QStringList fileList = QFileDialog::getOpenFileNames(
        this,
        tr("Add music files"),
        "D:\\Qt-Project\\MyMusicPlayer\\MyPlayMusic\\Music",
        tr("Music Files (*.mp3 *.wav *.flac *.ogg)")
    );

    if (fileList.isEmpty()) {
        return;
    }

    DatabaseManager dbManager;

    for (const QString &filePath : fileList) {
        QFileInfo fileInfo(filePath);
        QString musicName = fileInfo.completeBaseName();

        QVariantMap checkParams;
        checkParams[":filePath"] = filePath;

        if (!dbManager.insertData(SqlQueries::CheckMusicExists, checkParams)) {
            qDebug() << "Music already exists in the database: " << filePath;
            continue;
        }

        QVariantMap insertParams;
        insertParams[":filePath"] = filePath;
        insertParams[":fileName"] = musicName;

        if (!dbManager.insertData(SqlQueries::InsertMusic, insertParams)) {
            qDebug() << "Failed to insert music into database: " << filePath;
            continue;
        }

        QListWidgetItem *item = new QListWidgetItem(musicName, this->ui->localMusicListWidget);
        item->setData(Qt::UserRole, filePath);
        this->ui->localMusicListWidget->addItem(item);
        this->player->addMedia(filePath);
    }
}

void LocalMusicWidget::on_localMusicListWidget_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    QListWidgetItem *item = this->ui->localMusicListWidget->item(row);
    filePath = item->data(Qt::UserRole).toString();
    //player->setMedia(filePath);
    player->setCurrentIndex(row);
    player->play( );
}

