#include "LeftMenus.h"
#include <QListWidget>
#include "src/constants.h"
#include <QLabel>

LeftMenus::LeftMenus(QWidget *parent)
        : QWidget{parent} {
    auto *header = new QLabel("MUSICA音乐", this);
    header->setFixedSize(200, 100);
    header->setAlignment(Qt::AlignCenter);

    items = new QListWidget(this);
    items->move(0, 100);
    items->setFixedSize(LEFT_MENUS_WIDTH, WINDOW_HEIGHT);
    QStringList titles = {"发现音乐", "我的收藏", "下载管理"};
    QStringList iconsOn = {":/assets/images/ic_music_on.svg", ":/assets/images/ic_favorite_on.svg",
                           ":/assets/images/ic_download_on.svg"};
    QStringList iconsOff = {":/assets/images/ic_music_off.svg", ":/assets/images/ic_favorite_off.svg",
                            ":/assets/images/ic_download_off.svg"};
    for (int i = 0; i < titles.size(); i++) {
        QIcon icon;
        icon.addPixmap(QPixmap(iconsOff[i]), QIcon::Normal);
        icon.addPixmap(QPixmap(iconsOn[i]), QIcon::Selected);
        items->addItem(new QListWidgetItem(icon, titles[i], items, i));
    }
    items->setIconSize(QSize(24, 24));
    items->setCurrentRow(0);
    connect(items, &QListWidget::itemClicked, this, &LeftMenus::itemClicked);
}

void LeftMenus::setCurrentRow(int index) {
    items->setCurrentRow(index);
}

void LeftMenus::itemClicked(QListWidgetItem *item) {
    int index = item->type();
    emit menuClicked(index);
}
