/***********************************************************************
 * Module:
 *    Week 10, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    Ashleigh Walter, Ali Cope & George Brown
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/

#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

//using namespace std;
using namespace custom;

/****************************************************
 * READ FILE
 * Read in the file to be put into the map
 ****************************************************/
void readFile(map <string, Count> & counts, const string & fileName)
{
   
}

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
   cout << "What is the filename to be counted?\n";
   cin >> filename;
   readFile(map, filename);
   cout << "What word whose frequency is to be found. Typle ! when done\n";
   while(word != "!")
   {
      cin >> word;
   }
}
