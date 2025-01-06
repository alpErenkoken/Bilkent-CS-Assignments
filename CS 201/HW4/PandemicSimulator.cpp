//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#include "PandemicSimulator.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

PandemicSimulator::PandemicSimulator(const string cityGridFile)
{

    ifstream file;
    file.open(cityGridFile);

    if(!file.is_open())
    {
        std::cout << "File could not be opened." << std::endl;
        exit(1);
    }

    file >> row;
    file >> column;
    cityMap = new int[row*column];


    for(int i = 0; i < row; i++)
    {
        string line;
        file >> line;

        for(int k = column-1; k >= 0; k--)
        {
            cityMap[column*i+k] = line[k] - '0';
        }
    }

    file.close();
}

PandemicSimulator::~PandemicSimulator()
{
    delete [] cityMap;
}

bool PandemicSimulator::isPosExistInf(int pos,LinkedList<int>& inf)
{

    for(int i=1;i<inf.getLength()+1;i++)
    {
        if(inf.getEntry(i)==pos)
        {
            return true;
        }
    }
    return false;
}

bool PandemicSimulator::isOneExistCityMap(int** cityMap)
{

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if((*cityMap)[i*column+j] == 1)
            {
                return true;
            }
        }
    }

    return false;
}

void PandemicSimulator::update(int** copyCityMap,const int time)
{
    for(int x=0;x<time;x++)
    {

    LinkedList<int> copyInfected=infected;
    int t=0;
    int size2=0;

    //for(int t=0;t<time;t++)
    //{

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if((*copyCityMap)[i*column+j] == 2)
                {
                    queue.enqueue(i*column+j);
                    size2++;
                }
            }
        }

        while (!queue.isEmpty())
        {
            int pos=queue.peekFront();
            int reducedPos=pos;
            int quantity=0;

            if(!isPosExistInf(pos,copyInfected))
            {
                copyInfected.insert(copyInfected.getLength()+1,pos);
            }

            queue.dequeue();

            if(t<size2)
            {

                while(reducedPos>=column)
                {
                    reducedPos-=column;
                    quantity++;
                }

                if((0<=pos-column))
                {
                    if(((*copyCityMap)[pos-column]==1))
                    {
                        queue.enqueue(pos-column);
                        //copyInfected.insert(copyInfected.getLength()+1,pos-column);
                    }
                }

                if((pos+column<=row*column-1))
                {
                    if(((*copyCityMap)[pos+column]==1))
                    {
                        queue.enqueue(pos+column);
                        //copyInfected.insert(copyInfected.getLength()+1,pos+column);
                    }
                }

                if((quantity*column<=pos-1))
                {
                    if(((*copyCityMap)[pos-1]==1))
                    {
                        queue.enqueue(pos-1);
                        //copyInfected.insert(copyInfected.getLength()+1,pos-1);
                    }
                }

                if(pos+1<(quantity+1)*column)
                {
                    if(((*copyCityMap)[pos+1]==1))
                    {
                        queue.enqueue(pos+1);
                        //copyInfected.insert(copyInfected.getLength()+1,pos+1);
                    }
                }

                 t++;
            }
        }

        for(int i=1; i<copyInfected.getLength()+1;i++)
        {
            (*copyCityMap)[copyInfected.getEntry(i)]=2;
        }

    }

}

void PandemicSimulator::displayCityState(const int time)
{

    cout<<"City state at day "<<time<<":"<<endl;

    if(time==0)
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                cout << cityMap[i*column+j];
            }
            cout << endl;
        }
    }
    else
    {

        int* copyCityMap=new int[row*column];

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                copyCityMap[i*column+j] = cityMap[i*column+j];
            }
        }

        update(&copyCityMap,time);

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                cout << copyCityMap[i*column+j];
            }
            cout << endl;
        }

        delete [] copyCityMap;

    }

}

void PandemicSimulator::simulateBlock(const int r, const int c)
{
    if(cityMap[r*column+c]==2)
    {
        cout<<"Time for block ("<<r<<", "<<c<<") to be infected: 0 days."<<endl;
    }
    if(cityMap[r*column+c]==0)
    {
        cout<<"Time for block ("<<r<<", "<<c<<") to be infected: -1 days."<<endl;
    }
    if(cityMap[r*column+c]==1)
    {

        int *copyCityMap=new int[row*column];
        int* prevCopyCityMap=new int[row*column];

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                prevCopyCityMap[i*column+j] =3;
            }
        }

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                copyCityMap[i*column+j] = cityMap[i*column+j];
            }
        }

        int reqTime=0;

        while(copyCityMap[r*column+c]!=2)
        {

            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < column; j++)
                {
                    prevCopyCityMap[i*column+j] = copyCityMap[i*column+j];
                }
            }

            reqTime++;
            update(&copyCityMap,1);

            if(isEqual(&prevCopyCityMap,&copyCityMap))
            {
                cout<<"Time for block ("<<r<<", "<<c<<") to be infected: -1 days."<<endl;

                delete [] prevCopyCityMap;
                delete [] copyCityMap;

                return;
            }

        }

        cout<<"Time for block ("<<r<<", "<<c<<") to be infected: "<<reqTime<<" days."<<endl;

        delete [] prevCopyCityMap;
        delete [] copyCityMap;

    }

}

void PandemicSimulator::simulatePandemic()
{
    bool controller=true;

    int reqTime = 0;


    int* copyCityMap=new int[row*column];
    int* prevCopyCityMap=new int[row*column];

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            prevCopyCityMap[i*column+j] =3;
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            copyCityMap[i*column+j] = cityMap[i*column+j];
        }
    }

    while(controller)
    {
        bool isSpreaded=true;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(copyCityMap[i*column+j]==1)
                {

                    if(isEqual(&prevCopyCityMap,&copyCityMap))
                    {
                        cout<<"Pandemic cannot spread to all blocks."<<endl;

                        delete [] prevCopyCityMap;
                        delete [] copyCityMap;

                        return;
                    }

                    isSpreaded=false;
                    break;
                }
            }
            if(!isSpreaded)
            {
                break;
            }
        }

        if(isSpreaded)
        {
            controller=false;
        }

        if(controller)
        {

            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < column; j++)
                {
                    prevCopyCityMap[i*column+j] = copyCityMap[i*column+j];
                }
            }

            reqTime++;
            update(&copyCityMap,1);
        }

    }

    cout<<"Minimum time for pandemic to spread to all blocks: "<<reqTime<<" days."<<endl;

    delete [] prevCopyCityMap;
    delete [] copyCityMap;

}

bool PandemicSimulator::isEqual(int** prev,int** curr)
{

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if((*prev)[i*column+j]!=(*curr)[i*column+j])
            {
                return false;
            }
        }
    }

    return true;
}





