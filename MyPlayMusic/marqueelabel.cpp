#include "marqueelabel.h"
#include <QFontMetrics>

MarqueeLabel::MarqueeLabel(QWidget *parent)
    : QLabel(parent), offset(0), timer(new QTimer(this)), scrollingEnabled(false)
{
    connect(timer, &QTimer::timeout, this, &MarqueeLabel::updateText);
}

void MarqueeLabel::setText(const QString &text)
{
    originalText = text;
    QLabel::setText(text);  // 保留 QLabel 的原始功能
    QFontMetrics fm(font());
    int textWidth = fm.horizontalAdvance(text);

    if (textWidth > width()) {
        startScrolling();
    } else {
        stopScrolling();
    }
}

void MarqueeLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QFontMetrics fm = painter.fontMetrics();
    int textWidth = fm.horizontalAdvance(originalText);

    if (scrollingEnabled && textWidth > width()) {
        QString visibleText = originalText.mid(offset) + " " + originalText;
        painter.drawText(0, height() / 2 + fm.ascent() / 2, visibleText);
    } else {
        QLabel::paintEvent(event);  // 文本适合显示时使用默认绘制
    }
}


void MarqueeLabel::updateText()
{
    if (++offset >= originalText.length()) {
        offset = 0;
    }
    update();  // 触发重绘
}

void MarqueeLabel::startScrolling()
{
    if (!scrollingEnabled) {
        scrollingEnabled = true;
        timer->start(500);  // 控制滚动速度
    }
}

void MarqueeLabel::stopScrolling()
{
    if (scrollingEnabled) {
        scrollingEnabled = false;
        timer->stop();
        offset = 0;
        update();
    }
}
