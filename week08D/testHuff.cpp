/***********************************************************************
 * Implementation:
 *    HUFFMAN
 * Summary:
 *    This will contain the implementation for huffman()
 * Author
 *    Ashleigh Walter, Ali Cope & George Brown
 **********************************************************************/

#include <iostream>
#include <fstream>
#include "huffman.h" // for huffman() prototype
#include "bnode.h"      // for BNode
#include "pair.h"
#include "vector.h"
#include "tree.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ifstream;
using custom::pair;
using custom::set;
//using namespace std;
using namespace custom;

/************************************************
 * HUFFMAN
 * The interactive function allowing the user to
 * display huffman codes
 ***********************************************/
void huffman(string filename)
{
    /* 
STEP 1 --TESTED AND COMPLETE information is being read in and saved as a pair
--> Read file contents into a set of pairs
--> each pair has a token (A,B,C etc.) and a frequency (0.2etc)
--> Set will automatically sort by the smallest frequency
*/

//create set of pairs
   vector<pair<float, char>> pairs;
   
    //declare output stream
    ifstream fin(filename);
   
   // read the file save as set of pairs
    while (!fin.eof())
    {
// create our token and frequency variables
       char token;
       float frequency;
       // store data from file in variables
       fin >> token;
       fin >> frequency;
       cout << token << " , " << frequency;
       //use variables to create a new pair
       pair <float, char> tempPair(frequency, token);
       //insert tempPair into set
       if(!fin.eof())
          pairs.push_back(tempPair);
    }

    ordered = pairs;

    // make ordered in order of frequency first then data
    //temporary variable for sorter
    pair<float, char> sortTemp;

    for(int i = 0; i < (ordered.size() -1); i++)
    {

       for(int j = (i+1); j < (ordered.size()); j++)
       {
          if(ordered[i].first > ordered[j].first)
          {
             sortTemp = ordered[i];

             ordered[i] = ordered[j];
             ordered[j] = sortTemp;

          }

          else if(ordered[i].first == ordered[j].first)
          {
             if(ordered[i].first > ordered[j].first)
             {
                sortTemp = ordered[i];

                ordered[i] = ordered[j];
                ordered[j] = sortTemp;


             }
          }
       }

    }

    //display to test organization
    cout << " Here is the file as we read into vector pairs\n";

    for(int i = 0; i < pairs.size(); i++)
    {
       cout << pairs[i].first << " " << pairs[i].second << endl;


    }

    cout << endl;
    cout << "Here is the ordered vector:\n";

    for(int i = 0; i < pairs.size(); i++)
    {
       cout << ordered[i].first << " " << ordered[i].second << endl;


    }
    
    

    
    
}


