// Dalton Wright
// CSCI 301 01
// Project #4
// TestADTBag.cpp
// This program tests the ADT Bag class which is implemented by a doubly linked list.

#include <iostream>
#include <string>
#include "DLinkedBag.h"

using namespace std;

void displayBag(DLinkedBag<string>& bag)
{
	 cout << "The bag contains " << bag.getCurrentSize()
        << " items:" << endl;
   vector<string> bagItems = bag.toVector();

   int numberOfEntries = (int) bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   }  // end for
	 cout << endl << endl;
}  // end displayBag



void bagTester(DLinkedBag<string>& bag)
{
   cout << "isEmpty: returns " << bag.isEmpty()
   			<< "; should be 1 (true)" << endl;
   displayBag(bag);

	 string items[] = {"one", "two", "three", "four", "five", "one"};
   cout << "Add 6 items to the bag: " << endl;
	 for (int i = 0; i < 6; i++)
   {
		bag.add(items[i]);
   }  // end for

   displayBag(bag);

   cout << "isEmpty: returns " << bag.isEmpty()
   			<< "; should be 0 (false)" << endl;

   cout << "getCurrentSize: returns " << bag.getCurrentSize()
   			<< "; should be 6" << endl;

   cout << "Try to add another entry: add(\"extra\") returns "
   			<< bag.add("extra") << endl;

   cout << "contains(\"three\"): returns " << bag.contains("three")
   			<< "; should be 1 (true)" << endl;
   cout << "contains(\"ten\"): returns " << bag.contains("ten")
   			<< "; should be 0 (false)" << endl;
   cout << "getFrequencyOf(\"one\"): returns "
   			<< bag.getFrequencyOf("one") << " should be 2" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
   			<< "; should be 1 (true)" << endl;
   cout << "getFrequencyOf(\"one\"): returns "
   			<< bag.getFrequencyOf("one") << " should be 1" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
   			<< "; should be 1 (true)" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
   			<< "; should be 0 (false)" << endl;
   cout << endl;

   displayBag(bag);

   cout << "After clearing the bag, ";
   bag.clear();

   cout << "isEmpty: returns " << bag.isEmpty()
   			<< "; should be 1 (true)" << endl;
}  // end bagTester

int main()
{
	DLinkedBag<string> bag;
	cout << "Testing the Link-Based Bag:" << endl;
	cout << "The initial bag is empty." << endl;
  bagTester(bag);
	cout << "All done!" << endl;
	
  return 0;
}  // end main
