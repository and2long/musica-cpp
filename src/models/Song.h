#ifndef SONG_H
#define SONG_H

#include <QJsonObject>

class Song
{
public:
    // 歌曲id
    int sid;
    // 歌曲时长
    int duration;
    // 歌曲名
    QString name;
    // 歌曲演唱者
    QString artists;
    // 专辑封面
    QString album;
    // 是否被收藏
    bool isFavorite;

    Song();

    Song(int sid, QString name, QString artists, int duration, QString album, bool isFavorite = false);

    Song(QJsonObject obj);

    QString toString();
};

#endif // SONG_H
