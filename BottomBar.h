#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QWidget>
#include "Song.h"
#include <QLabel>
#include "ClickedLabel.h"
#include <QMediaPlayer>
#include "NetworkImage.h"

class BottomBar : public QWidget
{
    Q_OBJECT
public:
    explicit BottomBar(Song song, QWidget *parent = nullptr);

public slots:
    // 播放按钮的槽函数
    void play();
    // 歌曲列表点击事件
    void onSongClickedListener(Song value);
    // 播放器错误
    void errorOccurred(QMediaPlayer::Error error, const QString &errorString);
    void timeout();
    void bufferProgressChanged(float progress);

signals:

private:
    // 定时器间隔
    static const int INTERVAL = 500;

    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    NetworkImage *album;
    QLabel *songName;
    QLabel *songDuration;
    ClickedLabel *btnPlay;

    QTimer *timer;
    int curDuration = 0;
    // 是否正在播放
    bool playing;
    // 切换播放按钮状态
    void switchBtnStatus(bool status);
    // 当前歌曲
    Song song;
    // 是否有错误
    bool hasError;

};

#endif // BOTTOMBAR_H
