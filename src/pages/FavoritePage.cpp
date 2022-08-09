#include "FavoritePage.h"
#include "src/constants.h"
#include <QLabel>
#include <QSqlQuery>
#include <QVariant>
#include "src/models/Song.h"

FavoritePage::FavoritePage(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);

    QSqlQuery query;
    query.exec("select * from favorites");
    while (query.next())
    {
        int sid = query.value("sid").toInt();
        int duration = query.value("duration").toInt();
        QString name = query.value("name").toString();
        QString artists = query.value("artists").toString();
        QString album = query.value("album").toString();
        Song song = Song(sid, name, artists, duration, album);

        qDebug() << "FavoritePage: " << song.toString();
    }
}
