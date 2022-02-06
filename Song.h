#ifndef SONG_H
#define SONG_H
#include <QJsonObject>

class  Song
{
public:
    // 歌曲id
    int id;
    // 歌曲时长
    int duration;
    // 歌曲名
    QString name;
    // 歌曲演唱者
    QString artists;
    // 专辑封面
    QString album;
    Song(int id, QString name, QString artists, int duration, QString album);
    Song(QJsonObject obj);
    Song();

    QString toString();
};

#endif // SONG_H
