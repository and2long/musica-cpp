#include "playlist.h"
#include "src/constants.h"

#include <QLabel>

PlayList::PlayList(QWidget *parent)
        : QWidget{parent} {
    // 背景
    auto *bg = new QLabel(this);
    bg->setFixedSize(PLAY_LIST_WIDTH, PLAY_LIST_HEIGHT);
    bg->setObjectName("bg");

    auto *title = new QLabel("当前播放", this);
    title->setObjectName("title");
    title->setFixedSize(PLAY_LIST_WIDTH, 50);
    title->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    auto *count = new QLabel("共0首", this);
    count->setObjectName("count");
    count->setFixedSize(PLAY_LIST_WIDTH, 40);
    count->move(0, 40);
    count->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    auto *clear = new QLabel("清空列表", this);
    clear->setObjectName("clear");
    clear->setFixedSize(PLAY_LIST_WIDTH, 40);
    clear->move(0, 40);
    clear->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

}
