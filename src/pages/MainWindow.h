#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include <src/components/playlist.h>
#include "src/components/LeftMenus.h"
#include "src/components/VolumeSlider.h"
#include "src/components/BottomBar.h"
#include "FavoritePage.h"
#include "SearchPage.h"

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

public slots:

    void menuClicked(int index);

    void onSearch();

    void onVolumeBtnClicked();

    void onListBtnClicked();

private:
    LeftMenus *leftMenus;
    QStackedLayout *layout;
    VolumeSlider *volumeSlider;
    BottomBar *bottomBar;
    SearchPage *searchPage;
    FavoritePage *favoritePage;
    PlayList *playList;
};

#endif // MAINWINDOW_H
