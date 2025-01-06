//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#include "Song.h"

Song::Song()
{
    songId=0;
    songName="";
    songArtist="";
}
Song::~Song(){}

Song::Song(const int& id, const string& name, const string& artist)
{
    this->songId=id;
    this->songName=name;
    this->songArtist=artist;
}

int Song::getId() const
{
    return songId;
}
string Song::getName() const
{
    return songName;
}
string Song::getArtist() const
{
    return songArtist;
}


