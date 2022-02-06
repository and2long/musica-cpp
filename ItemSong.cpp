#include "ItemSong.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <sstream>
#include <iomanip>

ItemSong::ItemSong(int index, Song song, QWidget *parent) : QWidget{parent}, song(song)
{
    QHBoxLayout  *layout = new QHBoxLayout;
    setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    int item_song_stretchs[] = {2, 9, 5, 3};
    stringstream s;
    s << setw(2) << setfill('0') << (index + 1);
    string ss;
    s >> ss;
    QString titles[] = {QString::fromStdString(ss), song.name, song.artists, Song::formatDuration(song.duration)};
    for (int i = 0; i< 4 ; i++) {
        QLabel *item = new QLabel;
        if (i == 0)
        {
            item->setAlignment(Qt::AlignCenter);
        }
        if (i == 0 || i == 3)
        {
            item->setStyleSheet("color: #666666");
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
