#include "playlist.h"
#include "src/constants.h"

#include <QLabel>
#include <QStackedLayout>

PlayList::PlayList(QWidget *parent)
    : QWidget{parent}
{
    auto *container = new QLabel(this);
    container->setFixedSize(PLAY_LIST_WIDTH, PLAY_LIST_HEIGHT);
    container->setObjectName("bg");
    auto *layout = new QStackedLayout();
    layout->setStackingMode(QStackedLayout::StackingMode::StackOne);
    container->setLayout(layout);

    auto playListContainer = new QLabel();
    playListContainer->setFixedSize(PLAY_LIST_WIDTH, PLAY_LIST_HEIGHT);
    auto *title = new QLabel("当前播放", playListContainer);
    title->setObjectName("title");
    title->setFixedSize(PLAY_LIST_WIDTH, 50);
    title->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    auto *count = new QLabel("共0首", playListContainer);
    count->setObjectName("count");
    count->setFixedSize(PLAY_LIST_WIDTH, 40);
    count->move(0, 40);
    count->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    auto *clear = new QLabel("清空列表", playListContainer);
    clear->setObjectName("clear");
    clear->setFixedSize(PLAY_LIST_WIDTH, 40);
    clear->move(0, 40);
    clear->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    auto emptyContainer = new QLabel("你还没有添加任何歌曲！");
    emptyContainer->setObjectName("emptyContainer");
    emptyContainer->setFixedSize(PLAY_LIST_WIDTH, PLAY_LIST_HEIGHT);
    emptyContainer->setAlignment(Qt::AlignCenter);

    layout->addWidget(playListContainer);
    layout->addWidget(emptyContainer);
    layout->setCurrentIndex(1);
}
