// Dalton Wright
// CSCI 301 01
// Project #4
// Node.cpp - Implementation file.
#include "Node.h"
#include <cstddef>

template<class ItemType>
Node<ItemType>::Node() : next(NULL), previous(NULL)
{
} //end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : nodeItem(anItem), next(NULL), previous(NULL)
{
} //end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
                nodeItem(anItem), next(nextNodePtr), previous(NULL)
{
} //end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr) :
                nodeItem(anItem), next(nextNodePtr), previous(prevNodePtr)
{
} // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
   nodeItem = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

template<class ItemType>
void Node<ItemType>::setPrev(Node<ItemType>* prevNodePtr)
{
    previous = prevNodePtr;
} // end setPrev

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
   return nodeItem;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
   return next;
} // end getNext

template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrev() const
{
    return previous;
}
