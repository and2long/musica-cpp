#include "playlist.h"
#include "src/constants.h"
#include "src/db/database.h"
#include "ItemSong.h"

PlayList::PlayList(QWidget *parent)
    : QWidget{parent}
{
    int headerHeight = 80;
    auto headerSize = QSize(PLAY_LIST_WIDTH, headerHeight);
    auto containerSize = QSize(PLAY_LIST_WIDTH, PLAY_LIST_HEIGHT - headerHeight);

    setObjectName("root");
    auto *rootLayout = new QVBoxLayout();
    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);
    setLayout(rootLayout);

    auto header = new QWidget();
    header->setFixedSize(headerSize);
    header->setObjectName("header");
    rootLayout->addWidget(header);

    auto container = new QWidget();
    container->setFixedSize(containerSize);
    container->setObjectName("container");
    containerLayout = new QStackedLayout();
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

    auto *btnClear = new ClickedLabel();
    btnClear->setText("清空列表");
    btnClear->setFixedWidth(PLAY_LIST_WIDTH / 2);
    btnClear->setObjectName("btnClear");
    btnClear->setAlignment(Qt::AlignRight);
    connect(btnClear, &ClickedLabel::clicked, this, &PlayList::onBtnClearClicked);

    rowLayout->addWidget(count);
    rowLayout->addWidget(btnClear);

    auto emptyView = new QWidget();
    emptyView->setFixedSize(containerSize);
    auto *tip = new QLabel("你还没有添加任何歌曲！", emptyView);
    btnFind = new ClickedLabel(emptyView);
    btnFind->setText("去首页发现音乐");
    tip->setObjectName("tip");
    btnFind->setObjectName("btnFind");
    tip->setFixedWidth(PLAY_LIST_WIDTH);
    btnFind->setFixedWidth(PLAY_LIST_WIDTH);
    tip->setAlignment(Qt::AlignHCenter);
    btnFind->setAlignment(Qt::AlignHCenter);
    tip->move(0, 100);
    btnFind->move(0, 130);

    containerLayout->addWidget(emptyView);
    items = new QListWidget();
    items->setFixedSize(containerSize);
    containerLayout->addWidget(items);
}

void PlayList::initData() const
{
    QList<Song> favoriteSongs = Database::queryAllFavoriteItems();
    QList<int> ids = {};
        foreach (Song item, favoriteSongs) {
            ids.append(item.sid);
        }
    auto songs = Database::queryAllPlayListItems();
    if (songs.length() > 0) {
        containerLayout->setCurrentIndex(1);
    }
    else {
        containerLayout->setCurrentIndex(0);
    }
    items->clear();
    for (int i = 0; i < songs.size(); i++) {
        Song song = songs[i];
        song.isFavorite = ids.contains(song.sid);
        auto *widget = new ItemSong(i, song);
        auto *item = new QListWidgetItem;
        items->addItem(item);
        items->setItemWidget(item, widget);
    }
}
void PlayList::onBtnClearClicked() const
{
    items->clear();
    containerLayout->setCurrentIndex(0);
    Database::removeAllPlayListItems();
}
