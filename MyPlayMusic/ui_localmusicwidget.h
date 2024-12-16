/********************************************************************************
** Form generated from reading UI file 'localmusicwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALMUSICWIDGET_H
#define UI_LOCALMUSICWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocalMusicWidget
{
public:
    QWidget *widget;
    QLabel *label;
    QPushButton *playAllMusicBtn;
    QListWidget *localMusicListWidget;
    QPushButton *addMusicBtn;

    void setupUi(QWidget *LocalMusicWidget)
    {
        if (LocalMusicWidget->objectName().isEmpty())
            LocalMusicWidget->setObjectName(QString::fromUtf8("LocalMusicWidget"));
        LocalMusicWidget->resize(685, 494);
        widget = new QWidget(LocalMusicWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 621, 431));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 121, 61));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent;    /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black;                /* \345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"    font-size: 18px;                 /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-family: 'Comic Sans MS';   /* \345\255\227\344\275\223\347\261\273\345\236\213 */\n"
"    padding: 8px;                   /* \345\206\205\350\276\271\350\267\235 */\n"
"    margin: 10px;                   /* \345\244\226\350\276\271\350\267\235 */\n"
"    text-align: right;              /* \346\226\207\346\234\254\345\257\271\351\275\220\346\226\271\345\274\217 */\n"
"    border-radius: 5px;             /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"}\n"
""));
        playAllMusicBtn = new QPushButton(widget);
        playAllMusicBtn->setObjectName(QString::fromUtf8("playAllMusicBtn"));
        playAllMusicBtn->setGeometry(QRect(120, 20, 121, 41));
        playAllMusicBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;               /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white;                        /* \345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"    font-size: 18px;                     /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-family: 'Comic Sans MS';        /* \345\255\227\344\275\223\347\261\273\345\236\213 */\n"
"    font-weight: bold;                   /* \345\255\227\344\275\223\345\212\240\347\262\227 */\n"
"    \n"
"    padding: 10px;\n"
"    text-align: right;                   /* \346\226\207\346\234\254\345\257\271\351\275\220\346\226\271\345\274\217 */\n"
"    border-radius: 5px;                  /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    qproperty-icon: url(:/img/playAll.png);  /* \346\214\211\351\222\256\345\233\276\346\240\207 */\n"
"    qproperty-iconSize: 24px 24px;       /* \345\233\276\346\240\207\345\244\247\345\260\217 */\n"
"}\n"
""));
        localMusicListWidget = new QListWidget(widget);
        localMusicListWidget->setObjectName(QString::fromUtf8("localMusicListWidget"));
        localMusicListWidget->setGeometry(QRect(50, 80, 531, 321));
        addMusicBtn = new QPushButton(widget);
        addMusicBtn->setObjectName(QString::fromUtf8("addMusicBtn"));
        addMusicBtn->setGeometry(QRect(410, 30, 75, 23));

        retranslateUi(LocalMusicWidget);

        QMetaObject::connectSlotsByName(LocalMusicWidget);
    } // setupUi

    void retranslateUi(QWidget *LocalMusicWidget)
    {
        LocalMusicWidget->setWindowTitle(QApplication::translate("LocalMusicWidget", "Form", nullptr));
        label->setText(QApplication::translate("LocalMusicWidget", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        playAllMusicBtn->setText(QApplication::translate("LocalMusicWidget", "\346\222\255\346\224\276\345\205\250\351\203\250", nullptr));
        addMusicBtn->setText(QApplication::translate("LocalMusicWidget", "\346\267\273\345\212\240\351\237\263\344\271\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LocalMusicWidget: public Ui_LocalMusicWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALMUSICWIDGET_H
