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

    for (int i = 0; i< 4 ; i++) {
        layout->addWidget(new QLabel("item"));
    }
}
