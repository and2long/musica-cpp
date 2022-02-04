#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QWidget>
#include "Song.h"
#include <QLabel>
#include "ClickedLabel.h"
#include <QMediaPlayer>

class BottomBar : public QWidget
{
    Q_OBJECT
public:
    explicit BottomBar(QWidget *parent = nullptr);

public slots:
    // 播放按钮的槽函数
    void play();
    // 歌曲列表点击事件
    void onSongClickedListener(Song value);

signals:

private:

     QMediaPlayer *player;
     QAudioOutput *audioOutput;
     QLabel *album;
     QLabel *songName;
     QLabel *songDuration;
     ClickedLabel *btnPlay;

     // 是否正在播放
     bool playing;
     // 切换播放按钮状态
     void switchBtnStatus(bool status);
};

#endif // BOTTOMBAR_H
