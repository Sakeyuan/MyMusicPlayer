#include "musicmessage.h"
#include "ui_musicmessage.h"

MusicMessage::MusicMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicMessage)
{
    ui->setupUi(this);
}

MusicMessage::~MusicMessage()
{
    delete ui;
}

void MusicMessage::setTitle(QString text)
{
    this->ui->titleLabel->setText(text);
    this->ui->titleLabel->setFixedWidth(90);
}

void MusicMessage::setAuthor(QString text)
{
    this->ui->authorLabel->setText(text);
    this->ui->authorLabel->setFixedWidth(90);
}
