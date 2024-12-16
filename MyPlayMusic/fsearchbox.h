#ifndef FSEARCHBOX_H
#define FSEARCHBOX_H

#include <QWidget>

namespace Ui {
class FSearchBox;
}

class FSearchBox : public QWidget
{
    Q_OBJECT

public:
    explicit FSearchBox(QWidget *parent = nullptr);
    ~FSearchBox();

    void setPlaceholderText(QString text = "搜索");

public:
    QString m_text;

private:
    Ui::FSearchBox *ui;
};

#endif
