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
    void play();
    void onSongClickedListener(Song value);

signals:

private:

     QMediaPlayer *player;
     QAudioOutput *audioOutput;
     QLabel *album;
     QLabel *songName;
     QLabel *songDuration;
     ClickedLabel *btnPlay;
};

#endif // BOTTOMBAR_H
