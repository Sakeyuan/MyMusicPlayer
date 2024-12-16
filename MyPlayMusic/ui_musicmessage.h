/********************************************************************************
** Form generated from reading UI file 'musicmessage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICMESSAGE_H
#define UI_MUSICMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicMessage
{
public:
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MusicMessage)
    {
        if (MusicMessage->objectName().isEmpty())
            MusicMessage->setObjectName(QString::fromUtf8("MusicMessage"));
        MusicMessage->resize(210, 80);
        MusicMessage->setMinimumSize(QSize(210, 80));
        MusicMessage->setMaximumSize(QSize(210, 80));
        pushButton = new QPushButton(MusicMessage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 10, 60, 60));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/img/singer.png);"));
        gridLayoutWidget = new QWidget(MusicMessage);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 10, 111, 61));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 30));
        label->setMaximumSize(QSize(80, 30));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(25, 25));
        pushButton_2->setMaximumSize(QSize(25, 25));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/img/collect.png);"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);


        retranslateUi(MusicMessage);

        QMetaObject::connectSlotsByName(MusicMessage);
    } // setupUi

    void retranslateUi(QWidget *MusicMessage)
    {
        MusicMessage->setWindowTitle(QApplication::translate("MusicMessage", "Form", nullptr));
        pushButton->setText(QString());
        label_2->setText(QApplication::translate("MusicMessage", "\351\231\210\345\245\225\350\277\205", nullptr));
        label->setText(QApplication::translate("MusicMessage", "\345\215\201\345\271\264\344\271\213\345\220\216", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MusicMessage: public Ui_MusicMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICMESSAGE_H
