#include "Toast.h"
#include <QLabel>
#include <QTimer>
#include <QStyleOption>
#include <QPainter>

Toast::Toast(QString msg, QWidget *parent)
    : QWidget{parent}, msg(msg)
{
    setWindowFlag(Qt::FramelessWindowHint);

    QLabel *label = new QLabel(this);
    label->setText(msg);
    label->setMinimumWidth(200);
    label->setMinimumHeight(50);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("background-color: black; color: white; border-radius: 10px;");

    QTimer* timer = new QTimer(this);
    timer->start(3000);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &Toast::onTimeout);
}

void Toast::onTimeout()
{
    delete this;
}
