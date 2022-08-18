#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H

#include <QLabel>

class ClickedLabel: public QLabel
{
Q_OBJECT
public:
    explicit ClickedLabel(QWidget *parent = nullptr);

    void mouseReleaseEvent(QMouseEvent *ev) override;

signals:

    void clicked();
};

#endif // CLICKEDLABEL_H
