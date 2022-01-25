#include "left_menus.h"
#include <QListWidget>
#include "constants.h"

LeftMenus::LeftMenus(QWidget *parent)
    : QWidget{parent}
{
    QListWidget *items = new QListWidget(this);
    items->setFixedSize(LEFT_MENUS_WIDTH, WINDOW_HEIGHT);
    items->addItems({"发现音乐","下载管理","我的收藏"});
    items->setSpacing(5);
}
