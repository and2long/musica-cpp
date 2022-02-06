#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

static void createConnection()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("musica.db");
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        QStringList tables = database.tables();
        if (!tables.contains("favorites"))
        {
            qDebug() << "收藏表不存在，进行创建";
            QSqlQuery query;
            query.prepare("create table favorites (id int primary key, sid int, duration int, name varchar(100), artists varchar(30), album varchar(100))");
            if(!query.exec())
            {
                qDebug() << "Error: Fail to create table." << query.lastError();
            }
            else
            {
                qDebug() << "Table created!";
            }
        }
        QSqlQuery query;
        query.exec("select * from favorites");
        if (!query.next())
        {
            qDebug() << "收藏表无数据，插入一条测试数据。";
            query.exec("INSERT INTO favorites (sid, duration, name) VALUES (298317, 319039, '屋顶')");
        }
    }
}
#endif // CONNECTION_H
