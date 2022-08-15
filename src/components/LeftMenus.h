#ifndef LEFTMENUS_H
#define LEFTMENUS_H

#include <QWidget>
#include <QListWidgetItem>

class LeftMenus : public QWidget {
Q_OBJECT
public:
    explicit LeftMenus(QWidget *parent = nullptr);

    void setCurrentRow(int index);

private:
    QListWidget *items;

signals:

    void menuClicked(int index);

public slots:

    void itemClicked(QListWidgetItem *item);
};

#endif // LEFTMENUS_H
