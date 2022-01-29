#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QWidget>
#include "Song.h"

class SearchPage : public QWidget
{
    Q_OBJECT
public:
    explicit SearchPage(QWidget *parent = nullptr);

public slots:
    void onItemClicked(Song song);

signals:
    void itemClicked(Song song);
};

#endif // SEARCHPAGE_H
