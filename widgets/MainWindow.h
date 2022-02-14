#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include "LeftMenus.h"
#include "VolumeSlider.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void menuClicked(int index);
    void onSearch();
    void onBtnVolumeEntered(bool status);

private:
    LeftMenus *leftMenus;
    QStackedLayout *layout;
    VolumeSlider *slider;
};
#endif // MAINWINDOW_H
