/***********************************************************************
* Header:
*    WORD COUNT
* Summary:
*    This will contain just the prototype for the wordCount()
*    function
* Author
*    Ashleigh Walter, Ali Cope & George Brown
************************************************************************/

#ifndef WORD_COUNT_H
#define WORD_COUNT_H
#include "map.h"
#include "bst.h"
//#include "wordCount.cpp"
#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

namespace custom
{
/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
   map<string, int> wordMap;
   string filename;
   string word;
   cout << "What is the filename to be counted?"<<endl;
   cin >> filename;
   //readWordFile(wordMap, filename);
   
   //declare stream
    ifstream fin(filename);

  while (!fin.eof())
  {
//get word from the file
  fin >> word;

//check if it is already in our map increment our count 
  wordMap[word]++;
  }
   
   cout << "What word whose frequency is to be found. Type ! when done" << endl;
   while(word != "!")
   {
      cin >> word;
      cout << "\t" << word << " : " << wordMap[word] << endl;
   }


};
}
//};
#endif // WORD_COUNT_H

