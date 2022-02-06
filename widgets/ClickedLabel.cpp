#include "ClickedLabel.h"
#include <QLabel>

ClickedLabel::ClickedLabel(QWidget *parent, int index) : QLabel{parent}, index(index)
{

}

void ClickedLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    (void)ev;
    emit clicked();
}
