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
#include "queue.h"
#include <cmath>
using std::pow;
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

   //   cout << "no error" << endl;

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
      //    cout << token << " , " << frequency << endl;
      //use variables to create a new pair
      pair <float, string> tempPair(frequency, token);
      //insert tempPair into set
      if(!fin.eof())
      {
         pairs.push_back(tempPair);
         // cout << tempPair.first << " , " << tempPair.second << endl;
      }
   }
   

    ordered = pairs;

    // make ordered in order of frequency first then data
    //temporary variable for sorter
    pair<float, string> sortTemp;

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
    
    

    
    //create a queue to hold our huffNodes in order

    queue<HuffNode * >  huffQueue;

    //create a loop to change each pair into a huffNode and add to our queue
    for(int i = 0; i < pairs.size(); i++)
    {
       HuffNode * hn = new HuffNode(ordered[i].second, ordered[i].first);
       huffQueue.push(hn);

    }
    
/* 
    cout << "ordered pairs in the node" << endl << endl;
    
    for (int i = 0; i < pairs.size(); i++)
    {
       
       cout << huffQueue.front()->frequency << " "
            << huffQueue.front()->pHuff->data << endl;
       huffQueue.pop();
       
    }
    
    
    cout << " loop works" << endl;
    
    
    //Push Huffman queue into a single tree
    while (huffQueue.front()->frequency < (1.0))
    {
       cout << "while statement is okay" << endl;
       
       if (huffQueue.front())
       {
          cout << "if statement #1 is okay" << endl;
             
          //h0 for huffNode 0 path
          HuffNode * h0 = huffQueue.front();

          cout << "assigning h0 works" << endl;
          huffQueue.pop();
          cout << "popping off first item works" << endl;
          

          if (huffQueue.front())
          {
             
             //H1 for huffNode 1 path
             HuffNode * h1 = huffQueue.front();
             huffQueue.pop();
             
             cout << "h1 frequency" << h1->frequency << endl;
             
             // hr for huffNode root
             HuffNode * hr = new HuffNode('\0', (h0->frequency + h1->frequency));

             addLeft(hr->pHuff, h0->pHuff);
             addRight(hr->pHuff, h1->pHuff);

             huffQueue.push(hr);

          }
          else
          {
             //hr for huffNode root
             huffQueue.push(h0);
             huffQueue.pop();
             
          }


       }



    } */
    
// create a test tree

      // create
      BNode <char> * pTree = new BNode <char> ('\0');

      // add 2 to the left and 3 to the right
      addLeft(pTree, 'E');
      addRight(pTree, '\0');

      // add 6 and 7 to the right node
      addLeft(pTree->pRight, '\0');
      addRight(pTree->pRight, '\0');

      addLeft(pTree->pRight->pRight, 'D');
      addRight(pTree->pRight->pRight, 'A');

      addLeft(pTree->pRight->pLeft, 'B');
      addRight(pTree->pRight->pLeft, 'C');

    

vector<pair<char, int>> hCodes;

BNode <char> * tempNode = pTree;
bool quit = false;
int code = 0;
char token;
int level = 0;
int loop = 1;

 level = 0;
while(!quit)
{
    if(tempNode->data != '\0')
    {
    pair <char, int> *codepair = new pair <char, int>(tempNode->data, code);
        hCodes.push_back(*codepair);
        //get sibling
        tempNode = tempNode->pParent->pLeft;
        //make sure there is a token there
        if(tempNode->data != '\0')
        {
        cout << "code : " << code -1 << endl;
        pair <char, int> *codepair = new pair <char, int>(tempNode->data, code-1);
        hCodes.push_back(*codepair);
        quit = true;
        }
    }
    else
    {
        code += pow(10,level);
        level ++;
        tempNode = tempNode ->pRight;
    }
}
//go up one level
    tempNode = tempNode->pParent;
    level -=1;
    code /=100;

quit = false;
    
// go to the sibling
tempNode = tempNode->pParent->pLeft;
//code *= 10;

while(!quit)
{
    cout << "code : " << code << endl;
    
    if(tempNode->data != '\0' && !quit)
    {
        code += pow(10,level);
    pair <char, int> *codepair = new pair <char, int>(tempNode->data, code);
        hCodes.push_back(*codepair);
        //get sibling
        tempNode = tempNode->pParent->pLeft;
        //make sure there is a token there
        if(tempNode->data)
        {
        code -= 1;
        pair <char, int> *codepair = new pair <char, int>(tempNode->data, code);
        hCodes.push_back(*codepair);
        
        }
        quit = true;
        break;
    }
    else
        tempNode = tempNode ->pRight;
}
// got up a level

    tempNode = tempNode->pParent->pParent;
    level -=1;
    code /=100;

quit = false;

tempNode = tempNode->pParent->pLeft;
//code *= 10;

while(!quit)
{
    cout << "code : " << code << endl;
    
    if(tempNode->data != '\0' && !quit)
    {
    //     code += pow(10,level);
    // pair <char, int> *codepair = new pair <char, int>(tempNode->data, code);
    //     hCodes.push_back(*codepair);
    //     //get sibling
    //     tempNode = tempNode->pParent->pLeft;
    //     //make sure there is a token there
    //     if(tempNode->data)
    //     {
        code -= 1;
        pair <char, int> *codepair = new pair <char, int>(tempNode->data, code);
        hCodes.push_back(*codepair);
        
    //}
        quit = true;
        break;
    }
    else
        tempNode = tempNode ->pRight;
}




/* 
// get Leftest
while(!quit)
{
    
    if (tempNode->data)
    {
        pair <char, int> *codepair = new pair <char, int>(tempNode->data, code);
        hCodes.push_back(*codepair);
        //get sibling
        tempNode = tempNode->pParent->pRight;
        //make sure there is a token there
        if(tempNode->data)
        {
        code = 1;
        pair <char, int> *codepair = new pair <char, int>(tempNode->data, code);
        hCodes.push_back(*codepair);

        }
quit = true;
    } 
    else
        tempNode = tempNode->pLeft;
} */

// get Rightest
/* quit = false;
code = 0;
int level = 0;
int loop = 1;
tempNode = pTree;
while(!quit)
{
    
    if (tempNode->data)
    {
        pair <char, int> *codepair = new pair <char, int>(tempNode->data, code);
        hCodes.push_back(*codepair);
    } 
    else
    {
        code += loop;
        loop *=10;
        tempNode = tempNode->pRight;
    }
}
 */
for(int i=0; i < hCodes.size(); i++) {
    cout << hCodes[i].first << " , " << hCodes[i].second << endl;
};
    
    
}


