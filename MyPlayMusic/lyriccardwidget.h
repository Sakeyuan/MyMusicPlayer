#ifndef LYRICCARDWIDGET_H
#define LYRICCARDWIDGET_H

#include <QWidget>

namespace Ui {
class LyricCardWidget;
}

class LyricCardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LyricCardWidget(QWidget *parent = nullptr);
    ~LyricCardWidget();
    void setLyrics(const QString& text);
private:
    Ui::LyricCardWidget *ui;
};

#endif // LYRICCARDWIDGET_H
