//	LinkedBag340.cpp
//	Created by: CSC340

/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===
*/
#include"LinkedBag.h"
#include<iostream>
#include"Node.h"


using namespace std;
// use either <typename T> or <class T>  to specify a type parameter.
// <type T> is preferred because it is descriptive <class T> looks like
//class definition
// A template may have more than one parameter: <typename T1, typename T2, typename T3>
//default type for type parameter: template<typename T=int>
//define static member in a template class. Each template specialization has its own copy of static data field.


/*template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
 if (canRemoveItem)
    {
        Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());
        Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr; headPtr = headPtr->getNext();
        Return node to the system
        nodeToDeletePtr->setNext(nullptr); delete nodeToDeletePtr; nodeToDeletePtr = nullptr;
        itemCount--;
        //end if end remove
    }
 return canRemoveItem;
 */

//remove the secondnode
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340()
{
    bool done = false;
    
    //point to the sencond node
    Node<ItemType>* secondNodePtr= headPtr->getNext();
    
    bool removeItem = !isEmpty() && (secondNodePtr != nullptr);
    if(removeItem)
    {
        secondNodePtr-> setItem(headPtr->getItem());
        Node<ItemType>* nodeDeletePtr = headPtr;
        headPtr=headPtr->getNext();
        nodeDeletePtr->setNext(nullptr);
        delete nodeDeletePtr;
        nodeDeletePtr = nullptr;
        itemCount--;
        done = true;
    }
    return done;
    
   /* After the method remove deletes a node, the system can use this returned memory and possibly even reallocate it to your program as a result of the new operator*/
}

/* must make a headPtr point to the new node, and the new node must point to the node
 that had been at the beginning of the chain
 def:
 template<class ItemType>
 bool LinkedBag<ItemType>::add(const ItemType& newEntry)
 {
        // Add to beginning of chain: new node references rest of chain;
        // (headPtr is nullptr if chain is empty)
        Node<ItemType>* newNodePtr = new Node<ItemType>();
        newNodePtr->setItem(newEntry);
        newNodePtr->setNext(headPtr); //
        New node points to chain headPtr = newNodePtr;
        // New node is now first node itemCount++;
        return true;
 
 } // end add
*/

//addEnd340 go to the end of the ist then build a new node and link it to the end of the bag

template <typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry)
{
    Node<ItemType>* currentPtr=headPtr;
    while(currentPtr->getNext() != nullptr){
        currentPtr=currentPtr->getNext();
    }
    Node<ItemType>* newPtr = new Node<ItemType>();
    newPtr->setItem(newEntry);
    currentPtr->setNext(newPtr);
    itemCount++;
    return true;


}
/*
 template<typename Itemtype>
 bool LinkedBag<ItemType>::getCurrentSize() const{
 return itemCount;
 }
 
 */

// getCurrentSize340Iterative counts the number of nodes in the Linked Bag iteraltively

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const{
    int size;
    Node<ItemType>* currentPtr= headPtr;
    (currentPtr==nullptr) ? size = 0 : size = 1;
    
    while(currentPtr->getNext() != nullptr){
        size++;
        currentPtr=currentPtr->getNext();
    }
    return size;
}

//getCurrentSize340Recursive counts the number of nodes in the Linked Bag recursively. Use helper function getCurrentSize340RecrusiveHelper

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const{
    return getCurrentSize340RecursiveHelper(headPtr);
}


//getCurrentSize340RecrusiveNoHelper count the numner of nodes in the bag recursively this recursive function does not use helper

template <typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const{
    static int size=1;
    static Node<ItemType>* currentPtr = headPtr;
    if(currentPtr->getNext() != nullptr){
        size++;
        currentPtr = currentPtr->getNext();
        getCurrentSize340RecursiveNoHelper();
    }
    return size;
}

//getFrequencyOf340Recursive recursively counts the number of times an entry appears in the linked bag helper function is getFrequencyOf340RecursiveHelper

/*
 template<typename ItemType>
 int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const{
 int frequecny=0;
 int counter=0;
 Node<ItemType>* curPtr=headPtr;
 while((curPtr != nullptr) && (counter<itemCount)){
 headPtr= headPtr->getNext();
 nodeToDeletePtr-> setNext(nullptr);
 delete nodeToDeletePtr;
 nodeToDeletePtr=headPtr;
 }
 itemCount=0;
 }
 */

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {
    int frequency=0;
    Node<ItemType>* currentPtr = headPtr;
    for(int i=0; i< itemCount; i++){
        frequency += getFrequencyOf340RecursiveHelper(currentPtr, anEntry);
        currentPtr=currentPtr->getNext();
    }
    return frequency;
}

//immediate recursion, getFrequencyOf340RecursiveNoHelper recursively counts the number of times an entry appears in the Linked Bag. This recursive function does not use any helper functions

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const{
    static Node<ItemType>* currentPtr=headPtr;
    if(currentPtr==nullptr){
        currentPtr=headPtr;
        return 0;
    }else if(currentPtr->getItem()==anEntry){
        currentPtr=currentPtr->getNext();
        return 1+getFrequencyOf340RecursiveNoHelper(anEntry);
    }
    currentPtr=currentPtr->getNext();
    return getFrequencyOf340RecursiveNoHelper(anEntry);
    
    
}

//removeRandom340 removes a random entry from linked bag

template <typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340(){
    ItemType removed;
    Node<ItemType>* currentPtr = headPtr;
    
    int rng = rand() % (itemCount-1);
    for(int i=0; i==rng; i++){
        currentPtr=currentPtr->getNext();
    }
    removed = currentPtr->getItem();
    currentPtr->setItem(headPtr->getItem());
    Node<ItemType>* nodeToDeletePtr = headPtr;
    headPtr=headPtr->getNext();
    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;
    itemCount--;
    return removed;
    
}
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* currentNode) const{
    static int size=0;
    if(currentNode != nullptr){
        size++;
        getCurrentSize340RecursiveHelper(currentNode->getNext());
    }
    return size;
}
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* currentPtr, const ItemType& anEntry) const{
    if(currentPtr){
        if(currentPtr->getItem()==anEntry){
            return 1;
        }
    }
    return 0;
    
}
