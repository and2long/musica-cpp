#ifndef ITEMSONG_H
#define ITEMSONG_H

#include <QWidget>
#include "src/models/Song.h"
#include "ClickedLabel.h"

class ItemSong : public QWidget {
Q_OBJECT
public:
    explicit ItemSong(int index, Song song, QWidget *parent = nullptr);

    void mouseDoubleClickEvent(QMouseEvent *ev);

    void favoriteBtnClickEvent();

    void setFavoriteIcon(Song song);

    Song song;
    ClickedLabel *favoriteBtn;

signals:

    void doubleClicked(Song song);

    void favoriteIconClicked();
};

#endif // ITEMSONG_H
