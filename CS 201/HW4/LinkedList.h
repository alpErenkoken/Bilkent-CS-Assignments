//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

template <class ItemType>
class LinkedList {
private:
    int itemCount;
    Node<ItemType>* head;

public:
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);
    LinkedList<ItemType>& operator=(const LinkedList<ItemType>& aList);
    ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();

    Node<ItemType>* getNodeAt(int position) const;
    ItemType getEntry(int position) const;
    bool replace(int position, const ItemType& newEntry);
};

template <class ItemType>
LinkedList<ItemType>::LinkedList()
{
    itemCount = 0;
    head = nullptr;
}

template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}

template <class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
    itemCount = aList.itemCount;
    Node<ItemType>* origChainPtr= aList.head;
    if (origChainPtr == nullptr)
    {
        head = nullptr;
    }
    else
    {
        head=new Node<ItemType>();
        head->setItem(origChainPtr->getItem());

        Node<ItemType>* tempChainPtr = head;
        origChainPtr = origChainPtr->getNext();
        while (origChainPtr != nullptr)
        {
            Node<ItemType>* tempNode = new Node<ItemType>(origChainPtr->getItem());
            tempChainPtr->setNext(tempNode);

            tempChainPtr = tempChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
        tempChainPtr->setNext(nullptr);
    }

}

template <class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList<ItemType>& aList)
{
    if (this != &aList)
    {
        clear();
        itemCount = aList.itemCount;

        if (aList.head == nullptr)
        {
            head = nullptr;
        }
        else
        {
            head = new Node<ItemType>();
            head->setItem(aList.head->getItem());
            Node<ItemType>* newChainPtr = head;
            Node<ItemType>* origChainPtr = aList.head->getNext();

            while (origChainPtr != nullptr)
            {
                Node<ItemType>* newNode = new Node<ItemType>(origChainPtr->getItem());
                newChainPtr->setNext(newNode);
                newChainPtr = newChainPtr->getNext();
                origChainPtr = origChainPtr->getNext();
            }
            newChainPtr->setNext(nullptr);
        }
    }
    return *this;
}


template <class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
    bool abletoGet=(position >= 1) && (position <= itemCount);
    if (abletoGet)
    {
        Node<ItemType>* nodePtr=getNodeAt(position);
        return nodePtr->getItem();
    }
    return ItemType();
}

template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    bool isAble=((position>=1) && (position<=itemCount));

    if(isAble)
    {
        Node<ItemType>* curPtr= head;
        for(int skip=1;skip<position;skip++)
        {
            curPtr=curPtr->getNext();
        }
        return curPtr;
    }

    return nullptr;
}

template <class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool abletoInsert=((newPosition >= 1) && (newPosition <= itemCount+1));
    if (abletoInsert)
    {
        Node<ItemType>* newNodePtr=new Node<ItemType>(newEntry);

        if(newPosition==1)
        {
            newNodePtr->setNext(head);
            head=newNodePtr;
        }
        else
        {
            Node<ItemType>* prevPtr=getNodeAt(newPosition-1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }
        itemCount++;
    }
    return abletoInsert;
}

template <class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool abletoDelete=((position>=1) && (position<=itemCount));

    if (abletoDelete)
    {
        Node<ItemType>* curPtr=nullptr;

        if(position==1)
        {
            curPtr=head;
            head=head->getNext();
        }
        else
        {
            Node<ItemType>* prevPtr=getNodeAt(position-1);
            curPtr=prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
        }
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr=nullptr;
        itemCount--;
    }
    return abletoDelete;
}

template <class ItemType>
void LinkedList<ItemType>::clear()
{
    while(!isEmpty())
    {
        remove(1);
    }
}

template <class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template <class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}

template <class ItemType>
bool LinkedList<ItemType>::replace(int position, const ItemType& newEntry)
{
    if((position < 1) || (position > itemCount))
    {
        return false;
    }

        Node<ItemType>* curPtr=getNodeAt(position);
        if(curPtr==nullptr)
        {
            return false;
        }
        remove(position);
        insert(position,newEntry);
        return true;

    }


#endif




