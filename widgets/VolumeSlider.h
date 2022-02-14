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

signals:

private:
    QSlider *slider;
};

#endif // VOLUMESLIDER_H
