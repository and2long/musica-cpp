#include <QLabel>

#include "FavoritePage.h"
#include "src/constants.h"
#include "src/db/database.h"
#include "src/components/ItemSong.h"


FavoritePage::FavoritePage(QWidget *parent)
    : QWidget{parent}
{
    items = new QListWidget(this);
    items->setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    initData();
}

void FavoritePage::initData()
{
    QList<Song> songs = Database::queryAllFavoriteItems();
    items->clear();
    for (int i = 0; i < songs.size(); i++) {
        Song song = songs[i];
        song.isFavorite = true;
        auto *widget = new ItemSong(i, song);
        auto *item = new QListWidgetItem;
        items->addItem(item);
        items->setItemWidget(item, widget);
        connect(widget, &ItemSong::doubleClicked, this, &FavoritePage::onSongDoubleClickEvent);
        connect(widget, &ItemSong::favoriteIconClicked, this, &FavoritePage::onFavoriteIconClickEvent);
    }
}

void FavoritePage::onSongDoubleClickEvent(Song song)
{
    emit songDoubleClicked(song);
}

void FavoritePage::onFavoriteIconClickEvent()
{
    QListWidgetItem *it = items->currentItem();
    items->removeItemWidget(it);
    delete it;
}
