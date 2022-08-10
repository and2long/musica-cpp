#include "FavoritePage.h"
#include <QLabel>

#include "src/constants.h"
#include "src/db/database.h"
#include <src/components/ItemSong.h>

FavoritePage::FavoritePage(QWidget *parent)
    : QWidget{parent}
{
    items = new QListWidget(this);
    items->setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    initData();
}

void FavoritePage::initData()
{
    QList<Song> songs = Database::queryAll();
    qDebug() << "FavoritePage: " << songs.size();
    items->clear();
    for (int i = 0; i < songs.size(); i++)
    {
        Song song = songs[i];
        song.isFavorite = true;
        ItemSong *widget = new ItemSong(i, song);
        QListWidgetItem *item = new QListWidgetItem;
        items->addItem(item);
        items->setItemWidget(item, widget);
        connect(widget, &ItemSong::doubleClicked, this, &FavoritePage::onSongDoubleClickEvent);
    }
}

void FavoritePage::onSongDoubleClickEvent(Song song)
{
    emit songDoubleClicked(song);
}

