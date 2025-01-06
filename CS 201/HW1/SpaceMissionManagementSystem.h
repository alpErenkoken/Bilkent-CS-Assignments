//
// Alp Eren Köken Section:3 22202876
//



#ifndef SPACEMISSIONMANAGEMENTSYSTEM_H
#define SPACEMISSIONMANAGEMENTSYSTEM_H


#include "Spacecraft.h"
#include "Mission.h"

class SpaceMissionManagementSystem {

public:

    SpaceMissionManagementSystem();

    ~SpaceMissionManagementSystem();
    SpaceMissionManagementSystem(const SpaceMissionManagementSystem& management);
    SpaceMissionManagementSystem& operator=(const SpaceMissionManagementSystem& right);


    void addMission( const string name, const string launchDate, const string destination );
    void removeMission( const string name );
    void addSpacecraft( const string name, const string type );
    void removeSpacecraft( const string name );
    void assignSpacecraftToMission( const string spacecraftName, const string missionName );
    void dropSpacecraftFromMission( const string spacecraftName );
    void showAllMissions() const;
    void showAllSpacecrafts() const;
    void showMission( const string name ) const;
    void showSpacecraft( const string name ) const;

private:

    int countOfMissions;
    int countOfSpacecrafts;
    Mission* missions;
    Spacecraft* spacecrafts;
};


#endif //SPACEMISSIONMANAGEMENTSYSTEM_H
