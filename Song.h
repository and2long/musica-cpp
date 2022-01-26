#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class  Song
{
public:
    int id;
    int duration;
    string name;
    string artists;
    Song(int id, string name, string artists, int duration);

    string toString();
};

#endif // SONG_H
