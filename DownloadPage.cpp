#include "DownloadPage.h"
#include <QLabel>
#include "constants.h"

DownloadPage::DownloadPage(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);
    QLabel *tip = new QLabel("快去下载吧！", this);
    tip->setAlignment(Qt::AlignCenter);
}
