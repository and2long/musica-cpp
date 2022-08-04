#include "ClickedLabel.h"
#include <QLabel>

ClickedLabel::ClickedLabel(QWidget *parent) : QLabel{parent}
{
}

void ClickedLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    (void)ev;
    emit clicked();
}
