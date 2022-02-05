#ifndef TOAST_H
#define TOAST_H

#include <QWidget>

class Toast : public QWidget
{
    Q_OBJECT
public:
    explicit Toast(QString msg, QWidget *parent = nullptr);
    QString msg;

signals:

public slots:
    void onTimeout();

};

#endif // TOAST_H
