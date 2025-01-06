//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#ifndef USER_H
#define USER_H
#include <string>

#include "LinkedList.h"
#include "Playlist.h"

using namespace std;

class User {

public:

    User();
    ~User();
    User(const int& id,const string& name);
    User(const User& other);
    User& operator=(const User& other);

    void addPlaylist(Playlist& playlist,const int& posToInsert);
    void removePlaylist(const int& posToRemove);
    void setPlaylist(LinkedList<Playlist>& playlist);

    int getId() const;
    string getName() const;
    LinkedList<Playlist> getPlaylists() const;

private:

    int id;
    string name;
    LinkedList<Playlist> playlistOfU;

};



#endif //USER_H
