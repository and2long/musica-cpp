#include "SearchPage.h"
#include "constants.h"
#include <QListWidget>
#include "ItemSong.h"
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

SearchPage::SearchPage(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);

    QListWidget *items = new QListWidget(this);
    items->setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);

    QFile f(":/search_result.json");

    if(!f.open(QIODevice::ReadOnly))
    {
        qDebug() << "could't open projects json";
        return;
    }
    else
    {
        QByteArray data = f.readAll();
        f.close();
        QJsonParseError error;
        QJsonDocument doc(QJsonDocument::fromJson(data, &error));
        if (error.error != QJsonParseError::NoError)
        {
            qDebug() << "json parse error!";
        }
        else
        {
            QJsonObject obj = doc.object();
            QJsonObject result = obj.value("result").toObject();
            QJsonArray songs = result.value("songs").toArray();
            for (int i = 0; i < songs.size();  i++) {
                QJsonObject song = songs[i].toObject();
                ItemSong *widget = new ItemSong(i, Song(song));
                QListWidgetItem *item = new QListWidgetItem;
                items->addItem(item);
                items->setItemWidget(item, widget);
                connect(widget, SIGNAL(clicked(Song)),this,  SLOT(onItemClicked(Song)));
            }
        }
    }

}

void SearchPage::onItemClicked(Song song)
{
    emit itemClicked(song);
}

void SearchPage::onSearch(QString keyword)
{
    qDebug() << "搜索关键字：" << keyword;
}
