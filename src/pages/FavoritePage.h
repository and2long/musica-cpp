#ifndef FAVORITEPAGE_H
#define FAVORITEPAGE_H

#include "src/models/Song.h"
#include <QListWidget>
#include <QWidget>

class FavoritePage : public QWidget {
Q_OBJECT
public:
    explicit FavoritePage(QWidget *parent = nullptr);

    void initData();

private:
    QListWidget *items;

signals:

    void songDoubleClicked(Song song);

public slots:

    void onSongDoubleClickEvent(Song song);

    void onFavoriteIconClickEvent();
};

#endif // FAVORITEPAGE_H
