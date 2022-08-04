#include "ItemSong.h"
#include <QHBoxLayout>
#include <QLabel>
#include "src/utils/CommonUtil.h"

ItemSong::ItemSong(int index, Song song, QWidget *parent) : QWidget{parent}, song(song)
{
    QHBoxLayout *layout = new QHBoxLayout;
    setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QList stretchs = {2, 9, 5, 3};
    QStringList titles = {CommonUtil::formatNum(index + 1), song.name, song.artists, CommonUtil::formatDuration(song.duration)};
    for (int i = 0; i < stretchs.length(); i++)
    {
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
    emit clicked(song);
}
