#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QDebug>
#include <Qstring>

namespace Ui {
class MusicDialog;
}

class MusicDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MusicDialog(QWidget *parent = 0);
    ~MusicDialog();

private slots:
    void on_VolumeSlider_sliderMoved(int position);

    void on_ProgressSlider_sliderMoved(int position);

    void on_StartButton_clicked();

    void on_StopButton_clicked();

    void on_PositionChanged(qint64 position);

    void on_DurationChanged(qint64 position);

private:
    Ui::MusicDialog *ui;
    QMediaPlayer* player;
};

#endif // MUSICDIALOG_H
