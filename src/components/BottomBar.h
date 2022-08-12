#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QWidget>
#include "src/models/Song.h"
#include <QLabel>
#include "ClickedLabel.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include "NetworkImage.h"
#include <QSlider>

class BottomBar : public QWidget
{
    Q_OBJECT
public:
    explicit BottomBar(Song song, QWidget *parent = nullptr);
    ClickedLabel *btnVolume;
    ClickedLabel *btnList;

public slots:
    // 播放按钮的槽函数
    void play();
    // 歌曲列表点击事件
    void onSongDoubleClickEvent(Song value);
    // 播放器事件
    void errorOccurred(QMediaPlayer::Error error, const QString &errorString);
    void bufferProgressChanged(float progress);
    void positionChanged(qint64 position);

signals:

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    NetworkImage *album;
    QLabel *songName;
    QLabel *songDuration;
    ClickedLabel *btnPlay;
    QSlider *slider;

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
