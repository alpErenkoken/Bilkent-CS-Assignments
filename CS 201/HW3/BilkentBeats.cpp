//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#include "BilkentBeats.h"

#include "LinkedList.h"
#include "Song.h"
#include "User.h"

BilkentBeats::BilkentBeats(){}

BilkentBeats::~BilkentBeats(){}

int BilkentBeats::getSuitablePosU(const int& userId)
{
    int pos=1;

        for(int i=1;i<=users.getLength();i++)
        {
            if(users.getEntry(i).getId()>userId)
            {
                pos=i;
                return pos;
            }

            pos++;
        }

    return pos;
}

int BilkentBeats::getSuitablePosS(const int& songId)
{
    int pos=1;
    for(int i=1;i<=songs.getLength();i++)
    {
        if(songs.getEntry(i).getId()>songId)
        {
            pos=i;
            return pos;
        }

        pos++;
    }
    return pos;
}

int BilkentBeats::getSuitablePosPU(const int& playlistId,const int& userPos)
{
    LinkedList<Playlist>playlistOfUsers=users.getEntry(userPos).getPlaylists();
    int pos=1;

    for(int i=1;i<=playlistOfUsers.getLength();i++)
    {
        if(playlistOfUsers.getEntry(i).getId()>playlistId)
        {
            pos=i;
            return pos;
        }

        pos++;
    }
    return pos;
}

bool BilkentBeats::isExistU(const int& userId)const
{
    bool isExistID=false;

    for(int i=1;i<=users.getLength();i++)
    {
        if(users.getEntry(i).getId()==userId)
        {
            isExistID=true;
        }
    }
    return isExistID;
}

bool BilkentBeats::isExistS(const int& id)const
{
    bool isExistID=false;

    for(int i=1;i<=songs.getLength();i++)
    {
        if(songs.getEntry(i).getId()==id)
        {
            isExistID=true;
        }
    }
    return isExistID;
}

bool BilkentBeats::isExistP(const int& id)const
{
    bool isExistID=false;
    for(int i=1;i<=users.getLength();i++)
    {
        for(int j=1;j<=users.getEntry(i).getPlaylists().getLength();j++)
        {
            if(users.getEntry(i).getPlaylists().getEntry(j).getId()==id)
            {
                isExistID=true;
            }
        }
    }

    return isExistID;
}

int BilkentBeats::giveUserPos(const int& id)const
{
    for(int i=1;i<=users.getLength();i++)
    {
        if(users.getEntry(i).getId()==id)
        {
            return i;
        }
    }
    return 1;
}

int BilkentBeats::giveSongPos(const int& id)const
{
    for(int i=1;i<=songs.getLength();i++)
    {
        if(songs.getEntry(i).getId()==id)
        {
            return i;
        }
    }
    return 1;
}

int BilkentBeats::givePlaylistPos(const int& playlistId,const int& userPos)const
{
    for(int i=1;i<=users.getEntry(userPos).getPlaylists().getLength();i++)
    {
        if(users.getEntry(userPos).getPlaylists().getEntry(i).getId()==playlistId)
        {
            return i;
        }
    }
    return 1;
}

bool BilkentBeats::isUserHasPlaylist(int uID,int pID)
{
    int userPos=giveUserPos(uID);
    for(int i=1;i<=users.getEntry(userPos).getPlaylists().getLength();i++)
    {
        if(users.getEntry(userPos).getPlaylists().getEntry(i).getId()==pID)
        {
            return true;
        }
    }
    return false;
}


void BilkentBeats::addUser(const int userId, const string userName)
{

    if(isExistU(userId))
    {
        cout<<"Cannot add user. There is already a user with ID "<<userId<<"."<<endl;
    }
    else
    {
        User newUser(userId, userName);
        users.insert(getSuitablePosU(userId),newUser);
        cout<<"Added user "<<userId<<"."<<endl;
    }

}

void BilkentBeats::removeUser(const int userId)
{
    if(isExistU(userId))
    {
        users.remove(giveUserPos(userId));//remove playlists for this user.//remove user.
        cout<<"Removed user "<<userId<<"."<<endl;
    }
    else
    {
        cout<<"Cannot remove user. There is no user with ID "<<userId<<"."<<endl;
    }
}

void BilkentBeats::printUsers() const {

    if (users.isEmpty())
    {
        cout << "There are no users to show." << endl;
        return;
    }

    cout << "Users in the system:" << endl;

    for (int i = 1; i <= users.getLength(); ++i)
    {
        const User& user = users.getEntry(i);

        cout << "User ID : " << user.getId()
             << ", Name : " << user.getName()
             << ", Playlist IDs : ";

        const LinkedList<Playlist>& playlists = user.getPlaylists();

        if (playlists.isEmpty())
        {
            cout << "None";
        }
        else
        {
            cout << "[";
            for (int j = 1; j <= playlists.getLength(); ++j)
            {
                cout << playlists.getEntry(j).getId();
                if (j < playlists.getLength())
                {
                    cout << ",";
                }
            }
            cout << "]";
        }

        cout << endl;
    }
}

void BilkentBeats::addSong(const int id, const string songName, const string artists)
{
    if(isExistS(id))
    {
        cout<<"Cannot add song. BilkentBeats already contains song "<<id<<"."<<endl;
    }
    else
    {
        Song newSong(id, songName, artists);
        songs.insert(getSuitablePosS(id),newSong);
        cout<<"Added song "<<id<<"."<<endl;
    }
}

void BilkentBeats::removeSong(const int songID) {
    if (isExistS(songID)) {
        for (int i = 1; i <= users.getLength(); ++i) {
            User user = users.getEntry(i);
            LinkedList<Playlist> userPlaylists = user.getPlaylists();

            for (int j = 1; j <= userPlaylists.getLength(); ++j) {
                Playlist playlist = userPlaylists.getEntry(j);
                LinkedList<int> songIds = playlist.getSongs();

                for (int k = 1; k <= songIds.getLength(); ++k) {
                    if (songIds.getEntry(k) == songID) {
                        songIds.remove(k);
                        playlist.setSongs(songIds);
                        userPlaylists.replace(j, playlist);
                        user.setPlaylist(userPlaylists);
                        users.replace(i, user);
                        break;
                    }
                }
            }
        }

        songs.remove(giveSongPos(songID));
        cout << "Removed song " << songID << "." << endl;
    } else {
        cout << "Cannot remove song. There is no song with ID " << songID << "." << endl;
    }
}


void BilkentBeats::printSongs() const
{
    if(songs.isEmpty())
    {
        cout<<"Cannot print songs. There is no song in the music library."<<endl;
    }
    else
    {
        cout<<"Music Library:"<<endl;
        for(int i=1;i<=songs.getLength();i++)
        {
            cout<<"Song "<<songs.getEntry(i).getId()<<" : "<<songs.getEntry(i).getName()<<" - "<<songs.getEntry(i).getArtist()<<endl;
        }
    }
}

void BilkentBeats::addPlaylist(const int userId, const int playlistId)
{
    if(isExistU(userId))
    {
        if(!isExistP(playlistId))
        {
            Playlist newPlaylist(playlistId);
            int userPos=giveUserPos(userId);
            User newUser=users.getEntry(userPos);
            newUser.addPlaylist(newPlaylist,getSuitablePosPU(playlistId,userPos));

            users.replace(userPos,newUser);
            cout<<"Added playlist "<<playlistId<<" to "<<"user "<<userId<<"."<<endl;
        }
        else
        {
            cout<<"Cannot add playlist. There is a user having a playlist with ID "<<playlistId<<"."<<endl;
        }
    }
    else
    {
        cout<<"Cannot add playlist. There is no user with ID "<<userId<<"."<<endl;
    }

}

void BilkentBeats::removePlaylist(const int userId, const int playlistId)
{

    if(isExistU(userId))
    {
        if(isExistP(playlistId)&&isUserHasPlaylist(userId,playlistId))
        {
            User newUser=users.getEntry(giveUserPos(userId));
            newUser.removePlaylist(givePlaylistPos(playlistId,giveUserPos(userId)));

            users.replace(giveUserPos(userId),newUser);
            cout<<"Removed playlist "<<playlistId<<" from user "<<userId<<"."<<endl;
        }
        else
        {
            cout<<"Cannot remove playlist. User "<<userId<<" does not have a playlist with ID "<<playlistId<<"."<<endl;
        }
    }
    else
    {
        cout<<"Cannot remove playlist. There is no user with ID "<<userId<<"."<<endl;
    }

}


void BilkentBeats::addSongToPlaylist(const int playlistId, const int songId)
{
    if (!isExistS(songId))
    {
        cout << "Cannot add song. There is no song with ID " << songId << "." << endl;
        return;
    }

    if (!isExistP(playlistId))
    {
        cout << "Cannot add song. There is no playlist with ID " << playlistId << "." << endl;
        return;
    }
    if(isSongExistAlready(playlistId,songId))
    {
        cout << "Cannot add song. The playlist already contains song " <<songId<<"."<< endl;
    }
    else
    {

        for (int i = 1; i <= users.getLength(); i++)
        {
            User copyUser=users.getEntry(i);
            LinkedList<Playlist> userPlaylists = copyUser.getPlaylists();

            for (int j = 1; j <= userPlaylists.getLength(); j++)
            {
                if (userPlaylists.getEntry(j).getId() == playlistId)
                {
                    Playlist desiredPlaylist = userPlaylists.getEntry(j);
                    desiredPlaylist.addSong(songId);

                    userPlaylists.replace(j, desiredPlaylist);
                    copyUser.setPlaylist(userPlaylists);
                    users.replace(i,copyUser);

                    cout << "Added song " << songId << " to playlist " << playlistId << "." << endl;

                    return;
                }
            }
        }
    }
}

void BilkentBeats::removeSongFromPlaylist(const int playlistId, const int songId)
{
    if (!isExistP(playlistId))
    {
        cout << "Cannot remove song. There is no playlist with ID " << playlistId << "." << endl;
        return;
    }

    for (int i = 1; i <= users.getLength(); i++)
    {
        User copyUser = users.getEntry(i);
        LinkedList<Playlist> userPlaylists = copyUser.getPlaylists();

        for (int j = 1; j <= userPlaylists.getLength(); j++)
        {
            if (userPlaylists.getEntry(j).getId() == playlistId)
            {
                bool isSongExist = false;

                Playlist desiredPlaylist=userPlaylists.getEntry(j);
                LinkedList<int> songs = desiredPlaylist.getSongs();

                for (int k = 1; k <= songs.getLength(); k++)
                {
                    if (songs.getEntry(k) == songId)
                    {
                        songs.remove(k);

                        desiredPlaylist.setSongs(songs);
                        userPlaylists.replace(j, desiredPlaylist);
                        copyUser.setPlaylist(userPlaylists);
                        users.replace(i,copyUser);

                        isSongExist = true;
                        break;
                    }
                }

                if (isSongExist)
                {
                    userPlaylists.replace(j, userPlaylists.getEntry(j));
                    copyUser.setPlaylist(userPlaylists);
                    users.replace(i, copyUser);
                    cout << "Removed song " << songId << " from playlist " << playlistId << "." << endl;
                }
                else
                {
                    cout << "Cannot remove song. There is no song " << songId << " in playlist " << playlistId << "." << endl;
                }

                return;
            }
        }
    }

    cout << "Cannot remove song. Playlist " << playlistId << " not found in any user's playlists." << endl;
}

void BilkentBeats::printSongsInPlaylist(const int playlistId) const
{
    if (isExistP(playlistId))
    {
        for (int i = 1; i <= users.getLength(); ++i)
        {
            LinkedList<Playlist> playlists = users.getEntry(i).getPlaylists();
            for (int j = 1; j <= playlists.getLength(); ++j)
            {
                if (playlists.getEntry(j).getId() == playlistId)
                {
                    LinkedList<int> songIds = playlists.getEntry(j).getSongs();
                    if (songIds.isEmpty())
                    {
                        cout << "There are no songs to show in playlist " <<playlistId<<"."<<endl;
                    }
                    else
                    {
                        cout << "Songs in playlist " << playlistId << ":" << endl;
                        for (int k = 1; k <= songIds.getLength(); ++k)
                        {
                            int songId = songIds.getEntry(k);
                            Song song = songs.getEntry(giveSongPos(songId));
                            cout << "Song " << songId << " : " << song.getName() << " - " << song.getArtist() << endl;
                        }
                    }
                    return;
                }
            }
        }
    }
    else
    {
        cout << "Cannot print songs. There is no playlist with ID " << playlistId <<"."<< endl;
    }
}
bool BilkentBeats::isSongExistAlready(const int pId,const int sId) {

    bool isExist=false;

    for(int i = 1; i <= users.getLength(); i++)
    {
        for(int j = 1; j <= users.getEntry(i).getPlaylists().getLength(); j++)
        {
            if(users.getEntry(i).getPlaylists().getEntry(j).getId()==pId)
            {
                for(int a = 1; a <= users.getEntry(i).getPlaylists().getEntry(j).getSongs().getLength(); a++)
                {
                    if(users.getEntry(i).getPlaylists().getEntry(j).getSongs().getEntry(a)==sId)
                    {
                        isExist=true;
                    }
                }
            }
        }
    }
    return isExist;
}









