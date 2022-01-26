#include "Song.h"
#include <string>

Song::Song(int songId, string songName, string songArtists, int songDuration)
{
    id = songId;
    name = songName;
    duration = songDuration;
    artists = songArtists;
};

string Song::toString()
{
    return  "id:" + to_string(id) + ", name:" + name;
}
