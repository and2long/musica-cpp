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
