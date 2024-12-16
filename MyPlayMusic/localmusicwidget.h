#ifndef LOCALMUSICWIDGET_H
#define LOCALMUSICWIDGET_H

#include "fplayer.h"
#include <QWidget>

namespace Ui {
class LocalMusicWidget;
}

class LocalMusicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LocalMusicWidget(QWidget *parent = nullptr);
    ~LocalMusicWidget();

private slots:
    void on_addMusicBtn_clicked();

    void on_localMusicListWidget_doubleClicked(const QModelIndex &index);

signals:
    void durationChanged(qint64 duration);
    void positionChanged(qint64 position);

private:
    Ui::LocalMusicWidget *ui;
    FPlayer* player;
};

#endif // LOCALMUSICWIDGET_H
