#ifndef PLAYMUSICLISTFORM_H
#define PLAYMUSICLISTFORM_H

#include <QPoint>
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
namespace Ui {
class playMusicListForm;
}

class PlayMusicListForm : public QWidget
{
    Q_OBJECT

public:
    explicit PlayMusicListForm(QWidget *parent = nullptr);
    ~PlayMusicListForm();

    void setButtonChecked(QPushButton *button);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_clicked();

private:
    Ui::playMusicListForm *ui;

    bool isDragging;
    QPoint dragPosition;

};

#endif // PLAYMUSICLISTFORM_H
