#include "database.h"
#include <QSqlError>

void Database::init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("musica.db");
    db.close();
    if (!db.open())
    {
        qDebug() << "Error: Failed to connect database." << db.lastError();
    }
    else
    {
        QStringList tables = db.tables();
        if (!tables.contains("favorites"))
        {
            QSqlQuery query;
            query.prepare("create table favorites (id int primary key, sid int, duration int, name varchar(100), artists varchar(30), album varchar(100))");
            if (!query.exec())
            {
                qDebug() << "Error: Fail to create table." << query.lastError();
            }
            else
            {
                qDebug() << "Table of favorites created!";
            }
        }
    }
}

QList<Song> Database::queryAll()
{
    QSqlQuery query;
    query.exec("select * from favorites");
    QList<Song> results = {};
    while (query.next())
    {
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

void Database::insert(Song song)
{
    QSqlQuery query;
    query.exec(QString("INSERT INTO favorites (sid, duration, name, artists, album) VALUES (%1, %2, '%3', '%4', '%5')")
               .arg(QString::number(song.sid), QString::number(song.duration), song.name, song.artists, song.album));
}

void Database::remove(Song song)
{
    QSqlQuery query;
    query.exec(QString("DELETE FROM favorites WHERE sid = %1").arg(song.sid));
}

bool Database::exist(int sid)
{
    QSqlQuery query;
    query.exec(QString("SELECT 1 FROM favorites WHERE sid = %1 LIMIT 1").arg(sid));
    return query.next();
}
