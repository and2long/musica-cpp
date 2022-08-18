#include "Song.h"
#include <QJsonArray>
#include <utility>

Song::Song()
{
    sid = 0;
}

Song::Song(int songId, QString songName, QString songArtists, int songDuration, QString songAlbum, bool favorite)
{
    sid = songId;
    duration = songDuration;
    isFavorite = favorite;
    name = std::move(songName);
    artists = std::move(songArtists);
    album = std::move(songAlbum);
}

Song::Song(const QJsonObject &song)
{
    int songId = song.value("id").toInt();
    int songDuration = song.value("duration").toInt();
    QString songName = song.value("name").toString();
    QString songAlbum = song.value("album").toObject().value("artist").toObject().value("img1v1Url").toString();
    QJsonArray ats = song.value("artists").toArray();
    QString singer;
    if (ats.size() == 1) {
        singer = ats[0].toObject().value("name").toString();
    }
    else {
        for (int ii = 0; ii < ats.size(); ii++) {
            if (ii == 0) {
                singer += ats[0].toObject().value("name").toString();
            }
            else {
                singer += ("/" + ats[ii].toObject().value("name").toString());
            }
        }
    }
    sid = songId;
    name = songName;
    duration = songDuration;
    artists = singer;
    album = songAlbum;
}

QString Song::toString()
{
    return QString("id: %1, name: %2, duration: %3, artists: %4, album: %5, isFavorite: %6")
        .arg(QString::number(sid), name, QString::number(duration), artists, album, QString::number(isFavorite));
}
