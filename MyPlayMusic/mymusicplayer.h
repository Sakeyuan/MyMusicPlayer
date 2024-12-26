#ifndef MYMUSICPLAYER_H
#define MYMUSICPLAYER_H

#include <QWidget>
#include <QStyle>
#include <qevent.h>
#include <qlistwidget.h>
#include <QThreadPool>
#include <QRunnable>
#include <QPointer>
#include "playmusiclistform.h"
#include "localmusicwidget.h"
#include "util.h"
#include "lyriccardwidget.h"
#include "lyrices.h"
#include "databasemanager.h"
#include "queries.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyMusicPlayer; }
QT_END_NAMESPACE

class MyMusicPlayer : public QWidget
{
    Q_OBJECT

public:
    MyMusicPlayer(QWidget *parent = nullptr);
    ~MyMusicPlayer();

    void setLeftTextFontSize(int size = 14);
    PlayMusicListForm* getPlayMusicListFormInstance();
    bool loadLyricsAsync();

    LyricResult& getLyricResult();

private slots:
    void on_closeBtn_clicked();

    void on_shrinkBtn_clicked();

    void on_pushButton_clicked();

    void on_recommendListWidget_itemClicked(QListWidgetItem *item);

    void on_myMusicListWidget_itemClicked(QListWidgetItem *item);

    void on_createMusicListWidget_itemClicked(QListWidgetItem *item);

    void on_playMusicListFormBtn_clicked();

    void musicPlayerDurationChanged(qint64 duration);

    void onPositionChanged(qint64 position);

    void on_musicTimeSlider_sliderMoved(int position);

    void on_showMusicTextBtn_clicked();

    void showLyrics();

signals:
    void lyricParseFinish();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool dragging;                              // 标记是否正在拖动
    QPoint dragStartPosition;                   // 鼠标按下时的位置
    QFont leftTextFont;                         // 左边标签大小
    QWidget* findMusicWidget;                   // 发现音乐堆栈窗口
    QWidget* privateFMWidget;                   // 私人FM堆栈窗口
    QWidget* MVWidget;                          // MV堆栈窗口
    QWidget* friendWidget;                      // 朋友堆栈窗口
    LocalMusicWidget* localMusicWidget;          // 本地音乐堆栈窗口
    QWidget* downloadManagerWidget;             // 下载管理堆栈窗口
    QWidget* myRadioWidget;                     // 我的电台堆栈窗口
    QWidget* myCollectWidget;                   // 我的收藏堆栈窗口

    bool isShowLyrics;                          // 是否正在显示歌词
    LyricCardWidget* lyricWidget;               // 歌词界面
    FPlayer* fplayer;                           // 播放器
    LyricResult currentLyrics;                  // 当前歌词
    Lyrices lyricParser;


private:
    Ui::MyMusicPlayer *ui;

    void initTopABm();
    void initLeftControl();
    void initCenterControl();
    void initCarousel();
    void initLeftStackWidget();
    void initBottom();
    void initPlayer();
    void initDataBase();
    void initLyricParser();
    void updateButtonIcon(QPushButton* btn, const QString &iconPath,const int iconSize);

private:
    struct LyricsParseTask : public QRunnable
    {
    public:
        explicit LyricsParseTask(MyMusicPlayer* player)
            : player(player) {}

        void run() override;

    private:
        MyMusicPlayer* player;
    };
};
#endif // MYMUSICPLAYER_H
