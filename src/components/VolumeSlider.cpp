#include "VolumeSlider.h"
#include "src/constants.h"

VolumeSlider::VolumeSlider(QWidget *parent)
        : QWidget{parent} {
    // 背景
    auto *bg = new QLabel(this);
    bg->setFixedSize(VOLUME_SLIDER_WIDTH, VOLUME_SLIDER_HEIGHT);
    bg->setObjectName("bg");
    // 进度条
    slider = new QSlider(Qt::Orientation::Vertical, this);
    slider->setFixedSize(VOLUME_SLIDER_WIDTH, VOLUME_SLIDER_HEIGHT - 16);
    slider->move(0, 10);
    slider->setMaximum(100);
    slider->setValue(50);
}

void VolumeSlider::enterEvent(QEnterEvent *event) {
    (void) event;
    emit enter(true);
}

void VolumeSlider::leaveEvent(QEvent *event) {
    (void) event;
    emit enter(false);
}
