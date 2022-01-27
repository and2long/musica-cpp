#include "Song.h"
#include <string>
#include <QJsonArray>

Song::Song(int songId, QString songName, QString songArtists, int songDuration)
{
    id = songId;
    name = songName;
    duration = songDuration;
    artists = songArtists;
};

Song::Song(QJsonObject song)
{
    int songId = song.value("id").toInt();
    int songDuration = song.value("duration").toInt();
    QString songName = song.value("name").toString();
    QJsonArray ats = song.value("artists").toArray();
    QString singer;
    if (ats.size() == 1)
    {
        singer = ats[0].toObject().value("name").toString();
    }
    else
    {
        for (int ii = 0; ii < ats.size(); ii++) {
            if(ii == 0)
            {
                singer += ats[0].toObject().value("name").toString();
            }
            else{
                singer += ("/" + ats[ii].toObject().value("name").toString());
            }
        }
    }
    id = songId;
    name = songName;
    duration = songDuration;
    artists = singer;
}
QString Song::toString()
{
    return  QString::fromStdString("id:" + to_string(id) + ", name:" + name.toStdString());
}
