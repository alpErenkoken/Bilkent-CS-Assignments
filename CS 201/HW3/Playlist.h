//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "LinkedList.h"
#include "Song.h"
using namespace std;


class Playlist {

public:

    Playlist();
    ~Playlist();
    Playlist(const int& id);
    Playlist(const Playlist& other);
    Playlist& operator=(const Playlist& other);

    int getId() const;
    LinkedList<int> getSongs();

    void addSong(const int& id);
    void setSongs(LinkedList<int>& newSongs);

private:

    int id;
    LinkedList<int> songs;

};



#endif //PLAYLIST_H
