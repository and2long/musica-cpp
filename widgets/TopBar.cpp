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
    searchBox  = new QLineEdit(this);
    searchBox->setClearButtonEnabled(true);
    searchBox->setFixedSize(300, 28);
    searchBox->move((WINDOW_WIDTH - LEFT_MENUS_WIDTH) / 2 - 150, 11);
    searchBox->setPlaceholderText("关键字搜索");

    connect(searchBox, SIGNAL(returnPressed()), this, SLOT(onSearch()));
}

void TopBar::onSearch()
{
    QString keyword = searchBox->text();
    if (keyword != "")
    {
        emit search(searchBox->text());
    }
}
