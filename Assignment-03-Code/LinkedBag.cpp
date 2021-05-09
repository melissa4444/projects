#include <iostream>
#include "Node.h"
#include "LinkedBag.h"



using namespace std;


//1. removeSecondNode340 deletes the second node in the Linked Bag. 2 pts
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340(){
    bool done = false;
    
    // Create a pointer to the 2nd node
    Node<ItemType>* secondNodePtr = headPtr->getNext();
    
    bool canRemoveItem = !isEmpty() && (secondNodePtr != nullptr);
    if (canRemoveItem) {
        // Set 2nd node's item to first node
        secondNodePtr->setItem(headPtr->getItem());
        Node<ItemType>* nodeToDeletePtr = headPtr;
        
        headPtr = headPtr->getNext(); // Increment headPtr
        nodeToDeletePtr->setNext(nullptr); // De-link first node
        
        // Delete old first node
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        
        
        itemCount--; // Decrement item count
        done = true;
    }
    return done;
}

//2. addEnd340 inserts the new node at the end of the Linked Bag. 2 pts
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry){
    Node<ItemType>* currNodePtr = headPtr;
    
    // Navigate to end of list
    while (currNodePtr->getNext() != nullptr) {
        currNodePtr = currNodePtr->getNext();
    }
    
    // Build a new node and link it to end of bag
    Node<ItemType>* newEntryPtr = new Node<ItemType>();
    newEntryPtr->setItem(newEntry);
    currNodePtr->setNext(newEntryPtr);
    itemCount++;
    
    return true;
}

//3. getCurrentSize340Iterative counts the number of nodes in the Linked Bag iteratively. 2 pts
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int size;
    Node<ItemType>* currNodePtr = headPtr;
    (currNodePtr == nullptr) ? size = 0 : size = 1; // In the strange event that headPtr is null...
    
    while(currNodePtr->getNext() != nullptr) {
        size++;
        currNodePtr = currNodePtr->getNext();
    }
    
    return size;
}

//4. getCurrentSize340Recursive counts the number of nodes in the Linked Bag recursively. Use 1 helper function: getCurrentSize340RecursiveHelper. 2 pts
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    return getCurrentSize340RecursiveHelper(headPtr);
}

//5. IMMEDIATE RECURSION: getCurrentSize340RecursiveNoHelper counts the number of nodes in the Linked Bag recursively. This recursive function does not use any helper functions. 4 pts
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    static int size = 1;
    static Node<ItemType>* currNodePtr = headPtr;
    
    if (currNodePtr->getNext() != nullptr) {
        size++;
        currNodePtr = currNodePtr->getNext();
        getCurrentSize340RecursiveNoHelper();
    }
    
    return size;
}

//6. getFrequencyOf340Recursive recursively counts the number of times an entry appears in the Linked Bag. Use 1 helper function: getFrequencyOf340RecursiveHelper. 2 pts
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {
    int freq = 0;
    Node<ItemType>* currNodePtr = headPtr;
    for (int i=0; i<itemCount; i++) {
        freq += getFrequencyOf340RecursiveHelper(currNodePtr, anEntry);
        currNodePtr = currNodePtr->getNext();
    }
    
    return freq;
}

//7. IMMEDIATE RECURSION: getFrequencyOf340RecursiveNoHelper recursively counts the number of times an
//entry appears in the Linked Bag. This recursive function does not use any helper functions. 4 pts
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const {
    static Node<ItemType>* currNodePtr = headPtr;
    
    if (currNodePtr == nullptr) {
        currNodePtr = headPtr;
        return 0;
    } else if (currNodePtr->getItem() == anEntry) {
        currNodePtr = currNodePtr->getNext();
        return 1 + getFrequencyOf340RecursiveNoHelper(anEntry);
    }
    
    currNodePtr = currNodePtr->getNext();
    return getFrequencyOf340RecursiveNoHelper(anEntry);
}

//8. removeRandom340 removes a random entry from the Linked Bag. 2 pts
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340(){
    ItemType removed;
    Node<ItemType>* currNodePtr = headPtr;
    
    // Generate a random number between 0 and (max index)
    int rng = rand() % (itemCount - 1);
    
    // Increment a pointer the the index
    for (int i=0; i==rng; i++) {
        currNodePtr = currNodePtr->getNext();
    }
    
    removed = currNodePtr->getItem();
    
    currNodePtr->setItem(headPtr->getItem());
    Node<ItemType>* nodeToDeletePtr = headPtr;
    headPtr = headPtr->getNext();
    
    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;
    itemCount--;
    
    return removed;
}


//Private:
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* currNode) const{
    static int size = 0;
    if (currNode != nullptr) {
        size++;
        getCurrentSize340RecursiveHelper(currNode->getNext());
    }
    
    return size;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* currNodePtr, const ItemType& anEntry) const {
    if (currNodePtr) {
        if (currNodePtr->getItem() == anEntry) {
            return 1;
        }
    }
    
    return 0;
}