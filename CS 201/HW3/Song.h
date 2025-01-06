//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

class Song {


public:
    Song();
    ~Song();
    Song(const int& id,const string& name,const string& artist);

    int getId() const;
    string getName() const;
    string getArtist() const;

private:

    int songId;
    string songName;
    string songArtist;

};



#endif //SONG_H
