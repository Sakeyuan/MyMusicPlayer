/********************************************************************************
** Form generated from reading UI file 'mymusicplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMUSICPLAYER_H
#define UI_MYMUSICPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <musicmessage.h>
#include "qcarousel.h"

QT_BEGIN_NAMESPACE

class Ui_MyMusicPlayer
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *mainVerticalLayout;
    QWidget *topNavWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *topNavWidgetHorizontalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_logo_name;
    QLabel *label_logo;
    QSpacerItem *topHorizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *emailBtn;
    QPushButton *setingBtn;
    QLabel *label_line;
    QPushButton *shrinkBtn;
    QPushButton *enlargeBtn;
    QPushButton *closeBtn;
    QHBoxLayout *centerHorizontalLayout;
    QWidget *mainLeftWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QListWidget *recommendListWidget;
    QLabel *label_recomment;
    QListWidget *myMusicListWidget;
    QLabel *label_myMusic;
    QListWidget *createMusicListWidget;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_createMusicList;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QStackedWidget *mainCenterStackedWidget;
    QWidget *mainCenterStackedWidgetPage1;
    QVBoxLayout *verticalLayout;
    QTabWidget *centerTabWidget;
    QWidget *pRecommentTab;
    QVBoxLayout *verticalLayout_2;
    QCarousel *carouselWidget;
    QWidget *widget_2;
    QLabel *label;
    QWidget *songListTabBtn;
    QLabel *label_4;
    QWidget *radioTabBtn;
    QLabel *label_5;
    QWidget *rankTabBtn;
    QLabel *label_6;
    QWidget *songerTabBtn;
    QLabel *label_7;
    QWidget *recentMusicTabBtn;
    QLabel *label_8;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *bottomWidgetHorizontalLayout;
    MusicMessage *widget;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *bottomHLayout;
    QPushButton *preMusicBtn;
    QPushButton *stopMusicBtn;
    QPushButton *nextMusicBtn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *startTimeLabel;
    QSlider *musicTimeSlider;
    QLabel *endTimeLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *voiceBtn;
    QSlider *voiceSlider;
    QPushButton *playMusicListFormBtn;
    QPushButton *playModeBtn;
    QPushButton *showMusicTextBtn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *MyMusicPlayer)
    {
        if (MyMusicPlayer->objectName().isEmpty())
            MyMusicPlayer->setObjectName(QString::fromUtf8("MyMusicPlayer"));
        MyMusicPlayer->resize(1084, 775);
        MyMusicPlayer->setMinimumSize(QSize(1050, 750));
        MyMusicPlayer->setMaximumSize(QSize(16777215, 16777215));
        layoutWidget = new QWidget(MyMusicPlayer);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(5, -1, 1052, 741));
        mainVerticalLayout = new QVBoxLayout(layoutWidget);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        mainVerticalLayout->setContentsMargins(0, 0, 0, 0);
        topNavWidget = new QWidget(layoutWidget);
        topNavWidget->setObjectName(QString::fromUtf8("topNavWidget"));
        topNavWidget->setMinimumSize(QSize(1050, 55));
        topNavWidget->setMaximumSize(QSize(16777215, 16777215));
        topNavWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(236, 65, 65);"));
        horizontalLayout_2 = new QHBoxLayout(topNavWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        topNavWidgetHorizontalLayout = new QHBoxLayout();
        topNavWidgetHorizontalLayout->setSpacing(0);
        topNavWidgetHorizontalLayout->setObjectName(QString::fromUtf8("topNavWidgetHorizontalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_logo_name = new QLabel(topNavWidget);
        label_logo_name->setObjectName(QString::fromUtf8("label_logo_name"));
        label_logo_name->setMaximumSize(QSize(30, 30));
        label_logo_name->setStyleSheet(QString::fromUtf8("border-image: url(:/img/music.png);"));

        horizontalLayout_3->addWidget(label_logo_name);

        label_logo = new QLabel(topNavWidget);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        QFont font;
        font.setPointSize(12);
        label_logo->setFont(font);

        horizontalLayout_3->addWidget(label_logo);


        topNavWidgetHorizontalLayout->addLayout(horizontalLayout_3);

        topHorizontalSpacer = new QSpacerItem(500, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        topNavWidgetHorizontalLayout->addItem(topHorizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        emailBtn = new QPushButton(topNavWidget);
        emailBtn->setObjectName(QString::fromUtf8("emailBtn"));
        emailBtn->setMinimumSize(QSize(30, 30));
        emailBtn->setMaximumSize(QSize(30, 30));
        emailBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(emailBtn);

        setingBtn = new QPushButton(topNavWidget);
        setingBtn->setObjectName(QString::fromUtf8("setingBtn"));
        setingBtn->setMinimumSize(QSize(30, 30));
        setingBtn->setMaximumSize(QSize(30, 30));
        setingBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(setingBtn);

        label_line = new QLabel(topNavWidget);
        label_line->setObjectName(QString::fromUtf8("label_line"));
        label_line->setMinimumSize(QSize(20, 20));
        label_line->setMaximumSize(QSize(20, 30));
        label_line->setStyleSheet(QString::fromUtf8("border-image: url(:/img/vertical_line.png);"));

        horizontalLayout->addWidget(label_line);

        shrinkBtn = new QPushButton(topNavWidget);
        shrinkBtn->setObjectName(QString::fromUtf8("shrinkBtn"));
        shrinkBtn->setMinimumSize(QSize(30, 25));
        shrinkBtn->setMaximumSize(QSize(30, 30));
        shrinkBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(shrinkBtn);

        enlargeBtn = new QPushButton(topNavWidget);
        enlargeBtn->setObjectName(QString::fromUtf8("enlargeBtn"));
        enlargeBtn->setMinimumSize(QSize(30, 30));
        enlargeBtn->setMaximumSize(QSize(30, 30));
        enlargeBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(enlargeBtn);

        closeBtn = new QPushButton(topNavWidget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setMinimumSize(QSize(30, 25));
        closeBtn->setMaximumSize(QSize(30, 30));
        closeBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(closeBtn);


        topNavWidgetHorizontalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(topNavWidgetHorizontalLayout);


        mainVerticalLayout->addWidget(topNavWidget);

        centerHorizontalLayout = new QHBoxLayout();
        centerHorizontalLayout->setObjectName(QString::fromUtf8("centerHorizontalLayout"));
        mainLeftWidget = new QWidget(layoutWidget);
        mainLeftWidget->setObjectName(QString::fromUtf8("mainLeftWidget"));
        mainLeftWidget->setMinimumSize(QSize(175, 0));
        mainLeftWidget->setMaximumSize(QSize(16777215, 16777215));
        mainLeftWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 243, 246);"));
        scrollArea = new QScrollArea(mainLeftWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 180, 601));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 178, 599));
        recommendListWidget = new QListWidget(scrollAreaWidgetContents_3);
        recommendListWidget->setObjectName(QString::fromUtf8("recommendListWidget"));
        recommendListWidget->setGeometry(QRect(11, 33, 159, 171));
        recommendListWidget->setMaximumSize(QSize(16777215, 16777215));
        label_recomment = new QLabel(scrollAreaWidgetContents_3);
        label_recomment->setObjectName(QString::fromUtf8("label_recomment"));
        label_recomment->setGeometry(QRect(11, 11, 32, 16));
        label_recomment->setMaximumSize(QSize(16777215, 20));
        label_recomment->setFont(font);
        myMusicListWidget = new QListWidget(scrollAreaWidgetContents_3);
        myMusicListWidget->setObjectName(QString::fromUtf8("myMusicListWidget"));
        myMusicListWidget->setGeometry(QRect(11, 230, 159, 148));
        myMusicListWidget->setMaximumSize(QSize(16777215, 16777215));
        label_myMusic = new QLabel(scrollAreaWidgetContents_3);
        label_myMusic->setObjectName(QString::fromUtf8("label_myMusic"));
        label_myMusic->setGeometry(QRect(11, 210, 64, 16));
        label_myMusic->setMaximumSize(QSize(16777215, 20));
        label_myMusic->setFont(font);
        createMusicListWidget = new QListWidget(scrollAreaWidgetContents_3);
        createMusicListWidget->setObjectName(QString::fromUtf8("createMusicListWidget"));
        createMusicListWidget->setGeometry(QRect(11, 410, 159, 161));
        createMusicListWidget->setMaximumSize(QSize(16777215, 16777215));
        layoutWidget1 = new QWidget(scrollAreaWidgetContents_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 380, 161, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_createMusicList = new QLabel(layoutWidget1);
        label_createMusicList->setObjectName(QString::fromUtf8("label_createMusicList"));
        label_createMusicList->setFont(font);

        horizontalLayout_4->addWidget(label_createMusicList);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(30, 30));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/img/add.png);"));

        horizontalLayout_4->addWidget(pushButton);

        scrollArea->setWidget(scrollAreaWidgetContents_3);

        centerHorizontalLayout->addWidget(mainLeftWidget);

        mainCenterStackedWidget = new QStackedWidget(layoutWidget);
        mainCenterStackedWidget->setObjectName(QString::fromUtf8("mainCenterStackedWidget"));
        mainCenterStackedWidget->setMaximumSize(QSize(16777215, 16777215));
        mainCenterStackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 249, 252);"));
        mainCenterStackedWidgetPage1 = new QWidget();
        mainCenterStackedWidgetPage1->setObjectName(QString::fromUtf8("mainCenterStackedWidgetPage1"));
        verticalLayout = new QVBoxLayout(mainCenterStackedWidgetPage1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        centerTabWidget = new QTabWidget(mainCenterStackedWidgetPage1);
        centerTabWidget->setObjectName(QString::fromUtf8("centerTabWidget"));
        pRecommentTab = new QWidget();
        pRecommentTab->setObjectName(QString::fromUtf8("pRecommentTab"));
        verticalLayout_2 = new QVBoxLayout(pRecommentTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        carouselWidget = new QCarousel(pRecommentTab);
        carouselWidget->setObjectName(QString::fromUtf8("carouselWidget"));
        carouselWidget->setMaximumSize(QSize(16777215, 120));

        verticalLayout_2->addWidget(carouselWidget);

        widget_2 = new QWidget(pRecommentTab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 120, 81, 16));

        verticalLayout_2->addWidget(widget_2);

        centerTabWidget->addTab(pRecommentTab, QString());
        songListTabBtn = new QWidget();
        songListTabBtn->setObjectName(QString::fromUtf8("songListTabBtn"));
        label_4 = new QLabel(songListTabBtn);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 330, 201, 131));
        centerTabWidget->addTab(songListTabBtn, QString());
        radioTabBtn = new QWidget();
        radioTabBtn->setObjectName(QString::fromUtf8("radioTabBtn"));
        label_5 = new QLabel(radioTabBtn);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 280, 201, 131));
        centerTabWidget->addTab(radioTabBtn, QString());
        rankTabBtn = new QWidget();
        rankTabBtn->setObjectName(QString::fromUtf8("rankTabBtn"));
        label_6 = new QLabel(rankTabBtn);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 320, 201, 131));
        centerTabWidget->addTab(rankTabBtn, QString());
        songerTabBtn = new QWidget();
        songerTabBtn->setObjectName(QString::fromUtf8("songerTabBtn"));
        label_7 = new QLabel(songerTabBtn);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(310, 290, 201, 131));
        centerTabWidget->addTab(songerTabBtn, QString());
        recentMusicTabBtn = new QWidget();
        recentMusicTabBtn->setObjectName(QString::fromUtf8("recentMusicTabBtn"));
        label_8 = new QLabel(recentMusicTabBtn);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(330, 350, 201, 131));
        centerTabWidget->addTab(recentMusicTabBtn, QString());

        verticalLayout->addWidget(centerTabWidget);

        mainCenterStackedWidget->addWidget(mainCenterStackedWidgetPage1);

        centerHorizontalLayout->addWidget(mainCenterStackedWidget);


        mainVerticalLayout->addLayout(centerHorizontalLayout);

        bottomWidget = new QWidget(layoutWidget);
        bottomWidget->setObjectName(QString::fromUtf8("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 80));
        bottomWidget->setMaximumSize(QSize(16777215, 16777215));
        bottomWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 243, 246);"));
        horizontalLayout_5 = new QHBoxLayout(bottomWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        bottomWidgetHorizontalLayout = new QHBoxLayout();
        bottomWidgetHorizontalLayout->setObjectName(QString::fromUtf8("bottomWidgetHorizontalLayout"));
        widget = new MusicMessage(bottomWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(180, 80));
        widget->setMaximumSize(QSize(16777215, 16777215));

        bottomWidgetHorizontalLayout->addWidget(widget);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        bottomWidgetHorizontalLayout->addItem(horizontalSpacer_5);

        bottomHLayout = new QHBoxLayout();
        bottomHLayout->setSpacing(5);
        bottomHLayout->setObjectName(QString::fromUtf8("bottomHLayout"));
        preMusicBtn = new QPushButton(bottomWidget);
        preMusicBtn->setObjectName(QString::fromUtf8("preMusicBtn"));
        preMusicBtn->setMinimumSize(QSize(25, 25));
        preMusicBtn->setMaximumSize(QSize(25, 25));
        preMusicBtn->setStyleSheet(QString::fromUtf8(""));

        bottomHLayout->addWidget(preMusicBtn);

        stopMusicBtn = new QPushButton(bottomWidget);
        stopMusicBtn->setObjectName(QString::fromUtf8("stopMusicBtn"));
        stopMusicBtn->setMinimumSize(QSize(25, 25));
        stopMusicBtn->setMaximumSize(QSize(25, 25));
        stopMusicBtn->setStyleSheet(QString::fromUtf8(""));

        bottomHLayout->addWidget(stopMusicBtn);

        nextMusicBtn = new QPushButton(bottomWidget);
        nextMusicBtn->setObjectName(QString::fromUtf8("nextMusicBtn"));
        nextMusicBtn->setMinimumSize(QSize(25, 25));
        nextMusicBtn->setMaximumSize(QSize(25, 25));
        nextMusicBtn->setStyleSheet(QString::fromUtf8(""));

        bottomHLayout->addWidget(nextMusicBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        bottomHLayout->addItem(horizontalSpacer_2);

        startTimeLabel = new QLabel(bottomWidget);
        startTimeLabel->setObjectName(QString::fromUtf8("startTimeLabel"));

        bottomHLayout->addWidget(startTimeLabel);

        musicTimeSlider = new QSlider(bottomWidget);
        musicTimeSlider->setObjectName(QString::fromUtf8("musicTimeSlider"));
        musicTimeSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0px solid #ff0000;\n"
"    height: 4px;  /* \350\256\276\347\275\256\346\273\221\346\247\275\351\253\230\345\272\246 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(236, 65, 65);\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: rgb(255, 255, 255);\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: rgb(255, 255, 255);\n"
"    border: 0px solid #666666;\n"
"    border-radius: 6px; /* \345\234\206\345\275\242\346\273\221\345\235\227 */\n"
"    width: 12px;  /* \350\256\276\347\275\256\346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 12px; /* \350\256\276\347\275\256\346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin-top: -4px; /* \350\260\203\346\225\264\346\273\221\345\235\227\347\232\204\345\236\202\347\233\264\344\275\215\347\275\256 */\n"
"    margin-bottom: -4px;\n"
"}\n"
""));
        musicTimeSlider->setOrientation(Qt::Horizontal);

        bottomHLayout->addWidget(musicTimeSlider);

        endTimeLabel = new QLabel(bottomWidget);
        endTimeLabel->setObjectName(QString::fromUtf8("endTimeLabel"));

        bottomHLayout->addWidget(endTimeLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        bottomHLayout->addItem(horizontalSpacer);

        voiceBtn = new QPushButton(bottomWidget);
        voiceBtn->setObjectName(QString::fromUtf8("voiceBtn"));
        voiceBtn->setMinimumSize(QSize(25, 25));
        voiceBtn->setMaximumSize(QSize(25, 25));
        voiceBtn->setStyleSheet(QString::fromUtf8(""));

        bottomHLayout->addWidget(voiceBtn);

        voiceSlider = new QSlider(bottomWidget);
        voiceSlider->setObjectName(QString::fromUtf8("voiceSlider"));
        voiceSlider->setMinimumSize(QSize(100, 0));
        voiceSlider->setMaximumSize(QSize(100, 16777215));
        voiceSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0px solid #ff0000;\n"
"    height: 4px;  /* \350\256\276\347\275\256\346\273\221\346\247\275\351\253\230\345\272\246 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(0, 85, 255);\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: rgb(255,255,255);\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: rgb(255, 255, 255);\n"
"    border: 0px solid #666666;\n"
"    border-radius: 6px; /* \345\234\206\345\275\242\346\273\221\345\235\227 */\n"
"    width: 12px;  /* \350\256\276\347\275\256\346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 12px; /* \350\256\276\347\275\256\346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin-top: -4px; /* \350\260\203\346\225\264\346\273\221\345\235\227\347\232\204\345\236\202\347\233\264\344\275\215\347\275\256 */\n"
"    margin-bottom: -4px;\n"
"}\n"
""));
        voiceSlider->setOrientation(Qt::Horizontal);

        bottomHLayout->addWidget(voiceSlider);

        playMusicListFormBtn = new QPushButton(bottomWidget);
        playMusicListFormBtn->setObjectName(QString::fromUtf8("playMusicListFormBtn"));
        playMusicListFormBtn->setMaximumSize(QSize(25, 25));
        playMusicListFormBtn->setStyleSheet(QString::fromUtf8(""));

        bottomHLayout->addWidget(playMusicListFormBtn);

        playModeBtn = new QPushButton(bottomWidget);
        playModeBtn->setObjectName(QString::fromUtf8("playModeBtn"));
        playModeBtn->setMinimumSize(QSize(25, 25));
        playModeBtn->setMaximumSize(QSize(25, 25));
        playModeBtn->setStyleSheet(QString::fromUtf8(""));

        bottomHLayout->addWidget(playModeBtn);

        showMusicTextBtn = new QPushButton(bottomWidget);
        showMusicTextBtn->setObjectName(QString::fromUtf8("showMusicTextBtn"));
        showMusicTextBtn->setMinimumSize(QSize(25, 25));
        showMusicTextBtn->setMaximumSize(QSize(25, 25));
        showMusicTextBtn->setStyleSheet(QString::fromUtf8(""));

        bottomHLayout->addWidget(showMusicTextBtn);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        bottomHLayout->addItem(horizontalSpacer_4);


        bottomWidgetHorizontalLayout->addLayout(bottomHLayout);


        horizontalLayout_5->addLayout(bottomWidgetHorizontalLayout);


        mainVerticalLayout->addWidget(bottomWidget);


        retranslateUi(MyMusicPlayer);

        centerTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyMusicPlayer);
    } // setupUi

    void retranslateUi(QWidget *MyMusicPlayer)
    {
        MyMusicPlayer->setWindowTitle(QApplication::translate("MyMusicPlayer", "MyMusicPlayer", nullptr));
        label_logo_name->setText(QString());
        label_logo->setText(QApplication::translate("MyMusicPlayer", " \346\270\205\351\205\222\351\237\263\344\271\220", nullptr));
        emailBtn->setText(QString());
        setingBtn->setText(QString());
        label_line->setText(QString());
        shrinkBtn->setText(QString());
        enlargeBtn->setText(QString());
        closeBtn->setText(QString());
        label_recomment->setText(QApplication::translate("MyMusicPlayer", "\346\216\250\350\215\220", nullptr));
        label_myMusic->setText(QApplication::translate("MyMusicPlayer", "\346\210\221\347\232\204\351\237\263\344\271\220", nullptr));
        label_createMusicList->setText(QApplication::translate("MyMusicPlayer", "\345\210\233\345\273\272\347\232\204\346\255\214\345\215\225", nullptr));
        pushButton->setText(QString());
        label->setText(QApplication::translate("MyMusicPlayer", "\344\270\252\346\200\247\345\214\226\346\216\250\350\215\220", nullptr));
        centerTabWidget->setTabText(centerTabWidget->indexOf(pRecommentTab), QApplication::translate("MyMusicPlayer", "\344\270\252\346\200\247\346\216\250\350\215\220", nullptr));
        label_4->setText(QApplication::translate("MyMusicPlayer", " \346\255\214\345\215\225", nullptr));
        centerTabWidget->setTabText(centerTabWidget->indexOf(songListTabBtn), QApplication::translate("MyMusicPlayer", "\346\255\214\345\215\225", nullptr));
        label_5->setText(QApplication::translate("MyMusicPlayer", " \344\270\273\346\222\255\347\224\265\345\217\260", nullptr));
        centerTabWidget->setTabText(centerTabWidget->indexOf(radioTabBtn), QApplication::translate("MyMusicPlayer", "\344\270\273\346\222\255\347\224\265\345\217\260", nullptr));
        label_6->setText(QApplication::translate("MyMusicPlayer", " \346\216\222\350\241\214\346\246\234", nullptr));
        centerTabWidget->setTabText(centerTabWidget->indexOf(rankTabBtn), QApplication::translate("MyMusicPlayer", "\346\216\222\350\241\214\346\246\234", nullptr));
        label_7->setText(QApplication::translate("MyMusicPlayer", "\346\255\214\346\211\213", nullptr));
        centerTabWidget->setTabText(centerTabWidget->indexOf(songerTabBtn), QApplication::translate("MyMusicPlayer", "\346\255\214\346\211\213", nullptr));
        label_8->setText(QApplication::translate("MyMusicPlayer", "\346\234\200\346\226\260\351\237\263\344\271\220", nullptr));
        centerTabWidget->setTabText(centerTabWidget->indexOf(recentMusicTabBtn), QApplication::translate("MyMusicPlayer", "\346\234\200\346\226\260\351\237\263\344\271\220", nullptr));
        preMusicBtn->setText(QString());
        stopMusicBtn->setText(QString());
        nextMusicBtn->setText(QString());
        startTimeLabel->setText(QApplication::translate("MyMusicPlayer", "0.0", nullptr));
        endTimeLabel->setText(QApplication::translate("MyMusicPlayer", "10.1", nullptr));
        voiceBtn->setText(QString());
        playMusicListFormBtn->setText(QString());
        playModeBtn->setText(QString());
        showMusicTextBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyMusicPlayer: public Ui_MyMusicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMUSICPLAYER_H
