#ifndef ITEMSONG_H
#define ITEMSONG_H

#include <QWidget>
#include "Song.h"

class ItemSong : public QWidget
{
    Q_OBJECT
public:
    explicit ItemSong(int index, Song song, QWidget *parent = nullptr);

signals:

};

#endif // ITEMSONG_H
