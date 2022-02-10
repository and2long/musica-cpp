#include "BottomBar.h"
#include "constants.h"
#include "utils/CommonUtil.h"

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
    album->move(8, 12);

    // 歌曲名
    songName = new QLabel(this);
    songName->setStyleSheet("color: #ccc");
    songName->move(61, 14);
    songName->setText("");

    // 进度和时长
    songDuration = new QLabel(this);
    songDuration->move(61, 36);
    songDuration->setStyleSheet("color: grey; font-size: 12px");
    songDuration->setText("");

    // 播放按钮
    btnPlay = new ClickedLabel(this);
    btnPlay->setPixmap(QPixmap(":/images/ic_play.svg"));
    btnPlay->setFixedSize(40, 40);
    btnPlay->move(WINDOW_WIDTH / 2 - 20, BOTTOM_BAR_HEIGHT / 2 - 22);
    QObject::connect(btnPlay, &ClickedLabel::clicked,this, &BottomBar::play);

    // 歌曲列表按钮
    btnList = new ClickedLabel(this);
    btnList->setPixmap(QPixmap(":/images/ic_musiclist_off.svg"));
    btnList->setFixedSize(30, 30);
    btnList->setScaledContents(true);
    btnList->move(WINDOW_WIDTH - 50, BOTTOM_BAR_HEIGHT / 2 - 18);

    // 音量按钮
    btnVolume = new VolumeButton(this);
    btnVolume->setPixmap(QPixmap(":/images/ic_volume.svg"));
    btnVolume->setFixedSize(30, 30);
    btnVolume->setScaledContents(true);
    btnVolume->move(WINDOW_WIDTH - 90, BOTTOM_BAR_HEIGHT / 2 - 18);

    // 进度条
    slider = new QSlider(Qt::Orientation::Horizontal, this);
    slider->setFixedWidth(WINDOW_WIDTH);
    slider->setEnabled(false);
    slider->setFixedHeight(8);

    // 初始化播放器
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    audioOutput->setVolume(50);
    player->setAudioOutput(audioOutput);
    connect(player, &QMediaPlayer::errorOccurred, this, &BottomBar::errorOccurred);
    connect(player, &QMediaPlayer::bufferProgressChanged, this, &BottomBar::bufferProgressChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &BottomBar::positionChanged);
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);
    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);
}

void BottomBar::positionChanged(qint64 position)
{
    if (position <= song.duration)
    {
        songDuration->setText(CommonUtil::formatDuration(position) + " / " + CommonUtil::formatDuration(song.duration));
    }
}

void BottomBar::errorOccurred(QMediaPlayer::Error error, const QString &errorString)
{
    qDebug() << error << errorString;
    hasError = true;
    playing = false;
    switchBtnStatus(playing);
}

void BottomBar::bufferProgressChanged(float progress)
{
    qDebug() << progress;
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

    slider->setMaximum(song.duration);

    songName->setText(value.name);
    songName->adjustSize();

    songDuration->setText("00:00 / " + CommonUtil::formatDuration(song.duration));
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
    slider->setEnabled(status);
}
