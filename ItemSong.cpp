#include "ItemSong.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QString>

ItemSong::ItemSong(int index, Song song, QWidget *parent) : QWidget{parent}
{
    QHBoxLayout  *layout = new QHBoxLayout;
    setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    int item_song_stretchs[] = {2, 9, 5, 3};
    QString titles[] = {QString::fromStdString(to_string(index + 1)), song.name, song.artists, QString::fromStdString(to_string(song.duration))};
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
