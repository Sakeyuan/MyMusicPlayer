/********************************************************************************
** Form generated from reading UI file 'fsearchbox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FSEARCHBOX_H
#define UI_FSEARCHBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FSearchBox
{
public:
    QGridLayout *gridLayout_2;
    QWidget *fSearchBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *icon;
    QLineEdit *textBox;

    void setupUi(QWidget *FSearchBox)
    {
        if (FSearchBox->objectName().isEmpty())
            FSearchBox->setObjectName(QString::fromUtf8("FSearchBox"));
        FSearchBox->resize(152, 35);
        gridLayout_2 = new QGridLayout(FSearchBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(7);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        fSearchBox = new QWidget(FSearchBox);
        fSearchBox->setObjectName(QString::fromUtf8("fSearchBox"));
        gridLayout = new QGridLayout(fSearchBox);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 0, 3, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, -1, 2, -1);
        icon = new QPushButton(fSearchBox);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setMinimumSize(QSize(18, 18));
        icon->setMaximumSize(QSize(18, 18));
        icon->setStyleSheet(QString::fromUtf8("border-image: url(:/img/search.png);"));

        horizontalLayout->addWidget(icon);

        textBox = new QLineEdit(fSearchBox);
        textBox->setObjectName(QString::fromUtf8("textBox"));
        textBox->setMinimumSize(QSize(0, 25));
        textBox->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(textBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(fSearchBox, 0, 0, 1, 1);


        retranslateUi(FSearchBox);

        QMetaObject::connectSlotsByName(FSearchBox);
    } // setupUi

    void retranslateUi(QWidget *FSearchBox)
    {
        FSearchBox->setWindowTitle(QApplication::translate("FSearchBox", "Form", nullptr));
        icon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FSearchBox: public Ui_FSearchBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FSEARCHBOX_H
