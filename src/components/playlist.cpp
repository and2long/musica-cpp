#include "playlist.h"
#include "src/constants.h"
#include "ClickedLabel.h"

#include <QLabel>
#include <QStackedLayout>

PlayList::PlayList(QWidget *parent)
    : QWidget{parent}
{

    int headerHeight = 80;
    auto *headerSize = new QSize(PLAY_LIST_WIDTH, headerHeight);
    auto *containerSize = new QSize(PLAY_LIST_WIDTH, PLAY_LIST_HEIGHT - headerHeight);

    this->setObjectName("root");
    auto *rootLayout = new QVBoxLayout();
    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);
    this->setLayout(rootLayout);

    auto header = new QWidget();
    header->setFixedSize(*headerSize);
    header->setObjectName("header");
    rootLayout->addWidget(header);

    auto container = new QWidget();
    container->setFixedSize(*containerSize);
    container->setObjectName("container");
    auto containerLayout = new QStackedLayout();
    container->setLayout(containerLayout);
    rootLayout->addWidget(container);

    auto *title = new QLabel("当前播放", header);
    title->setObjectName("title");
    title->setFixedSize(PLAY_LIST_WIDTH, 50);
    title->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    auto row = new QWidget(header);
    row->move(0, 50);
    auto rowLayout = new QHBoxLayout();
    rowLayout->setContentsMargins(0, 0, 0, 0);
    rowLayout->setSpacing(0);
    row->setLayout(rowLayout);

    auto *count = new QLabel("共0首");
    count->setFixedWidth(PLAY_LIST_WIDTH / 2);
    count->setObjectName("count");
    count->setAlignment(Qt::AlignLeft);

    auto *clear = new ClickedLabel();
    clear->setText("清空列表");
    clear->setFixedWidth(PLAY_LIST_WIDTH / 2);
    clear->setObjectName("clear");
    clear->setAlignment(Qt::AlignRight);

    rowLayout->addWidget(count);
    rowLayout->addWidget(clear);

    auto emptyView = new QWidget();
    emptyView->setFixedSize(*containerSize);
    auto *tipTitle = new QLabel("你还没有添加任何歌曲！", emptyView);
    auto *tipSubtitle = new ClickedLabel(emptyView);
    tipSubtitle->setText("去首页发现音乐");
    tipTitle->setObjectName("tipTitle");
    tipSubtitle->setObjectName("tipSubtitle");
    tipTitle->setFixedWidth(PLAY_LIST_WIDTH);
    tipSubtitle->setFixedWidth(PLAY_LIST_WIDTH);
    tipTitle->setAlignment(Qt::AlignHCenter);
    tipSubtitle->setAlignment(Qt::AlignHCenter);
    tipTitle->move(0, 100);
    tipSubtitle->move(0, 130);

    containerLayout->addWidget(emptyView);
}
