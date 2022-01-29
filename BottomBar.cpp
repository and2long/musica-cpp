#include "BottomBar.h"
#include "constants.h"
#include <QLabel>
#include "Song.h"
#include "ClickedLabel.h"
#include <QAudioOutput>

BottomBar::BottomBar(QWidget *parent)
    : QWidget{parent}
{
    // 背景
    QLabel *bg = new QLabel(this);
    bg->setFixedSize(WINDOW_WIDTH, BOTTOM_BAR_HEIGHT);
    bg->setObjectName("bg");

    // 专辑图片
    album = new QLabel(this);
    album->setObjectName("album");
    album->setFixedSize(42, 42);
    album->move(8,8);

    // 歌曲名
    songName = new QLabel(this);
    songName->setObjectName("songName");
    songName->setStyleSheet("color: #ccc");
    songName->move(61, 10);
    songName->setText("孤勇者 - 陈奕迅");

    // 进度和时长
    songDuration = new QLabel(this);
    songDuration->setObjectName("songDuration");
    songDuration->move(61, 32);
    songDuration->setStyleSheet("color: grey");
    songDuration->setText("02:00 / 04:16");

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
//    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
}

void BottomBar::play()
{
    qDebug() << "播放";
}

void BottomBar::onSongClickedListener(Song value)
{
    qDebug() << value.toString();

    songName->setText(value.name);
    songName->adjustSize();

    songDuration->setText(QString::number(value.duration));
    songDuration->adjustSize();

    player->setSource(QUrl(QString("http://music.163.com/song/media/outer/url?id=%1.mp3").arg(QString::number(value.id))));
    player->play();

}
