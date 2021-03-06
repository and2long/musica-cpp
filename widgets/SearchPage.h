#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QWidget>
#include "Song.h"
#include <QListWidget>

class SearchPage : public QWidget
{
    Q_OBJECT
public:
    explicit SearchPage(QWidget *parent = nullptr);
    // 设置数据
    void setData(QByteArray data);
    // 设置模版数据
    void setTemplates();

private:
    QListWidget *items;

public slots:
    void onItemClicked(Song song);
    void onSearch(QString keyword);

signals:
    void itemClicked(Song song);
};

#endif // SEARCHPAGE_H
