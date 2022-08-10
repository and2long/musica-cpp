#include "ClickedLabel.h"
#include "ItemSong.h"
#include <QHBoxLayout>
#include <QLabel>
#include "src/utils/CommonUtil.h"
#include "src/db/database.h"

ItemSong::ItemSong(int index, Song song, QWidget *parent) : QWidget{parent}, song(song)
{
    QHBoxLayout *layout = new QHBoxLayout;
    setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QList stretchs = {2, 0, 9, 5, 3};
    QStringList titles = {CommonUtil::formatNum(index + 1), "", song.name, song.artists, CommonUtil::formatDuration(song.duration)};
    for (int i = 0; i < stretchs.length(); i++)
    {
        if(i == 1)
        {
            // 收藏按钮
            favoriteBtn = new ClickedLabel;
            favoriteBtn->setFixedSize(20, 20);
            favoriteBtn->setScaledContents(true);
            setFavoriteIcon(song);
            connect(favoriteBtn, &ClickedLabel::clicked, this, &ItemSong::favoriteBtnClickEvent);
            layout->addWidget(favoriteBtn, stretchs[i]);
        }
        QLabel *item = new QLabel;
        if (i == 0)
        {
            item->setAlignment(Qt::AlignCenter);
        }
        if (i == 0 || i == stretchs.length() - 1)
        {
            item->setStyleSheet("color: #666666");
        }
        item->setText(titles[i]);
        layout->addWidget(item, stretchs[i]);
    }
}

void ItemSong::mouseDoubleClickEvent(QMouseEvent *ev)
{
    (void)ev;
    emit doubleClicked(song);
}

void ItemSong::favoriteBtnClickEvent(){
    if (song.isFavorite)
    {
        Database::remove(song);
    }
    else
    {
        Database::insert(song);
    }
    song.isFavorite = !song.isFavorite;
    setFavoriteIcon(song);
}

void ItemSong::setFavoriteIcon(Song song)
{
    favoriteBtn->setPixmap(QPixmap(QString(":/assets/images/ic_favorite_%1.svg").arg(song.isFavorite ? "on" : "off")));
}
