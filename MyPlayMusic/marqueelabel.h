#ifndef MARQUEELABEL_H
#define MARQUEELABEL_H

#include <QLabel>
#include <QTimer>
#include <QPainter>
#include <QString>

class MarqueeLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MarqueeLabel(QWidget *parent = nullptr);
    void setText(const QString &text);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateText();

private:
    void startScrolling();
    void stopScrolling();

    QString originalText;
    int offset;
    QTimer *timer;
    bool scrollingEnabled;
};

#endif // MARQUEELABEL_H
