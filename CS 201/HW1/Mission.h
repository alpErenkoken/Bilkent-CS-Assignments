//
// Alp Eren Köken Section:3 22202876
//

//
#ifndef MISSION_H
#define MISSION_H


#include <string>
#include "Spacecraft.h"
using namespace std;


class Mission {

public:

    Mission(const string& name,const string& date,const string& destination);
    Mission();

    ~Mission();
    Mission(const Mission& other);
    Mission& operator=(const Mission& mission);

    //getters
    string getName();
    string getDate();
    string getDestination();
    Spacecraft* getAssignedSc();
    int getScCount();

    //helper methods
    void addAssignedSc(Spacecraft& sc);
    void setScCount(int x);
    void removeAssignedSc(Spacecraft& removeSc);
    void dropAssignedSc();

private:

    string name;
    string date;
    string destination;
    Spacecraft* assignedSc;
    int scCount;

};




#endif //MISSION_H