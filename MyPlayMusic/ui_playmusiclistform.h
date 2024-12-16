/********************************************************************************
** Form generated from reading UI file 'playmusiclistform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYMUSICLISTFORM_H
#define UI_PLAYMUSICLISTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playMusicListForm
{
public:
    QWidget *playMusicListFormTopWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QPushButton *playListBtn;
    QPushButton *historyRecordBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *playMusicListForm)
    {
        if (playMusicListForm->objectName().isEmpty())
            playMusicListForm->setObjectName(QString::fromUtf8("playMusicListForm"));
        playMusicListForm->resize(526, 587);
        playMusicListForm->setMinimumSize(QSize(500, 50));
        playMusicListForm->setMaximumSize(QSize(1000, 1000));
        playMusicListFormTopWidget = new QWidget(playMusicListForm);
        playMusicListFormTopWidget->setObjectName(QString::fromUtf8("playMusicListFormTopWidget"));
        playMusicListFormTopWidget->setGeometry(QRect(1, 1, 500, 50));
        playMusicListFormTopWidget->setMinimumSize(QSize(500, 50));
        playMusicListFormTopWidget->setMaximumSize(QSize(1000, 1000));
        playMusicListFormTopWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 37, 42);"));
        widget = new QWidget(playMusicListFormTopWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 10, 359, 42));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(41, 43, 48);"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 5, 0, 5);
        playListBtn = new QPushButton(widget_3);
        playListBtn->setObjectName(QString::fromUtf8("playListBtn"));
        playListBtn->setMinimumSize(QSize(100, 30));
        playListBtn->setMaximumSize(QSize(100, 50));
        playListBtn->setStyleSheet(QString::fromUtf8(""));
        playListBtn->setCheckable(false);
        playListBtn->setAutoExclusive(false);

        gridLayout->addWidget(playListBtn, 0, 0, 1, 1);

        historyRecordBtn = new QPushButton(widget_3);
        historyRecordBtn->setObjectName(QString::fromUtf8("historyRecordBtn"));
        historyRecordBtn->setMinimumSize(QSize(100, 30));
        historyRecordBtn->setMaximumSize(QSize(80, 30));
        historyRecordBtn->setStyleSheet(QString::fromUtf8(""));
        historyRecordBtn->setCheckable(false);
        historyRecordBtn->setAutoExclusive(false);

        gridLayout->addWidget(historyRecordBtn, 0, 1, 1, 1);


        horizontalLayout->addWidget(widget_3);

        horizontalSpacer = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(25, 25));
        pushButton->setMaximumSize(QSize(25, 25));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/img/close.png);"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(playMusicListForm);

        QMetaObject::connectSlotsByName(playMusicListForm);
    } // setupUi

    void retranslateUi(QWidget *playMusicListForm)
    {
        playMusicListForm->setWindowTitle(QApplication::translate("playMusicListForm", "Form", nullptr));
        playListBtn->setText(QApplication::translate("playMusicListForm", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        historyRecordBtn->setText(QApplication::translate("playMusicListForm", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class playMusicListForm: public Ui_playMusicListForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYMUSICLISTFORM_H
