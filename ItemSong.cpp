#include "ItemSong.h"
#include <QHBoxLayout>
#include <QLabel>

ItemSong::ItemSong(Song s, QWidget *parent) : QWidget{parent}, song(s)
{
    QHBoxLayout  *layout = new QHBoxLayout;
    setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    int item_song_stretchs[] = {2, 9, 5, 3};
    string titles[] = {"00", s.name, s.artists, to_string(s.duration)};
    for (int i = 0; i< 4 ; i++) {
        QLabel *item = new QLabel;
        if (i == 0)
        {
            item->setAlignment(Qt::AlignCenter);
        }
        item->setText(QString::fromStdString(titles[i]));
        layout->addWidget(item, item_song_stretchs[i]);
    }
}
