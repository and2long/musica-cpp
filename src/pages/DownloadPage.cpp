#include "DownloadPage.h"
#include <QLabel>
#include "src/constants.h"

DownloadPage::DownloadPage(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    auto *tip = new QLabel("还没有下载的音乐哦，快去下载吧～", this);
    tip->setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    tip->setAlignment(Qt::AlignCenter);
    tip->setStyleSheet("color: #B7B7B7");
}
