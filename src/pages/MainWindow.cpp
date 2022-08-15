#include "MainWindow.h"
#include "src/components/TopBar.h"
#include "SearchPage.h"
#include "DownloadPage.h"
#include "FavoritePage.h"
#include "src/constants.h"
#include "src/components/VolumeButton.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("MUSICA");
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    // 左侧菜单
    leftMenus = new LeftMenus(this);
    // 顶部快捷搜索栏
    auto *topBar = new TopBar(this);
    topBar->move(LEFT_MENUS_WIDTH, 0);
    // 中间层叠容器
    auto *container = new QWidget(this);
    container->setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    layout = new QStackedLayout();
    layout->setStackingMode(QStackedLayout::StackingMode::StackOne);
    container->setLayout(layout);
    container->move(LEFT_MENUS_WIDTH, TOP_BAR_HEIGHT);
    // 搜索页面
    searchPage = new SearchPage();
    layout->addWidget(searchPage);
    // 收藏界面
    favoritePage = new FavoritePage();
    layout->addWidget(favoritePage);
    // 下载界面
    auto *downloadPage = new DownloadPage();
    layout->addWidget(downloadPage);
    // 底部控制栏
    bottomBar = new BottomBar(Song(), this);
    bottomBar->move(0, 610);
    // 连接
    connect(searchPage, &SearchPage::songDoubleClicked, bottomBar, &BottomBar::onSongDoubleClickEvent);
    connect(favoritePage, &FavoritePage::songDoubleClicked, bottomBar, &BottomBar::onSongDoubleClickEvent);
    connect(topBar, &TopBar::search, searchPage, &SearchPage::onSearch);
    connect(topBar, &TopBar::search, this, &MainWindow::onSearch);
    connect(leftMenus, &LeftMenus::menuClicked, this, &MainWindow::menuClicked);
    connect(bottomBar->btnVolume, &VolumeButton::clicked, this, &MainWindow::onVolumeBtnClicked);
    connect(bottomBar->btnList, &VolumeButton::clicked, this, &MainWindow::onListBtnClicked);
    // 音量控制条
    volumeSlider = new VolumeSlider(this);
    volumeSlider->move(WINDOW_WIDTH - 90, WINDOW_HEIGHT - VOLUME_SLIDER_HEIGHT - 45);
    volumeSlider->hide();
    // 播放列表
    playList = new PlayList(this);
    playList->move(WINDOW_WIDTH - PLAY_LIST_WIDTH, TOP_BAR_HEIGHT);
    playList->hide();
}

void MainWindow::menuClicked(int index) {
    layout->setCurrentIndex(index);
    if (index == 0) {
        searchPage->setTemplates();
    }
    if (index == 1) {
        favoritePage->initData();
    }
}

void MainWindow::onVolumeBtnClicked() {
    if (volumeSlider->isHidden()) {
        volumeSlider->show();
        bottomBar->btnVolume->setStyleSheet("background-color: black; border-radius: 8px;");
    } else {
        volumeSlider->hide();
        bottomBar->btnVolume->setStyleSheet("");
    }
}

void MainWindow::onListBtnClicked() {
    if (playList->isHidden()) {
        playList->show();
        bottomBar->btnList->setStyleSheet("background-color: black; border-radius: 8px;");
    } else {
        playList->hide();
        bottomBar->btnList->setStyleSheet("");
    }
}

void MainWindow::onSearch() {
    layout->setCurrentIndex(0);
    leftMenus->setCurrentRow(0);
}

MainWindow::~MainWindow() = default;
