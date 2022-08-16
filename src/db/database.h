#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>

#include <src/models/Song.h>

class Database
{
public:
    static void init();

    static QList<Song> queryAllFavoriteItems();

    static void insertFavoriteItem(Song song);

    static void removeFavoriteItem(Song song);

    static bool existFavoriteItem(int sid);

    static QList<Song> queryAllPlayListItems();

    static void insertPlayListItem(Song song);

    static void removePlayListItem(Song song);

    static bool existPlayListItem(int sid);
};

#endif // DATABASE_H
