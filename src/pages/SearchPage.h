#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QWidget>
#include "src/models/Song.h"
#include <QListWidget>

class SearchPage: public QWidget
{
Q_OBJECT
public:
    explicit SearchPage(QWidget *parent = nullptr);

    // 设置数据
    void setData(const QByteArray& data);

    // 设置模版数据
    void setTemplates();

private:
    QListWidget *items;

public slots:

    void onSongDoubleClickEvent(Song &song);

    void onSearch(const QString& keyword);

signals:

    void songDoubleClicked(Song &song);
};

#endif // SEARCHPAGE_H
