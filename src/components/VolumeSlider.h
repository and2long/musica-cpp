#ifndef VOLUMESLIDER_H
#define VOLUMESLIDER_H

#include <QWidget>
#include <QLabel>
#include <QSlider>

class VolumeSlider : public QWidget
{
    Q_OBJECT
public:
    explicit VolumeSlider(QWidget *parent = nullptr);
protected:
    virtual void enterEvent(QEnterEvent *event);
    virtual void leaveEvent(QEvent *event);

signals:
    void enter(bool status);

private:
    QSlider *slider;
};

#endif // VOLUMESLIDER_H
