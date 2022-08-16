#include "database.h"
#include <QSqlError>

void Database::init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("musica.db");
    db.close();
    if (!db.open()) {
        qDebug() << "Error: Failed to connect database." << db.lastError();
    }
    else {
        QStringList tables = db.tables();
        if (!tables.contains("favorites")) {
            QSqlQuery query;
            query.prepare(
                "create table favorites (id int primary key, sid int, duration int, name varchar(100), artists varchar(30), album varchar(100))");
            if (!query.exec()) {
                qDebug() << "Error: Fail to create favorites table." << query.lastError();
            }
            else {
                qDebug() << "Table of favorites created!";
            }
        }
        if (!tables.contains("playlist")) {
            QSqlQuery query;
            query.prepare(
                "create table playlist (id int primary key, sid int, duration int, name varchar(100), artists varchar(30), album varchar(100))");
            if (!query.exec()) {
                qDebug() << "Error: Fail to create playlist table." << query.lastError();
            }
            else {
                qDebug() << "Table of playlist created!";
            }
        }
    }
}

QList<Song> Database::queryAllFavoriteItems()
{
    QSqlQuery query;
    query.exec("select * from favorites");
    QList<Song> results = {};
    while (query.next()) {
        int sid = query.value("sid").toInt();
        int duration = query.value("duration").toInt();
        QString name = query.value("name").toString();
        QString artists = query.value("artists").toString();
        QString album = query.value("album").toString();
        Song song = Song(sid, name, artists, duration, album);
        results.append(song);
    }
    return results;
}

void Database::insertFavoriteItem(Song song)
{
    if (existFavoriteItem(song.sid)) return;
    QSqlQuery query;
    query.exec(QString("INSERT INTO favorites (sid, duration, name, artists, album) VALUES (%1, %2, '%3', '%4', '%5')")
                   .arg(QString::number(song.sid), QString::number(song.duration), song.name, song.artists,
                        song.album));
}

void Database::removeFavoriteItem(Song song)
{
    QSqlQuery query;
    query.exec(QString("DELETE FROM favorites WHERE sid = %1").arg(song.sid));
}

bool Database::existFavoriteItem(int sid)
{
    QSqlQuery query;
    query.exec(QString("SELECT 1 FROM favorites WHERE sid = %1 LIMIT 1").arg(sid));
    return query.next();
}

QList<Song> Database::queryAllPlayListItems()
{
    QSqlQuery query;
    query.exec("select * from playlist");
    QList<Song> results = {};
    while (query.next()) {
        int sid = query.value("sid").toInt();
        int duration = query.value("duration").toInt();
        QString name = query.value("name").toString();
        QString artists = query.value("artists").toString();
        QString album = query.value("album").toString();
        Song song = Song(sid, name, artists, duration, album);
        results.append(song);
    }
    return results;
}

void Database::insertPlayListItem(Song song)
{
    if (existPlayListItem(song.sid)) return;
    QSqlQuery query;
    query.exec(QString("INSERT INTO playlist (sid, duration, name, artists, album) VALUES (%1, %2, '%3', '%4', '%5')")
                   .arg(QString::number(song.sid), QString::number(song.duration), song.name, song.artists,
                        song.album));
}

void Database::removePlayListItem(Song song)
{
    QSqlQuery query;
    query.exec(QString("DELETE FROM playlist WHERE sid = %1").arg(song.sid));
}

bool Database::existPlayListItem(int sid)
{
    QSqlQuery query;
    query.exec(QString("SELECT 1 FROM playlist WHERE sid = %1 LIMIT 1").arg(sid));
    return query.next();
}
