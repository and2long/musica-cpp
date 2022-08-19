#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include "ClickedLabel.h"

class PlayList: public QWidget
{
Q_OBJECT
public:
    explicit PlayList(QWidget *parent = nullptr);

    ClickedLabel *btnFind;
signals:

};

#endif // PLAYLIST_H
