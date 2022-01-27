#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QWidget>
#include "Song.h"


class BottomBar : public QWidget
{
    Q_OBJECT
public:
    explicit BottomBar(QWidget *parent = nullptr);

public slots:
    void play();

signals:

};

#endif // BOTTOMBAR_H
