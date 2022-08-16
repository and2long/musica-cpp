#include "SearchPage.h"
#include "src/constants.h"
#include <QListWidget>
#include "src/components/ItemSong.h"
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <src/db/database.h>

SearchPage::SearchPage(QWidget *parent)
    : QWidget{parent}
{
    items = new QListWidget(this);
    items->setFixedSize(CONTAINER_WIDTH, CONTAINER_HEIGHT);

    setTemplates();
}

void SearchPage::setData(QByteArray data)
{
    QList<Song> favoriteSongs = Database::queryAllFavoriteItems();
    QList<int> ids = {};
        foreach (Song item, favoriteSongs) {
            ids.append(item.sid);
        }
    QJsonParseError error;
    QJsonDocument doc(QJsonDocument::fromJson(data, &error));
    if (error.error != QJsonParseError::NoError) {
        qDebug() << "json parse error!\n"
                 << error.errorString();
    }
    else {
        items->clear();
        QJsonObject obj = doc.object();
        QJsonObject result = obj.value("result").toObject();
        QJsonArray songs = result.value("songs").toArray();
        for (int i = 0; i < songs.size(); i++) {
            QJsonObject songObj = songs[i].toObject();
            Song song = Song(songObj);
            song.isFavorite = ids.contains(song.sid);
            auto *widget = new ItemSong(i, song);
            auto *item = new QListWidgetItem;
            items->addItem(item);
            items->setItemWidget(item, widget);
            connect(widget, &ItemSong::doubleClicked, this, &SearchPage::onSongDoubleClickEvent);
        }
    }
}

void SearchPage::setTemplates()
{
    QFile f(":/assets/templates/search_result.json");

    if (!f.open(QIODevice::ReadOnly)) {
        qDebug() << "could't open projects json";
        return;
    }
    else {
        QByteArray data = f.readAll();
        f.close();
        setData(data);
    }
}

void SearchPage::onSongDoubleClickEvent(Song song)
{
    emit songDoubleClicked(song);
}

void SearchPage::onSearch(QString keyword)
{
    qDebug() << "搜索关键字：" << keyword;
    QUrl url("http://music.163.com/api/search/get?offset=0&limit=20&total=true&type=1&s=" + keyword);
    QNetworkAccessManager manager;
    QEventLoop loop;

    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        //        qDebug().noquote() << data;
        setData(data);
        reply->deleteLater();
    }
}
