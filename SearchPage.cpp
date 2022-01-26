#include "SearchPage.h"
#include "constants.h"
#include <QListWidget>
#include "ItemSong.h"

SearchPage::SearchPage(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    QListWidget *items = new QListWidget(this);
    items->setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    for (int i = 0; i < 20;  i++) {
        ItemSong *widget = new ItemSong();
        QListWidgetItem *item = new QListWidgetItem;
        items->addItem(item);
        items->setItemWidget(item, widget);
    }
}
