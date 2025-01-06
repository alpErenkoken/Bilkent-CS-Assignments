//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//
#ifndef PANDEMICSIMULATOR_H
#define PANDEMICSIMULATOR_H
#include <string>

#include "Queue.h"


class PandemicSimulator {

private:

    int * cityMap;
    int row;
    int column;

    Queue<int> queue;

    LinkedList<int> infected;


public:

    PandemicSimulator(const string cityGridFile);
    ~PandemicSimulator();

    void displayCityState(const int time);
    void simulateBlock(const int row, const int col);
    void simulatePandemic();

    void update(int** copyCityMap, int time);
    bool isPosExistInf(int pos, LinkedList<int>& inf);
    bool isOneExistCityMap(int** cityMap);
    bool isEqual(int** prev, int** curr);

};



#endif //PANDEMICSIMULATOR_H
