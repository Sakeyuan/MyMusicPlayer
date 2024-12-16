#include "fsearchbox.h"
#include "ui_fsearchbox.h"

FSearchBox::FSearchBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FSearchBox)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);

    QString fSearchBoxStyleSheet = "background-color: rgb(255, 255, 255);"
                                   "border: none;"
                                   "border-radius:8px;";

    this->ui->fSearchBox->setStyleSheet(fSearchBoxStyleSheet);

    QString textBoxStyleSheet = "QLineEdit { border: none; }";
    this->ui->textBox->setStyleSheet(textBoxStyleSheet);

    // 设置默认显示
    this->setPlaceholderText();
}

FSearchBox::~FSearchBox()
{
    delete ui;
}

void FSearchBox::setPlaceholderText(QString text)
{
    this->m_text = text;
    this->ui->textBox->setPlaceholderText(m_text);
}
