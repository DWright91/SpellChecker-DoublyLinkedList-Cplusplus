// Dalton Wright
// CSCI 301 01
// Project #4
// Node.h - Specification file.
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
   ItemType        nodeItem;      // A data item
   Node<ItemType>* previous;  // Pointer to previous node.
   Node<ItemType>* next;      // Pointer to next node

public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(Node<ItemType>* nextNodePtr);
   void setPrev(Node<ItemType>* prevNodePtr);
   ItemType getItem() const;
   Node<ItemType>* getNext() const;
   Node<ItemType>* getPrev() const;
}; // end Node

#include "Node.cpp"
#endif
