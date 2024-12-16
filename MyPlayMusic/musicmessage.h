#ifndef MUSICMESSAGE_H
#define MUSICMESSAGE_H

#include <QWidget>

namespace Ui {
class MusicMessage;
}

class MusicMessage : public QWidget
{
    Q_OBJECT

public:
    explicit MusicMessage(QWidget *parent = nullptr);
    ~MusicMessage();

private:
    Ui::MusicMessage *ui;
};

#endif // MUSICMESSAGE_H
