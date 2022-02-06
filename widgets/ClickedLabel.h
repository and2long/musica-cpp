#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H

#include <QLabel>

class ClickedLabel : public QLabel
{
    Q_OBJECT
public:
    // 当前索引（左侧菜单索引值变化）
    int index;

    ClickedLabel(QWidget *parent = nullptr, int index = 0);

    void mouseReleaseEvent(QMouseEvent *ev);

signals:
    void clicked();
};

#endif // CLICKEDLABEL_H
