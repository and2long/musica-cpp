#include "FavoritePage.h"
#include "constants.h"
#include <QLabel>

FavoritePage::FavoritePage(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    QLabel *tip = new QLabel("我的收藏", this);
    tip->setAlignment(Qt::AlignCenter);
}
