// Dalton Wright
// CSCI 301 01
// Project #4
// SpellChecker.cpp
// This program preforms spell-check by testing an input file with a dictionary file.

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "DLinkedBag.h"

using namespace std;

// Function Prototypes.
bool createDictionary(DLinkedBag<string>& dictionary, ifstream& file);
bool checkSpellingOfWord(string correctWord, string wordToCheck);
vector<string> spellChecker(DLinkedBag<string>& dictionary, ifstream& file);


// SpellChecker Driver.
int main()
{
  DLinkedBag<string> wordBag;
  string filename;
  bool isValid = false;
  bool hasOpened = false;
  ifstream wordFile("wordDictionary.txt");
  ifstream fileToCheck;
  vector<string> wordInDictionary;
  vector<string> incorrectWords;

  cout << "Program Starting... " << endl;

  while(isValid == false)
  {
    cout << "Enter the name of the file that contains words to check: ";
    cin >> filename;

    fileToCheck.open(filename.c_str());

    isValid = fileToCheck.is_open();

    if(!isValid)
    {
      cout << "Error, file name incorrect!" << endl;
    }
  }

  hasOpened = createDictionary(wordBag, wordFile);
  incorrectWords = spellChecker(wordBag, fileToCheck);

  wordFile.close();
  fileToCheck.close();

  wordInDictionary = wordBag.toVector();

  int size = wordBag.getCurrentSize();

  cout << "Here are the words found in dictionary:" << endl;

  for(int i = 0; i < size; i++)
  {
    cout << wordInDictionary[i] << endl;
  }

  cout << endl;
  cout << "The following words in the file \"wordTest.txt\" are not spelled correctly:" << endl;

  for(int i = 0; i < incorrectWords.size(); i++)
  {
    cout << incorrectWords[i] << endl;
  }

  cout << endl;
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
//                        createDictionary Function
////////////////////////////////////////////////////////////////////////////////
bool createDictionary(DLinkedBag<string>& dictionary, ifstream& file)
{
  bool hasOpened = file.is_open();
  string word;

  while(file >> word)
  {
    dictionary.add(word);
  }

  return hasOpened;
}

////////////////////////////////////////////////////////////////////////////////
//                          spellChecker Function
////////////////////////////////////////////////////////////////////////////////
vector<string> spellChecker(DLinkedBag<string>& dictionary, ifstream& file)
{
  vector<string> correctWords = dictionary.toVector();
  vector<string> incorrectWords;
  string wordToCheck;

  while(file >> wordToCheck)
  {
    string wordLowercase = wordToCheck;

    for(int i = 0; i < wordToCheck.length(); i++)
    {
      wordLowercase[i] = tolower(wordToCheck[i]);
    }

    for(int i = 0; i < dictionary.getCurrentSize(); i++)
    {
      if(wordLowercase != correctWords[i])
      {
        // Use checkSpellingOfWord for word spelling.
        if(checkSpellingOfWord(correctWords[i], wordLowercase))
        {
          incorrectWords.push_back(wordToCheck);
        }
      }
    }
  }

  return incorrectWords;
}

////////////////////////////////////////////////////////////////////////////////
//                      checkSpellingOfWord Function
////////////////////////////////////////////////////////////////////////////////
bool checkSpellingOfWord(string correctWord, string wordToCheck)
{
  bool isAlike = false;
  int correctLength = correctWord.length();
  int checkLength = wordToCheck.length();
  
  if(abs(correctLength - checkLength) > 1)
  {
    isAlike = false;
  }

  else if(abs(correctLength - checkLength) == 0)
  {
    // Checks to see if words start with same letter.
    if(correctWord[0] == wordToCheck[0])
    {
      int difference = 0;

      // Loops through ea. letter of the words.
      for(int i = 0; i < correctLength; i++)
      {
        if(correctWord[i] != wordToCheck[i])
        {
          difference++;
        }

      }

      if(difference >2)
      {
        isAlike = false;
      }
      else
      {
        isAlike = true;
      }
    }
  }

  // Check to see if the word is missing a letter.
  else if(correctLength - checkLength == 1)
  {
    int j = 0;     // To keep track of missing letters.

    for(int i = 0; i < correctLength; i++)
    {
      if(correctWord[i] != wordToCheck[i - j])
      {
        j++;
      }
    }

    if(j > 1)  // More than just one missing letter.
    {
      isAlike = false;
    }
    else        // One letter missing from the word.
    {
      isAlike = true;
    }
  }

  return isAlike;
}
