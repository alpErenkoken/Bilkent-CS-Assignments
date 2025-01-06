//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#include "User.h"

User::User()
{
    id=0;
    name="";
}

User::~User()
{
    playlistOfU.clear();
}

User::User(const int& id, const string& name)
{
    this->id=id;
    this->name=name;
}

User::User(const User& other) : id(other.id), name(other.name), playlistOfU(other.playlistOfU) {}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        id = other.id;
        name = other.name;
        playlistOfU = other.playlistOfU;
    }
    return *this;
}

void User::addPlaylist(Playlist& playlist,const int& posToInsert)
{
    playlistOfU.insert(posToInsert,playlist);
}

void User::removePlaylist(const int& posToRemove)
{
    playlistOfU.remove(posToRemove);
}

void User::setPlaylist(LinkedList<Playlist>& playlist)
{
    playlistOfU.clear();
    playlistOfU=playlist;
}

int User::getId() const
{
    return id;
}
string User::getName() const
{
    return name;
}

LinkedList<Playlist> User::getPlaylists() const
{
    return playlistOfU;
}


