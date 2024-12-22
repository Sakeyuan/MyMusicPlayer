#include "lyriccardwidget.h"
#include "ui_lyriccardwidget.h"


LyricCardWidget::LyricCardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LyricCardWidget)
{
    ui->setupUi(this);
}

LyricCardWidget::~LyricCardWidget()
{
    delete ui;
}

void LyricCardWidget::setLyrics(const QString& text)
{
    this->ui->lyricsLabel->setText(text);
}
