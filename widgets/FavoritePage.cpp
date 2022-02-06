#include "FavoritePage.h"
#include "constants.h"
#include <QLabel>
#include <QSqlQuery>
#include <QVariant>

FavoritePage::FavoritePage(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);

    QSqlQuery query;
    query.exec("select * from favorites");
    while (query.next())
    {
        int id = query.value("id").toInt();
        int sid = query.value("sid").toInt();
        int duration = query.value("duration").toInt();
        QString name = query.value("name").toString();

        qDebug() << id << " " << sid << " " << name << " " << duration;
    }
}
