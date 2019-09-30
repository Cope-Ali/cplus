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
   vector<pair<float, string>> pairs;
   
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
       pair <float, string> tempPair(frequency, token);
       //insert tempPair into set
       pairs.push_back(tempPair);
       cout << tempPair.first << "  " << tempPair.second << endl;
    }


    //STEP 2
    Tree hTree;

//to start we need to find the two lowest pairs
pair <float,string> low1;
pair<float,string> low2;
vector<pair<float, string>> tPairs;

//while (tPairs.size())
//{
 tPairs = pairs;
//clear pairs so we can add big numbers back on
pairs.clear();
  //look for the two smallest frequency pairs    
    for (int i = 0; i < tPairs.size(); i++)
    {

        //if low1 is empty set it
        if (low1.first > 0)
        low1 = tPairs[i];

        //make sure lowest number is first
        else if(tPairs[i].first < low1.first)
        {
            //add higher value to end of vector
            tPairs.push_back(low1);
            //set low1 to new lower pair
            low1 = tPairs[i];
        }
        //make next lowest second
        // set low2 if it is empty
        else if(low2.first > 0)
        low2 = tPairs[i];
        //make sure that pairs not less than low2
        else if(tPairs[i].first < low2.first)
        { //add higher value to end of vector
            tPairs.push_back(low2);
            //set low1 to new lower pair
            low2 = tPairs[i];
        }
        else if (low2.first == tPairs[i].first)
        low2 = tPairs[i];
        //at this point the number should only be here if it is higher than both low1 and low2 so push it onto empty vector
        else
        pairs.push_back(tPairs[i]);
    }
//set lowest to the left
hTree.setLeft(low1.second);
hTree.setLFreq(low1.first);
cout << low1.first << endl;
//second lowest to the right
hTree.setRight(low2.second);
hTree.setRFreq(low2.first);
cout << low2.first << endl;
//caluclate frequency
hTree.setCombinedFrequency();
cout << hTree.getCombinedFrequecy() << endl;
//}
 //FIRST we need to add the frequency of the smaller pair to the frequency of the next pair and create another tree. If the sum of the newTreeRootNode is smaller than rootNode (which it shoudn't be) it goes on the left, if it is larger it goes on the right.

}
 


/*
--> combine the two smallest trees into a single tree
   >>> a new root is created for the new tree that has a combined frequency
   >>> the smaller goes to the left and the larger goes to the right. If they are the same then the lower token value is smaller (A - left, B - right) 
--> combine the next two smallest etc until all have been combined.
*/
    

/*
STEP 3 - Determine the Huffman Code
--> branches to the left are 0 and to the right are 1. We will have to create the codes by navigating through left and right branches and building the code as we go. So left left left is 000, left left right is 001 --> right right right 111.
--> we also have to have a way to assign the huffman code and the token to the same object. Maybe another set of pairs?

I am thinking that as we navigate through each level until we find an assigned token. it is probably going to have to be a recursive function adding a 0 if we are going down the left and adding 1 if we are gloing to the right? 
*/

/*
STEP 4 - Output Huffman Code
--> sort the token and huffman code pairs -maybe another set?
--> display the Token and Code

*/



