#ifndef ITEMSONG_H
#define ITEMSONG_H

#include <QWidget>
#include "src/models/Song.h"

class ItemSong : public QWidget
{
    Q_OBJECT
public:
    explicit ItemSong(int index, Song song, QWidget *parent = nullptr);
    Song song;
    void mouseDoubleClickEvent(QMouseEvent *ev);
    void favoriteBtnClickEvent();

signals:
    void doubleClicked(Song song);
};

#endif // ITEMSONG_H
