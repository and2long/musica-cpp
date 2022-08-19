#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include <QListWidget>
#include <QStackedLayout>
#include "ClickedLabel.h"

class PlayList: public QWidget
{
Q_OBJECT
public:
    explicit PlayList(QWidget *parent = nullptr);

    QStackedLayout *containerLayout;
    ClickedLabel *btnFind;
    QListWidget *items;

    void initData() const;

public slots:
    void onBtnClearClicked() const;

signals:
};

#endif // PLAYLIST_H
