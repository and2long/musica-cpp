#ifndef VOLUMEBUTTON_H
#define VOLUMEBUTTON_H

#include "ClickedLabel.h"
#include <QObject>

class VolumeButton : public ClickedLabel
{
    Q_OBJECT
public:
    VolumeButton(QWidget *parent = nullptr);
protected:
    virtual void enterEvent(QEnterEvent *event);
    virtual void leaveEvent(QEvent *event);
};

#endif // VOLUMEBUTTON_H
