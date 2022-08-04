#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H

#include <QLabel>

class ClickedLabel : public QLabel
{
    Q_OBJECT
public:
    ClickedLabel(QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:
    void clicked();
};

#endif // CLICKEDLABEL_H
