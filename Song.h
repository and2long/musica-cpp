#ifndef SONG_H
#define SONG_H
#include <QString>
#include <string>
using namespace std;
#include <QJsonObject>

class  Song
{
public:
    int id;
    int duration;
    QString name;
    QString artists;
    Song(int id, QString name, QString artists, int duration);
    Song(QJsonObject obj);

    QString toString();
};

#endif // SONG_H
