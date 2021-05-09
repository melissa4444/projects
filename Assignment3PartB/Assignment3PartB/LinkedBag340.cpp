//	LinkedBag340.cpp
//	Created by: CSC340

/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===
*/
#include"LinkedBag.h"
#include<iostream>
#include<string>
#include<vector>//for the vector in ramdom remove
#include<stdlib.h>//srand, rand
#include<time.h>//time


template<typename ItemType>
bool LinkedBag;<ItemType>::removeSecondNode340()
{
    Node<ItemType>* pointerToDelete = headPtr;
    headPtr= headPtr -> getNext();
    if(headPtr!=nullptr)
    {
        headPtr->setItem (pointerTodelete-> getItem());
        pointerTodelete -> setNext(nullptr);
        delete pointerTodelte;
        pointerTodelete = nullptr;
    }
    return true;
    
}
//linked nodes sequence of nodes in which in turn has a link field pointing to
//the third node, and so on each node contains some data, a pointer outside the squence
// which points to the first node of the sequence and the link in the last node of the
//sequence must have the value nullptr so that any routing traversing the sequence will be
// able to tell when it has arrived to the end
//add the node to the end of the list

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& item)
{
    Node<ItemType>* lastNode = headPtr;
    while (lastNode->getNext() != nullptr)
    {
        lastNode= lastNode->getNext();
    }
    Node<ItemType>* nextNode = new Node<ItemType>();
    nextNode->setItem(item);
    lastNode->setNext(nextNode);
    itemCount++;
    return true;
}
// getCurrentSize() - Iterative
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const
{
    int bagsize = 0;
    Node<ItemType>* current = headPtr;
    while ((current != nullptr)&&(bagsize<itemCount))
    {
        bagsize++;
        current = current->getNext();
    }
    return bagsize;
}

// getCurrentSize() - Recursive
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const
{
    Node<ItemType>* current = headPtr;
    return getCurrentSize340RecursiveHelper(current);
}

// getCurrentSize() - Recursive

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const
{
    /*its impossible to traverse to each node recursively without any parameter passing.
     that why i just called the other function, not usre if I am allowed*/
    return getCurrentSize340Recursive();
}

// getFrequencyOf340Recursive() - Recursive
template<typename ItemType>
int LinkedBag<ItemType> :: getFrequencyOf340Recursive(const ItemType& itemName) const
{
    Node<ItemType>* current = headPtr;
    return getFrequencyOf340RecursiveHelper(current,itemName);
}

// getFrequencyOf340Recursive() - Recursive
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& itemName) const
{
    //I gain it is hard to do recursion without passing the next node in parameters.
    //I tried using static but that did not work. and most of samples online youtube, they pass node on the parameters.
    return getFrequencyOf340Recursive(itemName);
}

// Remove a random node
template<typename ItemType>
ItemType LinkedBag<ItemType> :: removeRandom340()
{
    /*doing this is time and memory in efficient, but it is easier to see whats going on
     doing this is more secure to remove items that are actually in the bag.*/
    std::vector<ItemType> temp = this->toVector();//using std because vactor is part of it
    
    srand(time(NULL));//initialized random seed
    //generating random number from 0 to the size of the vector.
    int random_number = rand() % temp.size();
    
    ItemType var = temp[random_number];//we can just use the righside in the revome
    //temp.erase(random_number);//erases randomnumber from the vector.
    remove(var);
    return var ;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* node)const
{
    Node<ItemType>* current = node;
    if (current->getNext() == nullptr) { return 1; }//check to see if the next node is a node. to not over count. ;D
    else
    {
        return 1 + getCurrentSize340RecursiveHelper(current->getNext());//+1 to increase by one for each node.
    }
}
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* node, const ItemType& itemInbag) const
{
    Node<ItemType>* current = node;
    if (current == nullptr) { return 0; }
    else if(current->getItem() == itemInbag)
    {
        return 1 + getFrequencyOf340RecursiveHelper(current->getNext(), itemInbag);
    }
    else
    {
        return getFrequencyOf340RecursiveHelper(current->getNext(), itemInbag);
    }
    return 0;
}//very needed
