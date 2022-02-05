#include "LeftMenus.h"
#include <QListWidget>
#include "constants.h"
#include <QLabel>

LeftMenus::LeftMenus(QWidget *parent)
    : QWidget{parent}
{
    QLabel *header = new QLabel("MUSICA音乐", this);
    header->setFixedSize(200, 100);
    header->setAlignment(Qt::AlignCenter);


    QListWidget *items = new QListWidget(this);
    items->move(0, 100);
    items->setFixedSize(LEFT_MENUS_WIDTH, WINDOW_HEIGHT);
    QStringList titles = {"发现音乐","下载管理","我的收藏"};
    for (int i = 0; i < titles.size(); i++) {
        items->addItem(new QListWidgetItem(QIcon(":/images/ic_music_off.svg"), titles[i]));
    }

    items->setCurrentRow(0);
}
