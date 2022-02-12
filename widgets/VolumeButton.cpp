#include "VolumeButton.h"

VolumeButton::VolumeButton(QWidget *parent): ClickedLabel{parent}
{

}

void VolumeButton::enterEvent(QEnterEvent *event)
{
    (void)event;
    emit enter(true);
}
void VolumeButton::leaveEvent(QEvent *event)
{
    (void)event;
    emit enter(false);
}
