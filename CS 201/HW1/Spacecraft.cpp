//
// Alp Eren Köken Section:3 22202876
//


#include "Spacecraft.h"
#include "Mission.h"
#include <string>
using namespace std;


Spacecraft::Spacecraft(const string& name, const string& type)
    : name(name), type(type),availability("Available"),scMission(nullptr){};

Spacecraft::Spacecraft()
{
    name = "";
    type = "";
    availability="Available";
    scMission=nullptr;
}

string Spacecraft::getName()
{
    return name;
}
string Spacecraft::getType()
{
    return type;
}
string Spacecraft::getAvailability()
{
    return availability;
}
Mission* Spacecraft::getMission()
{
    return scMission;
}
void Spacecraft::setMission(Mission* mission)
{
    scMission = mission;
}

void Spacecraft::dropMission()
{
    this->scMission = nullptr;
}

void Spacecraft::setAvailability(const string& availability)
{
    this->availability = availability;
}