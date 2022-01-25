#include "main_window.h"
#include <left_menus.h>
#include "constants.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("MUSICA");
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    new LeftMenus(this);

}

MainWindow::~MainWindow()
{
}
