#include "TopBar.h"
#include "constants.h"
#include <QLineEdit>
#include <QLabel>

TopBar::TopBar(QWidget *parent)
    : QWidget{parent}
{
    QLabel *bg = new QLabel(this);
    bg->setFixedSize(WINDOW_WIDTH - LEFT_MENUS_WIDTH, TOP_BAR_HEIGHT);
    bg->setObjectName("bg");
    QLineEdit *searchBox  = new QLineEdit(this);
    searchBox->setClearButtonEnabled(true);
    searchBox->setFixedSize(300, 28);
    searchBox->move((WINDOW_WIDTH - LEFT_MENUS_WIDTH) / 2 - 150, 11);
}
