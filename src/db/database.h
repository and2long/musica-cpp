#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>

#include <src/models/Song.h>

class Database
{
public:
    static void init();
    static QList<Song> queryAll();
};

#endif // DATABASE_H
