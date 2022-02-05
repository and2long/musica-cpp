#include "ItemSong.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QString>

ItemSong::ItemSong(int index, Song song, QWidget *parent) : QWidget{parent}, song(song)
{
    QHBoxLayout  *layout = new QHBoxLayout;
    setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    int item_song_stretchs[] = {2, 9, 5, 3};
    QString titles[] = {QString::number(index + 1), song.name, song.artists, song.formatDuration()};
    for (int i = 0; i< 4 ; i++) {
        QLabel *item = new QLabel;
        if (i == 0)
        {
            item->setAlignment(Qt::AlignCenter);
        }
        item->setText(titles[i]);
        layout->addWidget(item, item_song_stretchs[i]);
    }
}

void ItemSong::mouseDoubleClickEvent(QMouseEvent *ev)
{
    (void)ev;
    emit clicked(song);
}
