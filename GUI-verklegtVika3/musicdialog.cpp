#include "musicdialog.h"
#include "ui_musicdialog.h"

MusicDialog::MusicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MusicDialog)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    show();
    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &MusicDialog::on_PositionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MusicDialog::on_DurationChanged);

}

MusicDialog::~MusicDialog()
{
    delete ui;
}

void MusicDialog::on_VolumeSlider_sliderMoved(int position)
{
    player->setVolume(position);
}

void MusicDialog::on_ProgressSlider_sliderMoved(int position)
{
    player->setPosition(position);
}

void MusicDialog::on_StartButton_clicked()
{
    // Load the file

    player->setMedia(QUrl("qrc:/images/pictures/NyanCat.mp3"));
    player->play();

    // Engage nyan-cat cursor when music player starts
    QApplication::setOverrideCursor(QPixmap(":/images/pictures/nyan-cat.png"));

}

void MusicDialog::on_StopButton_clicked()
{
    player->stop();

    // Restore normal cursor on stop
    QApplication::restoreOverrideCursor();
}

void MusicDialog::on_PositionChanged(qint64 position)
{
    ui->ProgressSlider->setValue(position);
}

void MusicDialog::on_DurationChanged(qint64 position)
{
    ui->ProgressSlider->setMaximum(position);
}
