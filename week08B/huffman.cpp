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
//#include "huffnode.h"
#include "queue.h"
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
    cout << filename << endl;
    /* 
STEP 1 --TESTED AND COMPLETE information is being read in and saved as a pair
--> Read file contents into a set of pairs
--> each pair has a token (A,B,C etc.) and a frequency (0.2etc)
--> Set will automatically sort by the smallest frequency
    */

//create set of pairs


   vector<pair<float, string>> pairs;
   vector<pair<float, string>> ordered;
   
    //declare output stream
   ifstream fin(filename);
   
   // read the file save as set of pairs
   while (!fin.eof())
   {
      // create our token and frequency variables
      string token;
      float frequency;
      // store data from file in variables
      fin >> token;
      fin >> frequency;
      //use variables to create a new pair
      cout << token << " , " << frequency << endl;
      pair <float, string> tempPair(frequency, token);
      //insert tempPair into set
      if(!fin.eof())
         pairs.push_back(tempPair);
      
   }
/*
   ordered = pairs;
   
    // make ordered in order of frequency first then data
    //temporary variable for sorter
    pair<float, string> sortTemp;

    //will put in pairs in ascending order
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
    /*cout << " Here is the file as we read into vector pairs\n";
    
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
     
//create a queue to hold our huffNodes in order

queue<HuffNode> * huffQueue = new queue<HuffNode>;
    
//create a loop to change each pair into a huffNode and add to our queue    
for(int i = 0; i < pairs.size(); i++)
{
HuffNode * hn = new HuffNode(pairs[i].second,pairs[i].first);
huffQueue->push(*hn);



}
   

    /*
    //right and left nodes
    pair<float, char> s0;
    pair<float, char> s1;

    //vector to collect the nodes with Leaves
    // vector <BNode<pair<float, char> > * > pLeafNodes;
    vector <BNode<pair<float, char> > * > LpNodes;
    int ip = 0;
    
    //Huffman
    for(int i = 0; i < ordered.size();)
    {
       //smallest is always first once sorted
       
       s0 = {ordered[i].first, ordered[i].second};
       i++;
       //second smallest is sorted
       
       s1 = {ordered[i].first, ordered[i].second};
       i++;
       
       //BNode <pair<float, char>> * TempTri = new BNode <pair<float, char>>;
          
       
       //pLeafNodes[ip].push_back(pTempTri);       
       //pLeafNodes.push_back(*pTempTri);

       //BNode <pair<float, char>> * ps0 = new BNode <pair<float, char>>;
       //ps0->data = s0;
       
       //   addLeft(pLeafNodes[ip], *s0);
       // addLeft(pLeafNodes, s0);
       //addRight(pLeafNodes[ip],s1);
       //ip++;
          
          
    }
    */

    //ToDo link up all leaf nodes.
   



    
}


