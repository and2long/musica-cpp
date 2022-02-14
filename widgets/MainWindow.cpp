#include "MainWindow.h"
#include "TopBar.h"
#include "SearchPage.h"
#include "DownloadPage.h"
#include "FavoritePage.h"
#include "BottomBar.h"
#include "constants.h"
#include "connection.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    createConnection();

    setWindowTitle("MUSICA");
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    // 左侧菜单
    leftMenus = new LeftMenus(this);
    // 顶部快捷搜索栏
    TopBar *topBar =  new TopBar(this);
    topBar->move(LEFT_MENUS_WIDTH, 0);
    // 中间层叠容器
    QWidget *container = new QWidget(this);
    container->setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    layout = new QStackedLayout();
    layout->setStackingMode(QStackedLayout::StackingMode::StackOne);
    container->setLayout(layout);
    container->move(LEFT_MENUS_WIDTH, TOP_BAR_HEIGHT);
    // 搜索页面
    SearchPage *searchPage = new SearchPage();
    layout->addWidget(searchPage);
    // 下载界面
    DownloadPage *downloadPage = new DownloadPage();
    layout->addWidget(downloadPage);
    // 收藏界面
    FavoritePage *favoritePage = new FavoritePage();
    layout->addWidget(favoritePage);
    // 底部控制栏
    BottomBar *bottomBar = new BottomBar(Song(), this);
    bottomBar->move(0, 610);
    // 连接
    connect(searchPage, &SearchPage::itemClicked, bottomBar, &BottomBar::onSongClickedListener);
    connect(topBar, &TopBar::search, searchPage, &SearchPage::onSearch);
    connect(topBar, &TopBar::search, this, &MainWindow::onSearch);
    connect(leftMenus, &LeftMenus::menuClicked, this, &MainWindow::menuClicked);
    connect(bottomBar->btnVolume, &VolumeButton::enter, this, &MainWindow::onBtnVolumeEntered);
    // 音量控制条
    slider = new VolumeSlider(this);
    slider->move(WINDOW_WIDTH - 90, WINDOW_HEIGHT - VOLUME_SLIDER_HEIGHT - 40);
    slider->hide();
}

void MainWindow::menuClicked(int index)
{
    layout->setCurrentIndex(index);
}

void MainWindow::onBtnVolumeEntered(bool status)
{
    qDebug() << status;
    if (status)
    {
        slider->show();
    }
    else
    {
        slider->hide();
    }
}

void MainWindow::onSearch()
{
    layout->setCurrentIndex(0);
    leftMenus->setCurrentRow(0);
}

MainWindow::~MainWindow()
{
}
