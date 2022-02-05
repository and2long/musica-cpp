#include "BottomBar.h"
#include "constants.h"
#include <QLabel>
#include "Song.h"
#include "ClickedLabel.h"
#include <QAudioOutput>
#include "NetworkImage.h"
#include "Toast.h"

BottomBar::BottomBar(Song s, QWidget *parent)
    : QWidget{parent}, song(s)
{
    // 背景
    QLabel *bg = new QLabel(this);
    bg->setFixedSize(WINDOW_WIDTH, BOTTOM_BAR_HEIGHT);
    bg->setObjectName("bg");

    // 专辑图片
    album = new NetworkImage(this);
    album->setFixedSize(42, 42);
    album->move(8,8);

    // 歌曲名
    songName = new QLabel(this);
    songName->setStyleSheet("color: #ccc");
    songName->move(61, 10);
    songName->setText("");

    // 进度和时长
    songDuration = new QLabel(this);
    songDuration->move(61, 32);
    songDuration->setStyleSheet("color: grey");
    songDuration->setText("");

    // 播放按钮
    btnPlay = new ClickedLabel(this);
    btnPlay->setPixmap(QPixmap(":/images/ic_play.svg"));
    btnPlay->setFixedSize(40, 40);
    btnPlay->move(WINDOW_WIDTH / 2 - 20, BOTTOM_BAR_HEIGHT / 2 - 20);
    QObject::connect(btnPlay, &ClickedLabel::clicked,this, &BottomBar::play);

    // 初始化播放器
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    audioOutput->setVolume(50);
    player->setAudioOutput(audioOutput);
    connect(player, &QMediaPlayer::errorOccurred, this, &BottomBar::onErrorOccurred);
}

void BottomBar::onErrorOccurred(QMediaPlayer::Error error, const QString &errorString)
{
    qDebug() << error << errorString;
    hasError = true;
    playing = false;
    switchBtnStatus(playing);
}

void BottomBar::play()
{
    if (song.id != 0 && !hasError) {
        if (playing)
        {
            player->pause();
            playing = false;
        }
        else
        {
            player->play();
            playing = true;
            qDebug() << song.toString();
        }
        switchBtnStatus(playing);
    }
}

void BottomBar::onSongClickedListener(Song value)
{
    qDebug() << value.toString();

    hasError = false;

    if (song.id == value.id)
    {
        return;
    }

    song = value;

    songName->setText(value.name);
    songName->adjustSize();

    songDuration->setText("00:00 / " + value.formatDuration());
    songDuration->adjustSize();

    player->setSource(QUrl(QString("http://music.163.com/song/media/outer/url?id=%1.mp3").arg(QString::number(value.id))));
    player->play();
    playing = true;
    switchBtnStatus(playing);

    album->setImageUrl(song.album);
}

void BottomBar::switchBtnStatus(bool status)
{
    if (status)
    {
        btnPlay->setPixmap(QPixmap(":/images/ic_pause.svg"));
    }
    else
    {
        btnPlay->setPixmap(QPixmap(":/images/ic_play.svg"));
    }
}
