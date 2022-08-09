#include "FavoritePage.h"
#include <QLabel>

#include "src/constants.h"
#include "src/db/database.h"

FavoritePage::FavoritePage(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    initData();
}

void FavoritePage::initData()
{
    QList<Song> results = Database::queryAll();
    qDebug() << "FavoritePage: " << results.size();
}
