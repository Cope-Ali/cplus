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
#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

//using namespace std;
using namespace custom;

/****************************************************
 * READ FILE
 * Read in the file to be put into the map
 ****************************************************/
/*void readWordFile(map <string, int> & wordMap, const string & filename)
{
    //declare stream
    ifstream fin(filename);
// create variable to hold the inputted word
string word;

while (!fin.eof())
{
//get word from the file
fin >> word;

//check if it is already in our map increment our count 
wordMap[word]++;
}   
}
/*
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
   
   
   cout << "What word whose frequency is to be found. Typle ! when done\n";
   while(word != "!")
   {
      cin >> word;
      cout << "\t" << word << " : " << wordMap[word] << endl;
   }
}
