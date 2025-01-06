//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <ostream>

#include "LinkedList.h"

using namespace std;

template<class ItemType>
class Queue
{
    private:
    LinkedList<ItemType>* listPtr;

    public:

    Queue();
    Queue(const Queue& aQueue);
    ~Queue();

    bool enqueue(const ItemType item);
    bool dequeue();
    bool isEmpty() const;

    ItemType peekFront() const;
};

template <class ItemType>
Queue<ItemType>::Queue()
{
    listPtr=new LinkedList<ItemType>();
}

template <class ItemType>
Queue<ItemType>::Queue(const Queue& aQueue)
{
    listPtr=new LinkedList<ItemType>(*aQueue.listPtr);
}

template <class ItemType>
Queue<ItemType>::~Queue()
{
    delete listPtr;
}

template <class ItemType>
bool Queue<ItemType>::isEmpty() const
{
    return listPtr->isEmpty();
}

template <class ItemType>
bool Queue<ItemType>::enqueue(const ItemType item)
{
    return listPtr->insert(listPtr->getLength()+1,item);
}

template <class ItemType>
bool Queue<ItemType>::dequeue()
{
    return listPtr->remove(1);
}

template <class ItemType>
ItemType Queue<ItemType>::peekFront() const
{
    if (listPtr->isEmpty())
    {
        cout << "Queue is empty." << endl;//------------------------------------------------------------------
    }
    else
    {
        return listPtr->getEntry(1);
    }
    return listPtr->getEntry(1);
}


#endif //QUEUE_H
