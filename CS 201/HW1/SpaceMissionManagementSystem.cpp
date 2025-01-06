//
// Alp Eren Köken Section:3 22202876
//



#include "SpaceMissionManagementSystem.h"

#include <iostream>
#include <string>


using namespace std;

SpaceMissionManagementSystem::SpaceMissionManagementSystem()
    : countOfMissions(0), countOfSpacecrafts(0), missions(nullptr), spacecrafts(nullptr) {}


SpaceMissionManagementSystem::~SpaceMissionManagementSystem()
{
    if (missions)
        delete[] missions;
    if (spacecrafts)
        delete[] spacecrafts;
}

SpaceMissionManagementSystem::SpaceMissionManagementSystem(const SpaceMissionManagementSystem& management)
{

    this->countOfMissions = management.countOfMissions;
    this->countOfSpacecrafts = management.countOfSpacecrafts;

        if ( countOfMissions > 0 )
        {
            missions= new Mission[countOfMissions ];
            for ( int i = 0; i < countOfMissions; i++ )
                missions[ i ] = management.missions[ i ];
        }
        else
            missions= nullptr;
    if ( countOfSpacecrafts > 0 )
    {
        spacecrafts= new Spacecraft[countOfSpacecrafts ];
        for ( int i = 0; i < countOfSpacecrafts; i++ )
            spacecrafts[ i ] = management.spacecrafts[ i ];
    }
    else
        spacecrafts= nullptr;

}
SpaceMissionManagementSystem& SpaceMissionManagementSystem:: operator=(const SpaceMissionManagementSystem& right)
{
    if(this==&right)
    {
        return *this;
    }

    if(missions!=nullptr)
    {
        delete []missions;
    }


    missions=new Mission[right.countOfMissions];
    countOfMissions=right.countOfMissions;

    for(int i=0;i<right.countOfMissions;i++)
    {
        missions[i]=right.missions[i];
    }

    if(spacecrafts!=nullptr)
    {
        delete []spacecrafts;
    }


    spacecrafts=new Spacecraft[right.countOfSpacecrafts];
    countOfSpacecrafts=right.countOfSpacecrafts;

    for(int i=0;i<right.countOfSpacecrafts;i++)
    {
        spacecrafts[i]=right.spacecrafts[i];
    }

    return *this;
}


    void SpaceMissionManagementSystem::addMission(const string name,const string date,const string destination)
    {
    if (missions != nullptr)
    {
        for(int i=0;i<countOfMissions;i++)
        {
            if(missions[i].getName()==name)
            {
                cout<<"Cannot add mission. Mission "<<name<<" already exists."<<endl;
                return;
            }
        }
    }

        Mission* new_missions=new Mission [countOfMissions+1];
        Mission addingMission(name,date,destination);

    if(missions==nullptr)
    {
        new_missions[0]=addingMission;
        missions=new_missions;
    }else
    {
        for(int i=0;i<countOfMissions;i++)
        {
            new_missions[i]=missions[i];
        }
        new_missions[countOfMissions]= addingMission;

        delete [] missions;
        missions=new_missions;

    }
    countOfMissions++;
    cout<<"Added mission "<<name<<"."<<endl;

    }

    void SpaceMissionManagementSystem:: removeMission(const string name)
    {

        int indexOfRemoved=-1;

        for(int i=0;i<countOfMissions;i++)
        {
            if(name==missions[i].getName())
            {
                indexOfRemoved=i;
                break;
            }
        }

        if(indexOfRemoved==-1)
        {
            cout<<"Cannot remove mission. Mission "<<name<<" does not exist."<<endl;
            return;
        }

    for(int i=0;i<countOfSpacecrafts;i++)
    {
        if(spacecrafts[i].getAvailability()=="Assigned")
        {
            if(spacecrafts[i].getMission()->getName()==missions[indexOfRemoved].getName())
            {

                spacecrafts[i].setAvailability("Available");
                spacecrafts[i].dropMission();

            }
        }
    }

    if(countOfMissions>1)
    {
        Mission* new_mission=new Mission[countOfMissions-1];

        for(int i=indexOfRemoved;i<countOfMissions-1;i++)
        {
            missions[i]=missions[i+1];
        }
        for(int i=0;i<countOfMissions-1;i++)
        {
            new_mission[i]=missions[i];
        }

        delete [] missions;
        missions=new_mission;
    }
    else
    {
        delete [] missions;
        missions=nullptr;
    }
    countOfMissions--;

        cout<<"Removed mission "<<name<<"."<<std::endl;
    }



    void SpaceMissionManagementSystem:: addSpacecraft(const string name,const string type)
    {
    if(spacecrafts!=nullptr)
    {
        for(int i=0;i<countOfSpacecrafts;i++)
        {
            if(spacecrafts[i].getName()==name)
            {
                cout << "Cannot add spacecraft. Spacecraft "<<name<<" already exists."<<std::endl;
                return;
            }
        }
    }

    Spacecraft* new_spacecrafts=new Spacecraft[countOfSpacecrafts+1];
    Spacecraft addingSpacecraft(name,type);
    if(spacecrafts==nullptr)
    {
        new_spacecrafts[0]=addingSpacecraft;
        spacecrafts=new_spacecrafts;
    }
    else
    {
        for(int i=0;i<countOfSpacecrafts;i++)
        {
            new_spacecrafts[i]=spacecrafts[i];
        }

        delete [] spacecrafts;
        new_spacecrafts[countOfSpacecrafts]=addingSpacecraft;
        spacecrafts=new_spacecrafts;

    }
        countOfSpacecrafts++;

        cout<<"Added spacecraft "<<name<<"."<<std::endl;

    }

    void SpaceMissionManagementSystem:: removeSpacecraft(const string name)
{
    bool isExist=false;
    bool isAvailable=false;
    bool control=true;
    int indexOfRemove;

    for(int i=0;i<countOfSpacecrafts;i++)
    {

        if(spacecrafts[i].getName()==name)
        {
            isExist=true;
            if(spacecrafts[i].getAvailability()=="Available")
            {
                isAvailable=true;
            }
        }

        if(isExist && isAvailable && control)
        {
            indexOfRemove=i;
            control=false;
        }

    }

    if(!(isExist && isAvailable))
    {
        if(isExist)
        {
            cout<<"Cannot remove spacecraft. Spacecraft "<<name<<" is assigned to a mission."<<endl;

        }
        else
        {
            cout<<"Cannot remove spacecraft. Spacecraft "<<name<<" does not exist."<<std::endl;


        }
        return;
    }


    if(countOfSpacecrafts>1)
        {
    Spacecraft* new_spacecrafts=new Spacecraft [countOfSpacecrafts-1];

    for(int i=indexOfRemove;i<countOfSpacecrafts-1;i++)
    {
        spacecrafts[i]=spacecrafts[i+1];
    }

    for(int i=0;i<countOfSpacecrafts-1;i++)
    {
        new_spacecrafts[i]=spacecrafts[i];
    }

    delete [] spacecrafts;
    spacecrafts=new_spacecrafts;
        }
    else
        {
        delete [] spacecrafts;
        spacecrafts=nullptr;
        }

    countOfSpacecrafts--;

    cout<<"Removed spacecraft "<<name<<"."<<endl;

    }

    void SpaceMissionManagementSystem::assignSpacecraftToMission(const string scname,const string mname)
    {
        bool isscExist=false;
        bool isMAssignable=false;
        int indexOfSc;
        int indexOfM;

        for(int i=0;i<countOfSpacecrafts;i++)
        {
            if(spacecrafts[i].getName()==scname)
            {
              isscExist=true;
                indexOfSc=i;
                break;
            }

        }
    if(!isscExist)
    {
        cout<<"Cannot assign spacecraft. Spacecraft "<<scname<<" does not exist."<<endl;
    }
    else
    {
        for (int i=0;i<countOfMissions;i++)
        {
            if((missions[i].getName()==mname))
            {
                indexOfM=i;
                isMAssignable=true;
                break;
            }
        }
    }
        if(!isMAssignable && isscExist)
        {
            cout<<"Cannot assign spacecraft. Mission "<<mname<<" does not exist."<<endl;

        }
        if(isMAssignable)
        {
            if(spacecrafts[indexOfSc].getAvailability()=="Assigned")
            {
                isMAssignable=false;
                cout << "Cannot assign spacecraft. Spacecraft " << scname << " is already assigned to mission " << spacecrafts[indexOfSc].getMission()->getName() << "."<<endl;
            }
        }
        if(isMAssignable)
        {
            missions[indexOfM].addAssignedSc(spacecrafts[indexOfSc]);
            spacecrafts[indexOfSc].setAvailability("Assigned");
            spacecrafts[indexOfSc].setMission(&missions[indexOfM]);

            cout << "Assigned spacecraft " << scname << " to mission " << mname << "."<<endl;
        }

    }

    void SpaceMissionManagementSystem:: dropSpacecraftFromMission( const  string spacecraftName )
{
    int indexOfDroppedSpacecraft=-1;
    bool isDroppable=false;

    for(int i=0;i<countOfSpacecrafts;i++)
    {
        if(spacecrafts[i].getName()==spacecraftName)
        {
            indexOfDroppedSpacecraft=i;
            break;
        }
    }
    if(indexOfDroppedSpacecraft==-1)
    {
        cout<<"Cannot drop spacecraft. Spacecraft "<<spacecraftName<<" does not exist."<<endl;
    }
    else
    {
        if(spacecrafts[indexOfDroppedSpacecraft].getAvailability()=="Assigned")
        {
            isDroppable=true;
        }
        else
        {
            cout<<"Cannot drop spacecraft. Spacecraft "<<spacecraftName<<" is not assigned to any mission."<<endl;
        }
    }
    if(isDroppable)
    {
        if(spacecrafts[indexOfDroppedSpacecraft].getMission()->getScCount()>1)
        {
            spacecrafts[indexOfDroppedSpacecraft].setAvailability("Available");
            spacecrafts[indexOfDroppedSpacecraft].getMission()->removeAssignedSc(spacecrafts[indexOfDroppedSpacecraft]);

        }
        else
        {
            spacecrafts[indexOfDroppedSpacecraft].setAvailability("Available");
            delete[] spacecrafts[indexOfDroppedSpacecraft].getMission()->getAssignedSc();
            spacecrafts[indexOfDroppedSpacecraft].getMission()->dropAssignedSc();

        }

        cout<<"Dropped spacecraft "<<spacecraftName<<" from mission "<<spacecrafts[indexOfDroppedSpacecraft].getMission()->getName()<<"."<<endl;
        spacecrafts[indexOfDroppedSpacecraft].dropMission();

    }

}

    void SpaceMissionManagementSystem::showAllMissions() const
    {
        cout<<"Missions in the space mission management system:"<<endl;
    if(missions==nullptr)
    {
        cout<<"None"<<endl;
        return;
    }

        for(int i=0;i<countOfMissions;i++)
        {
            cout<<"Mission: " << missions[i].getName()<<", Launch Date: "<<missions[i].getDate()<<", Destination: "<<missions[i].getDestination()<<", Assigned Spacecraft Count: "<<missions[i].getScCount()<<endl;
        }
    }

    void SpaceMissionManagementSystem::showAllSpacecrafts() const
    {
        cout<<"Spacecrafts in the space mission management system:"<<endl;
    if(spacecrafts==nullptr)
    {
        cout<<"None"<<endl;
        return;
    }

        for(int i=0;i<countOfSpacecrafts;i++)
        {
            cout<<"Spacecraft: " << spacecrafts[i].getName()<<", Type: "<<spacecrafts[i].getType()<<", Status: "<<spacecrafts[i].getAvailability()<<endl;
        }

    }

void SpaceMissionManagementSystem::showMission(const string name) const
{
    int indexOfMission;
    bool isExist=false;
    for(int i=0;i<countOfMissions;i++)
    {
        if(missions[i].getName()==name)
        {
            isExist=true;
            indexOfMission=i;
            break;
        }
    }

    if(!isExist)
    {
        cout<<"Cannot show mission. Mission "<<name<<" does not exist."<<endl;
    }
    else
        {
    cout<<"Mission:"<<endl;
    cout<<"  Name: "<<missions[indexOfMission].getName()<<endl;
    cout<<"  Launch Date: "<<missions[indexOfMission].getDate()<<endl;
    cout<<"  Destination: "<<missions[indexOfMission].getDestination()<<endl;
    cout<<"  Assigned Spacecrafts:"<<endl;

    if(missions[indexOfMission].getAssignedSc()==nullptr)
    {
        cout<<"    None"<<endl;
    }
    else
    {
        for (int i=0;i<missions[indexOfMission].getScCount();i++)
        {
            cout<<"  - "<<missions[indexOfMission].getAssignedSc()[i].getName()<<endl;
        }
    }
        }
}

void SpaceMissionManagementSystem::showSpacecraft(const string name) const
{
    int indexOfsc;
    bool isExist=false;
    for(int i=0;i<countOfSpacecrafts;i++)
    {
        if(spacecrafts[i].getName()==name)
        {
            isExist=true;
            indexOfsc=i;
            break;
        }
    }

    if(!isExist)
    {
        cout<<"Cannot show spacecraft. Spacecraft "<<name<<" does not exist."<<endl;
    }
    else
    {
        cout<<"Spacecraft: "<<spacecrafts[indexOfsc].getName()<<", Type: "<<spacecrafts[indexOfsc].getType()<<", Status: "<<spacecrafts[indexOfsc].getAvailability()<<endl;
    }

}
