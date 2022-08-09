#ifndef FAVORITEPAGE_H
#define FAVORITEPAGE_H

#include <QWidget>

class FavoritePage : public QWidget
{
    Q_OBJECT
public:
    explicit FavoritePage(QWidget *parent = nullptr);

    void initData();

signals:
};

#endif // FAVORITEPAGE_H
