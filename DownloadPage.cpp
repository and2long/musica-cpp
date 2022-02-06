#include "DownloadPage.h"
#include <QLabel>
#include "constants.h"

DownloadPage::DownloadPage(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    QLabel *tip = new QLabel("还没有下载的音乐哦，快去下载吧～", this);
    tip->setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    tip->setAlignment(Qt::AlignCenter);
}
