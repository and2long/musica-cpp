#include "MainWindow.h"
#include <LeftMenus.h>
#include "constants.h"
#include "TopBar.h"
#include "SearchPage.h"
#include "BottomBar.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("MUSICA");
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    new LeftMenus(this);

    TopBar *topBar =  new TopBar(this);
    topBar->move(LEFT_MENUS_WIDTH, 0);

    SearchPage *searchPage = new SearchPage(this);
    searchPage->move(LEFT_MENUS_WIDTH, TOP_BAR_HEIGHT);

    BottomBar *bottomBar = new BottomBar(Song(), this);
    bottomBar->move(0, 610);

    connect(searchPage, SIGNAL(itemClicked(Song)), bottomBar, SLOT(onSongClickedListener(Song)));

}

MainWindow::~MainWindow()
{
}
