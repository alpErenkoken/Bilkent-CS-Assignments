//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#include "Playlist.h"

#include "Song.h"

Playlist::Playlist()
{
    id=0;
}

Playlist::~Playlist()
{
    songs.clear();
}

Playlist::Playlist(const int& id)
{
    this->id=id;
}

Playlist::Playlist(const Playlist& other) : id(other.id), songs(other.songs) {}

Playlist& Playlist::operator=(const Playlist& other)
{
    if (this != &other)
    {
        id = other.id;
        songs = other.songs;
    }
    return *this;
}


void Playlist::addSong(const int& id)
{
    songs.insert(songs.getLength()+1,id);
}

void Playlist::setSongs(LinkedList<int>& newSongs)
{
    songs=newSongs;
}

int Playlist::getId() const
{
    return id;
}

LinkedList<int> Playlist::getSongs()
{
    return songs;
}







