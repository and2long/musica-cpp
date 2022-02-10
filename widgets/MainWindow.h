#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include "LeftMenus.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void menuClicked(int index);
    void onSearch();
    void onBtnVolumeHovered();
    void onBtnVolumeUnHovered();

private:
    LeftMenus *leftMenus;
    QStackedLayout *layout;
};
#endif // MAINWINDOW_H
