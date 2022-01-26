#ifndef ITEMSONG_H
#define ITEMSONG_H

#include <QWidget>
#include "Song.h"

class ItemSong : public QWidget
{
    Q_OBJECT
public:
    explicit ItemSong(Song song, QWidget *parent = nullptr);
    Song song;

signals:

};

#endif // ITEMSONG_H
