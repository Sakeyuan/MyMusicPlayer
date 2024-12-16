#include "playmusiclistform.h"
#include "ui_playmusiclistform.h"
#include <QStackedWidget>

PlayMusicListForm::PlayMusicListForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playMusicListForm)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);

    // 创建两个 QWidget
    QWidget* playListWidget = new QWidget(this);
    playListWidget->resize(500, 500);
    playListWidget->setStyleSheet("background-color: lightblue;");  // 设置背景色为淡蓝色

    QWidget* historyRecordWidget = new QWidget(this);
    historyRecordWidget->resize(500, 500);
    historyRecordWidget->setStyleSheet("background-color: lightgray;");  // 设置背景色为浅灰色

    // 创建 QStackedWidget 并添加 QWidget
    QStackedWidget* stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(playListWidget);       // 第一个 widget
    stackedWidget->addWidget(historyRecordWidget);  // 第二个 widget

    // 将 QStackedWidget 添加到布局中
    QVBoxLayout* mainVLayout = new QVBoxLayout();
    mainVLayout->addWidget(ui->playMusicListFormTopWidget);
    mainVLayout->addWidget(stackedWidget);
    mainVLayout->setSpacing(0);
    setLayout(mainVLayout);

    // 设置按钮的样式
    const QString buttonStyle = "QPushButton {"
                                "    background-color: transparent;" // 背景透明
                                "    border: none;"                  // 无边框
                                "    color: white;"
                                "    padding: 8px"
                                "}"
                                "QPushButton:pressed {"
                                "    background-color: rgb(35, 37, 42);"
                                "}"
                                "QPushButton:checked {"
                                "    background-color: rgb(35, 37, 42);" // 按钮选中时背景色
                                "}";

    ui->playListBtn->setStyleSheet(buttonStyle);
    ui->historyRecordBtn->setStyleSheet(buttonStyle);

    // 设置按钮为可选中状态
    ui->playListBtn->setCheckable(true);
    ui->playListBtn->setAutoExclusive(true);

    ui->historyRecordBtn->setCheckable(true);
    ui->historyRecordBtn->setAutoExclusive(true);

    // 默认选中第一个按钮
    ui->playListBtn->setChecked(true);

    // 连接按钮点击信号到槽函数
    connect(ui->playListBtn, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentWidget(playListWidget);  // 切换到 playListWidget
    });

    connect(ui->historyRecordBtn, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentWidget(historyRecordWidget);  // 切换到 historyRecordWidget
    });
}

PlayMusicListForm::~PlayMusicListForm()
{
    delete ui;
}

void PlayMusicListForm::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        isDragging = true;
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void PlayMusicListForm::mouseMoveEvent(QMouseEvent *event)
{
    if(isDragging){
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void PlayMusicListForm::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        isDragging = false;
        event->accept();
    }
}

void PlayMusicListForm::on_pushButton_clicked()
{
    this->close();
}

