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
       //use variables to create a new pair
       pair <float, char> tempPair(frequency, token);
       //insert tempPair into set
       pairs.push_back(tempPair);
    }


    //STEP 2
    
   /*  BNode <char> * tree;
    BNode <char> * node;
    vector<char> ordered;
    
    for (int i = 0; i < pairs.size(); i++)
    {
       for(int x = 0; i < pairs.size(); i++)// dont we need to have x here not i
       {
          if(pairs[x].first < pairs[i].first)
          {
             ordered.push_back(pairs[x].second);

          }
       }

    } */
       
    
/*
STEP 2 - Generate Huffman Trees
--> each token is assigned it own binary tree
*/

//create root node

 float sumFrequency;
 char leftToken;
 char rightToken;

//save first item
 sumFrequency = pairs.data->first;
 leftToken = pairs.data->second;

//delete the first item in the vector
delete [] pairs.data; 

//save first item (was second)
sumFrequency = sumFrequency + pairs.data->first;
rightToken = pairs.data->second;

//delete the first item in the vector
delete [] pairs.data; 

//create root
 BNode <char> * rootNode = new BNode <char> ('.');

 //add to left and right
    addLeft(rootNode, new BNode <char> (leftToken));
  addRight(rootNode, new BNode <char> (rightToken));

/* 
while(pairs.size())
{

pair <float,char> tempPairL = new pair(pairs.data->first, pairs.data->second);
  BNode <pair<float, char>> * leftNode = new BNode <pair<float,char>>(tempPairL);

//delete the first item in the vector
delete [] pairs.data; 

//create the second node
pair <float,char> tempPairR = new pair(pairs.data->first, pairs.data->second);
    BNode <pair <float, char>> * rightNode = new BNode <pair<float,char>>(tempPairR);

//delete the second item in the vector
delete [] pairs.data; 

//get sum of left and right nodes frequency
float sumFrequency = leftNode->data.first + rightNode->data.first;
    //create new node that will be the root of the tree
    BNode <float> * rootNode = new BNode <float> (sumFrequency);
    //add left and right Nodes
    addLeft(rootNode, leftNode->data.second);

   addRight(rootNode, new BNode <char> (rightNode->data.second));
 */
//Next we need to compare the frequency of the rootNode with the next node in the pairs vector. If it is larger we combine them with the rootNode on the left and the next on the right. If it is smaller we have to do two things. FIRST we need to add the frequency of the smaller pair to the frequency of the next pair and create another tree. If the sum of the newTreeRootNode is smaller than rootNode (which it shoudn't be) it goes on the left, if it is larger it goes on the right.

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



