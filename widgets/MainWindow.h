#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include "LeftMenus.h"
#include "VolumeSlider.h"
#include "BottomBar.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void menuClicked(int index);
    void onSearch();
    void onVolumeBtnClicked();

private:
    LeftMenus *leftMenus;
    QStackedLayout *layout;
    VolumeSlider *volumeSlider;
    BottomBar *bottomBar;
};
#endif // MAINWINDOW_H
