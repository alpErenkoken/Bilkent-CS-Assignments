//
// Alp Eren Köken Section:3 22202876
//


#include "Mission.h"

Mission::Mission(const string& name, const string& date, const string& destination)
    : name(name), date(date), destination(destination), assignedSc(nullptr), scCount(0) {}

Mission::Mission()
{
    scCount=0;
    assignedSc=nullptr;
    name="";
    date="";
    destination="";

}

Mission::~Mission()
{
    delete[] assignedSc;
}

Mission::Mission( const Mission& other )
{
    this->name = other.name;
    this->date = other.date;
    this->destination = other.destination;
    this->scCount = other.scCount;

    if ( scCount > 0 )
    {
        assignedSc= new Spacecraft[ scCount ];
        for ( int i = 0; i < scCount; i++ )
            assignedSc[ i ] = other.assignedSc[ i ];
    }
    else
        assignedSc= nullptr;
}

Mission &Mission::operator=(const Mission& right)
{
    if(this==&right)
    {
        return *this;
    }
    delete []assignedSc;

    name=right.name;
    date=right.date;
    destination=right.destination;
    scCount=right.scCount;

    assignedSc=new Spacecraft[scCount];

    for(int i=0;i<scCount;i++)
    {
        assignedSc[i]=right.assignedSc[i];
    }
    return *this;
}



string Mission::getName()
{
    return name;
}
string Mission::getDate()
{
    return date;
}
string Mission::getDestination()
{
    return destination;
}
Spacecraft* Mission::getAssignedSc()
{
    return assignedSc;
}
int Mission::getScCount()
{
    return scCount;
}
void Mission::addAssignedSc(Spacecraft& sc)
{
    Spacecraft* newAssignedSc=new Spacecraft[scCount+1];
    for(int i=0;i<scCount;i++)
    {
        newAssignedSc[i]=assignedSc[i];
    }
    newAssignedSc[scCount]=sc;

    delete []assignedSc;
    assignedSc=newAssignedSc;
    scCount++;

}

void Mission::setScCount(int x)
{
    scCount=scCount+x;
}
void Mission::removeAssignedSc(Spacecraft& removeSc)
{
    int index;
    for(int i=0; i<scCount; i++)
    {
        if(assignedSc[i].getName()==removeSc.getName())
        {
            index=i;
        }
    }

    Spacecraft* new_AssignedSc=new Spacecraft[scCount-1];
    for(int i=index;i<scCount-1;i++)
    {
        assignedSc[i]=assignedSc[i+1];
    }
    for(int i=0;i<scCount-1;i++)
    {
        new_AssignedSc[i]=assignedSc[i];
    }
    delete []assignedSc;
    assignedSc=new_AssignedSc;
    scCount--;
}
void Mission::dropAssignedSc()
{
    assignedSc=nullptr;
    scCount=0;
}