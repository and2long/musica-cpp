#include "ItemSong.h"
#include <QHBoxLayout>
#include <QLabel>

ItemSong::ItemSong(QWidget *parent)
    : QWidget{parent}
{
    QHBoxLayout  *layout = new QHBoxLayout;
    setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    int item_song_stretchs[] = {1, 9, 5, 3};
    for (int i = 0; i< 4 ; i++) {
        QLabel *item = new QLabel;
        if (i == 0)
        {
            item->setAlignment(Qt::AlignCenter);
            item->setText("00");
        }
        else
        {
            item->setText("item");
        }
        layout->addWidget(item, item_song_stretchs[i]);
    }
}
