// Dalton Wright
// CSCI 301 01
// Project #4
// DLinkedBag.cpp - Implementation file.

#include <iostream>
#include <cstddef>
#include "DLinkedBag.h"
#include "Node.h"

template<class ItemType>
DLinkedBag<ItemType>::DLinkedBag() : itemCount(0), headPtr(NULL)
{
};

template<class ItemType>
DLinkedBag<ItemType>::DLinkedBag(const DLinkedBag<ItemType>& aBag) : itemCount(aBag.getCurrentSize)
{
  Node<ItemType>* origPtr = aBag.headPtr;

  if(origPtr == NULL)
  {
    headPtr = NULL;
  }
  else
  {
    headPtr = new Node<ItemType>();
    headPtr->setItem(origPtr->getItem());
    headPtr->setPrev(NULL);

    Node<ItemType>* newPtr = headPtr;
    origPtr = origPtr->getNext();

    while(origPtr != NULL)
    {
      ItemType nextItem = origPtr->getItem();

      Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

      newNodePtr->setPrev(newPtr);
      newPtr->setnext(newNodePtr);

      newPtr = newPtr->getNext();

      origPtr = origPtr->getNext();
    }

    newPtr->setNext(NULL);
  }
}

template<class ItemType>
bool DLinkedBag<ItemType>::isEmpty() const
{
  if(itemCount == 0)
  {
    return true;
  }
  else if(itemCount > 0)
  {
    return false;
  }
  else
  {
    std::cout << "Error! The item count is negative!" << std::endl;
    return false;
  }

};

template<class ItemType>
int DLinkedBag<ItemType>::getCurrentSize() const
{
  return itemCount;
};

template<class ItemType>
bool DLinkedBag<ItemType>::add(const ItemType& item)
{
  Node<ItemType>* newNode;
  newNode = new Node<ItemType>(item);

  if(itemCount == 0)
  {
    headPtr = newNode;
  }
  else
  {
    headPtr->setPrev(newNode);
    newNode->setNext(headPtr);
    headPtr = newNode;
  }
  itemCount++;
  return true;
};

template<class ItemType>
bool DLinkedBag<ItemType>::contains(const ItemType& item)
{
  Node<ItemType>* curPtr = headPtr;
  ItemType bagItem;

  for(int i = 0; i < itemCount; i++)
  {
    bagItem = curPtr->getItem();

    if (bagItem == item)
    {
      return true;
    }

    curPtr = curPtr->getNext();
  }

  return false;
};

template<class ItemType>
bool DLinkedBag<ItemType>::remove(const ItemType& item)
{
  bool isRemovable = contains(item);
  if(isRemovable)
  {
    Node<ItemType>* curPtr = headPtr;
    ItemType bagItem;

    if(curPtr->getItem() == item)
    {
      headPtr = headPtr->getNext();
      headPtr->setPrev(NULL);
    }

    else
    {
      while(curPtr->getNext() != NULL)
      {
        bagItem = curPtr->getItem();

        if(bagItem == item)
        {
          Node<ItemType>* prevNode = curPtr->getPrev();
          Node<ItemType>* nextNode = curPtr->getNext();

          prevNode->setNext(nextNode);
          nextNode->setPrev(prevNode);

          break;
        }

        curPtr = curPtr->getNext();
      }
    }

    curPtr->setNext(NULL);
    curPtr->setPrev(NULL);
    delete curPtr;
    curPtr = NULL;
    itemCount--;

    return true;
  }

  return false;
};

template<class ItemType>
void DLinkedBag<ItemType>::clear()
{
  while(itemCount != 0)
  {
    Node<ItemType>* curPtr = headPtr;
    headPtr = headPtr->getNext();
    curPtr->setNext(NULL);
    curPtr->setPrev(NULL);
    delete curPtr;
    curPtr = NULL;
    itemCount--;
  }
};

template<class ItemType>
int DLinkedBag<ItemType>::getFrequencyOf(const ItemType& item)
{
  int frequency = 0;
  Node<ItemType>* curPtr = headPtr;
  ItemType someItem;

  for(int i = 0; i < itemCount; i++)
  {
    someItem = curPtr->getItem();
    if(someItem == item)
    {
      frequency++;
    }

    curPtr = curPtr->getNext();
  }

  return frequency;
}


template<class ItemType>
std::vector<ItemType> DLinkedBag<ItemType>::toVector() const
{
  Node<ItemType>* curPtr = headPtr;
  std::vector<ItemType> bagContents;

  for(int i = 0; i < itemCount; i++)
  {
    bagContents.push_back(curPtr->getItem());
    curPtr = curPtr->getNext();
  }

  return bagContents;
}  // end toVector
