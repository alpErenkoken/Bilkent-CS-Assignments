//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#ifndef BILKENTBEATS_H
#define BILKENTBEATS_H
#include <string>

#include "LinkedList.h"
#include "Playlist.h"
#include "User.h"

using namespace std;

class BilkentBeats {

public:

    BilkentBeats();
    ~BilkentBeats();

    void addUser( const int userId, const string userName );
    void removeUser( const int userId );
    void printUsers() const;

    void addSong( const int songID, const string songName, const string artists );
    void removeSong( const int songID );
    void printSongs() const;

    void addPlaylist( const int userId, const int playlistId );
    void removePlaylist( const int userId, const int playlistId );
    void addSongToPlaylist( const int playlistId, const int songId );
    void removeSongFromPlaylist( const int playlistId, const int songId );
    void printSongsInPlaylist( const int playlistId ) const;


    bool isSongExistAlready(int playlistID, int songId);
    bool isExistU(const int& userId)const;
    bool isExistS(const int& userId)const;
    bool isExistP(const int& id)const;
    int giveUserPos(const int& id)const;
    int giveSongPos(const int& id) const;
    int givePlaylistPos(const int& playlistId, const int& userPos)const;
    bool isUserHasPlaylist(int uID, int pID);

    int getSuitablePosU(const int& userId);
    int getSuitablePosS(const int& songId);
    int getSuitablePosPU(const int& playlistId, const int& userPos);


private:

    LinkedList<User> users;
    LinkedList<Song> songs;

};



#endif //BILKENTBEATS_H
