#include "mymusicplayer.h"
#include "ui_mymusicplayer.h"

#include <QDir>
#include <QtDebug>
#include <QString>
#include <qstyleditemdelegate.h>
#include <QStandardPaths>

class NoFocusDelegate : public QStyledItemDelegate
{
public:
    NoFocusDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyleOptionViewItem opt = option;
        // 禁用焦点效果
        opt.state &= ~QStyle::State_HasFocus;
        QStyledItemDelegate::paint(painter, opt, index);
    }
};

MyMusicPlayer::MyMusicPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyMusicPlayer),lyricWidget(nullptr),fplayer(FPlayer::instance()),playerState(QMediaPlayer::StoppedState)
    , playbackMode(QMediaPlaylist::Loop)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setLayout(ui->mainVerticalLayout);
    ui->bottomWidget->setLayout(ui->bottomWidgetHorizontalLayout);
    ui->topNavWidget->setLayout(ui->topNavWidgetHorizontalLayout);

    this->setMouseTracking(true);
    initTopABm();
    initLeftControl();
    initCenterControl();
    initCarousel();
    initLeftStackWidget();
    initBottom();
    initPlayer();
    initDataBase();
}

void MyMusicPlayer::initTopABm() {
    // 设置按钮样式
    QString BtnQSS = "QPushButton {"
                     "   background: transparent;"
                     "   border: none;"
                     "   "
                     "}"
                     "QPushButton:pressed {"
                     "   background-color: gray;"
                     "}";

    ui->enlargeBtn->setStyleSheet(BtnQSS);
    ui->closeBtn->setStyleSheet(BtnQSS);
    ui->shrinkBtn->setStyleSheet(BtnQSS);
    ui->setingBtn->setStyleSheet(BtnQSS);
    ui->emailBtn->setStyleSheet(BtnQSS);
    ui->preMusicBtn->setStyleSheet(BtnQSS);
    ui->stopMusicBtn->setStyleSheet(BtnQSS);
    ui->nextMusicBtn->setStyleSheet(BtnQSS);
    ui->voiceBtn->setStyleSheet(BtnQSS);
    ui->playMusicListFormBtn->setStyleSheet(BtnQSS);
    ui->playModeBtn->setStyleSheet(BtnQSS);
    ui->showMusicTextBtn->setStyleSheet(BtnQSS);

    QString LabelQSS = "background: transparent; border: none; ";
    ui->startTimeLabel->setStyleSheet(LabelQSS);
    ui->endTimeLabel->setStyleSheet(LabelQSS);

    // 初始化按钮图标
    updateButtonIcon(ui->enlargeBtn,":/img/enlarge.png",30);
    updateButtonIcon(ui->closeBtn,":/img/close.png",30);
    updateButtonIcon(ui->shrinkBtn,":/img/subtract.png",30);
    updateButtonIcon(ui->setingBtn,":/img/seting.png",30);
    updateButtonIcon(ui->emailBtn,":/img/email.png",30);
    updateButtonIcon(ui->preMusicBtn,":/img/preMusic.png",25);
    updateButtonIcon(ui->stopMusicBtn,":/img/stop.png",25);
    updateButtonIcon(ui->nextMusicBtn,":/img/nextMusic.png",25);
    updateButtonIcon(ui->voiceBtn,":/img/voice.svg",25);
    updateButtonIcon(ui->playMusicListFormBtn,":/img/playListForm.png",25);
    updateButtonIcon(ui->playModeBtn,":/img/listCircle.svg",25);
    updateButtonIcon(ui->showMusicTextBtn,":/img/lyric.svg",30);

    // 保存初始位置
    QPoint originalPos = this->pos();

    // 放大缩小
    connect(ui->enlargeBtn, &QPushButton::clicked, this, [=]() mutable {
        if (this->isMaximized()) {
            this->showNormal();
            updateButtonIcon(ui->enlargeBtn,":/img/enlarge.png",30);

            // 恢复原始位置
            this->move(originalPos);
        }
        else {
            // 保存最大化前的位置
            originalPos = this->pos();

            this->showMaximized();
            updateButtonIcon(ui->enlargeBtn,":/img/reduce.png",30);
            QTimer::singleShot(100, this, [=]() {
                this->move(0, 0); // 调整为期望的位置
            });
        }
    });

}

void MyMusicPlayer::initLeftControl()
{
    const QString leftSlideTextQSS = "QListWidget{color:rgb(18, 20, 25); background:rgb(240, 243, 246);border:0px solid gray;}"
                                     "QListWidget::Item{height:30px;border:0px solid gray;padding-left:15;}"
                                     "QListWidget::Item:hover{color:rgb(18, 20, 25);background:transparent;border:0px solid gray;}"
                                     "QListWidget::Item:selected{background:rgb(204, 204, 204);color:rgb(18, 20, 25);border-width:0;}"
                                     "QListWidget::Item:selected:active{background:rgb(204, 204, 204);color:rgb(18, 20, 25);border-width:0;}";
    setLeftTextFontSize(12);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);
    ui->recommendListWidget->setStyleSheet(leftSlideTextQSS);
    ui->recommendListWidget->setItemDelegate(new NoFocusDelegate(this));

    QListWidgetItem *add_item_0 = new QListWidgetItem(ui->recommendListWidget);
    add_item_0->setIcon(QIcon(":/img/home.png"));
    add_item_0->setText("首页");
    add_item_0->setFont(leftTextFont);

    QListWidgetItem *add_item_1 = new QListWidgetItem(ui->recommendListWidget);
    add_item_1->setIcon(QIcon(":/img/leftMusic.png"));
    add_item_1->setText("发现音乐");
    add_item_1->setFont(leftTextFont);

    QListWidgetItem *add_item_2 = new QListWidgetItem(ui->recommendListWidget);
    add_item_2->setIcon(QIcon(":/img/leftFM.png"));
    add_item_2->setText("私人FM");
    add_item_2->setFont(leftTextFont);

    QListWidgetItem *add_item_3 = new QListWidgetItem(ui->recommendListWidget);
    add_item_3->setIcon(QIcon(":/img/leftVideo.png"));
    add_item_3->setText("MV");
    add_item_3->setFont(leftTextFont);

    QListWidgetItem *add_item_4 = new QListWidgetItem(ui->recommendListWidget);
    add_item_4->setIcon(QIcon(":/img/leftFriends.png"));
    add_item_4->setText("朋友");
    add_item_4->setFont(leftTextFont);

    ui->myMusicListWidget->setStyleSheet(leftSlideTextQSS);
    ui->myMusicListWidget->setItemDelegate(new NoFocusDelegate(this));

    QListWidgetItem *add_item_5 = new QListWidgetItem(ui->myMusicListWidget);
    add_item_5->setIcon(QIcon(":/img/leftMusic.png"));
    add_item_5->setText("本地音乐");
    add_item_5->setFont(leftTextFont);

    QListWidgetItem *add_item_6 = new QListWidgetItem(ui->myMusicListWidget);
    add_item_6->setIcon(QIcon(":/img/leftDownload.png"));
    add_item_6->setText("下载管理");
    add_item_6->setFont(leftTextFont);

    QListWidgetItem *add_item_7 = new QListWidgetItem(ui->myMusicListWidget);
    add_item_7->setIcon(QIcon(":/img/leftPower.png"));
    add_item_7->setText("我的电台");
    add_item_7->setFont(leftTextFont);

    QListWidgetItem *add_item_8 = new QListWidgetItem(ui->myMusicListWidget);
    add_item_8->setIcon(QIcon(":/img/collect.png"));
    add_item_8->setText("我的收藏");
    add_item_8->setFont(leftTextFont);

    ui->createMusicListWidget->setStyleSheet(leftSlideTextQSS);
    ui->createMusicListWidget->setItemDelegate(new NoFocusDelegate(this));
    ui->createMusicListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->createMusicListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QListWidgetItem *add_item_9 = new QListWidgetItem(ui->createMusicListWidget);
    add_item_9->setIcon(QIcon(":/img/leftMusicList.png"));
    add_item_9->setText("我的歌单" + QString::number(ui->createMusicListWidget->count()));
    add_item_9->setFont(leftTextFont);
}

void MyMusicPlayer::initCenterControl()
{
    QString mainStyle =
            "QTabWidget::pane#centerTabWidget {"
            "    border-top: 2px solid #00C2C7CB;"
            "    position: absolute;"
            "    top: 10px;"
            "    background: #002d2f33;"
            "}"
            "QTabWidget#centerTabWidget::tab-bar {"
            "    alignment: center;"
            "}"
            // Tab bar styling
            "QTabBar::tab {"
            "    background: #00000000;"
            "    border: none;"
            "    border-bottom: 1.5px solid #dcdde4;"
            "    min-width: 10px;"
            "    margin-right: 20px;"
            "    padding-left: 20px;"
            "    padding-right: 20px;"
            "    padding-top: 5px;"
            "    padding-bottom: 5px;"
            "    color: #686a6e;"
            "    font-size: 12px;"
            "}"
            "QTabBar::tab:hover {"
            "    background: rgb(240, 243, 246);"
            "}"
            "QTabBar::tab:selected {"
            "    border-color: #3a3a3f;"
            "    color: #3c3e42;"
            "    border-bottom-color: #3c3e42;"
            "}";

    ui->centerTabWidget->setStyleSheet(mainStyle);
}

void MyMusicPlayer::initCarousel()
{
    ui->carouselWidget->addImage(QPixmap(":/CarouselImg/1.jpg"));
    ui->carouselWidget->addImage(QPixmap(":/CarouselImg/2.jpg"));
    ui->carouselWidget->addImage(QPixmap(":/CarouselImg/3.jpg"));
    ui->carouselWidget->addImage(QPixmap(":/CarouselImg/4.jpg"));
    ui->carouselWidget->addImage(QPixmap(":/CarouselImg/5.jpg"));
    ui->carouselWidget->setPixmapSize(QSize(500,120));
    ui->carouselWidget->setCurrentIndex(0);
    ui->carouselWidget->setAutoSlide(3000);
}

void MyMusicPlayer::initLeftStackWidget()
{
    // 定义偏移量
    const int recommendOffset = 0;
    const int musicListOffset = ui->recommendListWidget->count();

    // 创建并初始化 QWidget 对象
    this->findMusicWidget = new QWidget(this);
    this->privateFMWidget = new QWidget(this);
    this->MVWidget = new QWidget(this);
    this->friendWidget = new QWidget(this);
    this->localMusicWidget = new LocalMusicWidget(this);
    this->downloadManagerWidget = new QWidget(this);
    this->myRadioWidget = new QWidget(this);
    this->myCollectWidget = new QWidget(this);

    // 将 QWidget 对象指针添加到 QList 中
    QList<QWidget*> pages = {
        findMusicWidget,
        privateFMWidget,
        MVWidget,
        friendWidget,
        localMusicWidget,
        downloadManagerWidget,
        myRadioWidget,
        myCollectWidget
    };

    // 添加页面到 QStackedWidget
    for (QWidget* page : pages) {
        ui->mainCenterStackedWidget->addWidget(page);
    }

    ui->mainCenterStackedWidget->setCurrentIndex(0);

    connect(ui->recommendListWidget, &QListWidget::itemClicked, this, [this, recommendOffset](QListWidgetItem* item) {
        int index = ui->recommendListWidget->row(item);
        ui->mainCenterStackedWidget->setCurrentIndex(recommendOffset + index);
    });

    connect(ui->myMusicListWidget, &QListWidget::itemClicked, this, [this, musicListOffset](QListWidgetItem* item) {
        int index = ui->myMusicListWidget->row(item);
        ui->mainCenterStackedWidget->setCurrentIndex(musicListOffset + index);
    });
}

void MyMusicPlayer::initBottom()
{
    // 初始音量
    this->ui->voiceSlider->setValue(currentVolume);
    connect(this->ui->preMusicBtn,&QPushButton::clicked,this->fplayer,&FPlayer::previous);
    connect(this->ui->nextMusicBtn,&QPushButton::clicked,this->fplayer,&FPlayer::next);
    connect(this->localMusicWidget,&LocalMusicWidget::durationChanged,this,&MyMusicPlayer::musicPlayerDurationChanged);
    connect(this->localMusicWidget,&LocalMusicWidget::positionChanged,this,&MyMusicPlayer::onPositionChanged);
}

void MyMusicPlayer::initPlayer()
{
    //    connect(fplayer->getMediaPlayerlist(), &QMediaPlaylist::currentIndexChanged, this, [this](int newIndex) {
    //        if (newIndex >= 0) {
    //            if(this->currentLyrics.isValid()){
    //                QMutexLocker locker(&mutex);
    //                Lyrices::clearLyricResult(this->currentLyrics);
    //            }
    //            this->loadLyricsAsync();
    //        }
    //    });

    connect(fplayer,&FPlayer::mediaChanged,this,&MyMusicPlayer::musicChanged);
    connect(fplayer,&FPlayer::playbackModeChanged,this,&MyMusicPlayer::playbackModeChanged);

    connect(fplayer->getMediaPlayer(),&QMediaPlayer::stateChanged,[this](QMediaPlayer::State state){
        this->playerState = state;
        if(this->playerState == QMediaPlayer::PausedState || this->playerState == QMediaPlayer::StoppedState){
            updateButtonIcon(this->ui->stopMusicBtn,":/img/play.png",25);
        }
        else{
            updateButtonIcon(this->ui->stopMusicBtn,":/img/stop.png",25);
        }
    });


}

void MyMusicPlayer::initDataBase()
{
    DatabaseManager dbManager;
    if (!dbManager.connect()) {
        qWarning() << "Failed to connect to the database at:";
        return;
    }

    // 创建表
    if (!dbManager.createTable(SqlQueries::CreateMusicLibraryTable)) {
        qDebug() << "Failed to create table.";
        return;
    }
    qDebug() << "Table created successfully.";
}

void MyMusicPlayer::initLyricParser()
{

}

void MyMusicPlayer::updateButtonIcon(QPushButton* btn,const QString &iconPath,const int iconSize) {
    QPixmap pixmap(iconPath);
    QPixmap scaledPixmap = pixmap.scaled(iconSize, iconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    btn->setIcon(QIcon(scaledPixmap));
    btn->setIconSize(scaledPixmap.size());
}

void MyMusicPlayer::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        dragStartPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void MyMusicPlayer::mouseMoveEvent(QMouseEvent *event) {
    if (dragging) {
        QPoint newPos = event->globalPos() - dragStartPosition;
        move(newPos);
        event->accept();
    }
}

void MyMusicPlayer::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = false;
        event->accept();
    }
}

MyMusicPlayer::~MyMusicPlayer()
{
    delete ui;
}

void MyMusicPlayer::setLeftTextFontSize(int size)
{
    this->leftTextFont.setPointSize(size);
}

PlayMusicListForm *MyMusicPlayer::getPlayMusicListFormInstance()
{
    static PlayMusicListForm* instance = nullptr;
    if(nullptr == instance){
        instance = new PlayMusicListForm(this);
    }
    return instance;
}

bool MyMusicPlayer::loadLyricsAsync(QString filePath)
{
    qDebug() << "解析歌词中......";
    if(filePath.isEmpty()){
        qDebug() << "歌曲为空";
        return false;
    }
    auto *task = new LyricsParseTask(filePath);

    connect(task, &LyricsParseTask::lyricParseFinish, this, &MyMusicPlayer::showLyrics);
    connect(task, &LyricsParseTask::lyricParseFailed, this, [](const QString &filePath) {
        qDebug() << "Failed to parse lyrics for:" << filePath;
    });

    task->setAutoDelete(true);

    QThreadPool::globalInstance()->start(task);

    return true;
}

LyricResult &MyMusicPlayer::getLyricResult()
{
    return this->currentLyrics;
}

void MyMusicPlayer::on_closeBtn_clicked()
{
    this->close();
}

void MyMusicPlayer::musicChanged(QString filePath)
{
    if(this->currentLyrics.isValid()){
        QMutexLocker locker(&mutex);
        Lyrices::clearLyricResult(this->currentLyrics);
    }
    this->loadLyricsAsync(filePath);
}

void MyMusicPlayer::on_shrinkBtn_clicked()
{
    this->showMinimized();
}

void MyMusicPlayer::on_pushButton_clicked()
{
    QListWidgetItem *add_item = new QListWidgetItem(ui->createMusicListWidget);
    add_item->setIcon(QIcon(":/img/leftMusicList.png"));
    add_item->setText("我的歌单" + QString::number(ui->createMusicListWidget->count()));
    add_item->setFont(leftTextFont);
}

void MyMusicPlayer::on_recommendListWidget_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item);
    ui->myMusicListWidget->clearSelection();
    ui->createMusicListWidget->clearSelection();
}

void MyMusicPlayer::on_myMusicListWidget_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item);
    ui->recommendListWidget->clearSelection();
    ui->createMusicListWidget->clearSelection();
}

void MyMusicPlayer::on_createMusicListWidget_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item);
    ui->recommendListWidget->clearSelection();
    ui->myMusicListWidget->clearSelection();
}

void MyMusicPlayer::on_playMusicListFormBtn_clicked()
{
    PlayMusicListForm* playMusicListForm = getPlayMusicListFormInstance();

    if (playMusicListForm->isVisible()) {
        playMusicListForm->hide();
    }
    else {
        playMusicListForm->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

        int parentWidth = this->width();
        int parentHeight = this->height();

        int parentX = this->x();
        int parentY = this->y();

        int childWidth = playMusicListForm->width();
        int childHeight = playMusicListForm->height();

        int x = parentX + parentWidth - childWidth;
        int y = parentY + parentHeight - childHeight;

        playMusicListForm->move(x, y - ui->bottomWidget->height());

        playMusicListForm->show();
    }
}

void MyMusicPlayer::musicPlayerDurationChanged(qint64 duration) {
    if (duration < 0){
        return;
    }
    ui->musicTimeSlider->setMaximum(duration);
    ui->endTimeLabel->setText(Util::formatTime(duration));
}

void MyMusicPlayer::onPositionChanged(qint64 position) {
    if (position < 0){
        return;
    }
    ui->musicTimeSlider->setSliderPosition(position);
    ui->startTimeLabel->setText(Util::formatTime(position));
    if(isShowLyrics && this->lyricWidget && this->lyricWidget->isVisible()){
        QString lyrics = Lyrices::getLyricAtTime(position,this->currentLyrics.lyrics);
        this->lyricWidget->setLyrics(lyrics);
    }
}

void MyMusicPlayer::on_musicTimeSlider_sliderMoved(int position)
{
    qint64 newPosition = static_cast<qint64>(position);
    fplayer->setPosition(newPosition);
}

void MyMusicPlayer::on_voiceSlider_sliderMoved(int position)
{
    currentVolume = position;
    fplayer->setVolume(position);
    if(currentVolume == 0){
        this->updateButtonIcon(this->ui->voiceBtn,":/img/notvoice.svg",25);
    }
    else{
        this->updateButtonIcon(this->ui->voiceBtn,":/img/voice.svg",25);
    }
}

void MyMusicPlayer::on_showMusicTextBtn_clicked()
{
    if (!isShowLyrics) {
        if (lyricWidget == nullptr) {
            lyricWidget = new LyricCardWidget(this);
            lyricWidget->setWindowFlags(Qt::Tool);
        }
        isShowLyrics = true;
        if (lyricWidget) {
            lyricWidget->show();
        }
        this->lyricWidget->setLyrics("歌词加载中......");
        this->updateButtonIcon(this->ui->showMusicTextBtn,":/img/lyricClicked.svg",30);
    }
    else {
        isShowLyrics = false;

        if (lyricWidget) {
            lyricWidget->hide();
        }
        this->updateButtonIcon(this->ui->showMusicTextBtn,":/img/lyric.svg",30);
    }
}

void MyMusicPlayer::showLyrics(const LyricResult &result)
{
    this->currentLyrics = result;
    QString title = currentLyrics.title;
    QString artist = currentLyrics.artist;
    this->ui->musicMessage->setAuthor(artist);
    this->ui->musicMessage->setTitle(title);
    qDebug() << "-----歌词解析完毕-----";
}

void MyMusicPlayer::on_stopMusicBtn_clicked()
{
    if(this->playerState == QMediaPlayer::PlayingState){
        this->fplayer->pause();
        updateButtonIcon(ui->stopMusicBtn,":/img/play.png",25);
    }
    else if(this->playerState == QMediaPlayer::PausedState){
        this->fplayer->play();
        updateButtonIcon(ui->stopMusicBtn,":/img/stop.png",25);
    }
    else{
        this->fplayer->stop();
        updateButtonIcon(ui->stopMusicBtn,":/img/stop.png",25);
    }
}

void MyMusicPlayer::on_voiceBtn_clicked()
{
    if(currentVolume != 0){
        updateButtonIcon(ui->voiceBtn,":/img/notvoice.svg",25);
        currentVolume = 0;
    }
    else{
        updateButtonIcon(ui->voiceBtn,":/img/voice.svg",25);
        currentVolume = 80;
    }
    this->ui->voiceSlider->setValue(currentVolume);
    this->fplayer->setVolume(currentVolume);
}

void MyMusicPlayer::on_playModeBtn_clicked()
{
    switch (this->playbackMode) {
    case QMediaPlaylist::CurrentItemOnce:
        this->playbackMode = QMediaPlaylist::CurrentItemInLoop;
        this->updateButtonIcon(this->ui->playModeBtn,":/img/singleCircle.svg",25);
        qDebug() << "单曲循环";
        break;
    case QMediaPlaylist::CurrentItemInLoop:
        this->playbackMode = QMediaPlaylist::Sequential;
        this->updateButtonIcon(this->ui->playModeBtn,":/img/sequential.svg",25);
        qDebug() << "列表顺序播放";
        break;
    case QMediaPlaylist::Sequential:
        this->playbackMode = QMediaPlaylist::Loop;
        this->updateButtonIcon(this->ui->playModeBtn,":/img/listCircle.svg",25);
        qDebug() << "列表循环播放";
        break;
    case QMediaPlaylist::Loop:
        this->playbackMode = QMediaPlaylist::Random;
        this->updateButtonIcon(this->ui->playModeBtn,":/img/randomCircle.svg",25);
        qDebug() << "随机播放";
        break;
    case QMediaPlaylist::Random:
        this->playbackMode = QMediaPlaylist::CurrentItemOnce;
        this->updateButtonIcon(this->ui->playModeBtn,":/img/single.svg",25);
        qDebug() << "单曲";
        break;
    }
    this->fplayer->setPlaybackMode(this->playbackMode);
}

void MyMusicPlayer::playbackModeChanged(QMediaPlaylist::PlaybackMode playbackMode)
{
    this->playbackMode = playbackMode;
}

