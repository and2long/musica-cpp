#include "VolumeSlider.h"
#include "constants.h"

VolumeSlider::VolumeSlider(QWidget *parent)
    : QWidget{parent}
{
    // 背景
    QLabel *bg = new QLabel(this);
    bg->setFixedSize(VOLUME_SLIDER_WIDTH, VOLUME_SLIDER_HEIGHT);
    bg->setObjectName("bg");
    // 进度条
    slider = new QSlider(Qt::Orientation::Vertical, this);
    slider->setFixedSize(VOLUME_SLIDER_WIDTH, VOLUME_SLIDER_HEIGHT - 16);
    slider->move(0, 10);
}
