#include "musicdialog.h"
#include "ui_musicdialog.h"

MusicDialog::MusicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MusicDialog)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);

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

    player->setMedia(QUrl::fromLocalFile("NyanCat.mp3"));
    player->play();

    //musicDialog->show();

    //QCursor customCursor(QPixmap(":/images/pictures/nyan-cat.png"));
    //setCursor(customCursor);

}

void MusicDialog::on_StopButton_clicked()
{
    player->stop();

    //QCursor customCursor(QPixmap(":/images/pictures/nyan-cat.png"));


    //QApplication::restoreOverrideCursor();
}

void MusicDialog::on_PositionChanged(qint64 position)
{
    ui->ProgressSlider->setValue(position);
}

void MusicDialog::on_DurationChanged(qint64 position)
{
    ui->ProgressSlider->setMaximum(position);
}
