//
//Name:Alp Eren Köken
//Section:3
//Student No:22202876
//
#ifndef NODE_H
#define NODE_H

template <class ItemType>
class Node
{
private:
    ItemType item;
    Node<ItemType>* next;

public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    Node(const Node<ItemType>& other);
    Node<ItemType>& operator=(const Node<ItemType>& other);

    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);

    ItemType getItem() const;
    Node<ItemType>* getNext() const;
};

template <class ItemType>
Node<ItemType>::Node() : next(nullptr){}

template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem) :  item(anItem), next(nullptr){}

template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr)
    : item(anItem), next(nextNodePtr){}

template <class ItemType>
Node<ItemType>::Node(const Node<ItemType>& other)
    : item(other.item), next(other.next) {}

template <class ItemType>
Node<ItemType>& Node<ItemType>::operator=(const Node<ItemType>& other)
{
    if (this != &other)
    {
        item = other.item;
        next = other.next;
    }
    return *this;
}

template <class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
}

template <class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
}

template <class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
    return next;
}

#endif //NODE_H
