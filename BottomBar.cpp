#include "BottomBar.h"
#include "constants.h"
#include <QLabel>
#include "Song.h"
#include "ClickedLabel.h"

BottomBar::BottomBar(QWidget *parent)
    : QWidget{parent}
{
    // 背景
    QLabel *bg = new QLabel(this);
    bg->setFixedSize(WINDOW_WIDTH, BOTTOM_BAR_HEIGHT);
    bg->setObjectName("bg");

    // 专辑图片
    QLabel *album = new QLabel(this);
    album->setObjectName("album");
    album->setFixedSize(42, 42);
    album->move(8,8);

    // 歌曲名
    QLabel *songName = new QLabel(this);
    songName->setStyleSheet("color: #ccc");
    songName->move(61, 10);
    songName->setText("孤勇者 - 陈奕迅");

    // 进度和时长
    QLabel *songDuration = new QLabel(this);
    songDuration->move(61, 32);
    songDuration->setStyleSheet("color: grey");
    songDuration->setText("02:00 / 04:16");

    // 播放按钮
    ClickedLabel *btnPlay = new ClickedLabel(this);
    btnPlay->setPixmap(QPixmap(":/images/ic_play.svg"));
    btnPlay->setFixedSize(40, 40);
    btnPlay->move(WINDOW_WIDTH / 2 - 20, BOTTOM_BAR_HEIGHT / 2 - 20);
    QObject::connect(btnPlay, SIGNAL(clicked()),this, SLOT(play()));

}

void BottomBar::play()
{
    qDebug() << "播放";
}
