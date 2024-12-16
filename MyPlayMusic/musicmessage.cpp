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
