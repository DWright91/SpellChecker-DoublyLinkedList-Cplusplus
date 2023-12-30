// Dalton Wright
// CSCI 301 01
// Project #4
// DLinkedBag.h - Specification file.

#ifndef _D_LINKED_BAG
#define _D_LINKED_BAG

#include <vector>
#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class DLinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items

public:
   DLinkedBag();
   DLinkedBag(const DLinkedBag<ItemType>& aBag); // Copy constructor
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry);
   int getFrequencyOf(const ItemType& anEntry);
   std::vector<ItemType> toVector() const;
}; // end DLinkedBag

#include "DLinkedBag.cpp"
#endif
