#include "VolumeButton.h"

VolumeButton::VolumeButton(QWidget *parent): ClickedLabel{parent}
{

}

void VolumeButton::enterEvent(QEnterEvent *event)
{
    (void)event;
    qDebug() << "enter";
}
void VolumeButton::leaveEvent(QEvent *event)
{
    (void)event;
    qDebug() << "leave";
}
