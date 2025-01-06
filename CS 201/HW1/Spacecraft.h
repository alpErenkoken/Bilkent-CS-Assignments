//
// Alp Eren Köken Section:3 22202876
//



#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include <string>


using namespace std;

class Mission;

class Spacecraft {

public:
    Spacecraft(const string& name,const string& type);
    Spacecraft();

    string getName();
    string getType();
    string getAvailability();
    Mission* getMission();

    void setAvailability(const string& availability);
    void dropMission();
    void setMission(Mission* mission);



private:

    string name;
    string type;
    string availability="Available";
    Mission* scMission;

};



#endif //SPACECRAFT_H