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


queue <HuffNode *>  sortQueue(queue <HuffNode * > huffQueue)
{
   queue <HuffNode * > newQueue;

   
   
   while(!huffQueue.empty())
   {
      cout << "Starting size" << huffQueue.size() << endl;
         //h0for huffNode 0 path
         HuffNode * h0 = huffQueue.front();

         cout << "h0 frequency" << h0->frequency << endl;
         
         huffQueue.pop();

         if (huffQueue.empty())
            newQueue.push(h0);
         
         
         else
         {
            cout << "got into the if";
            //H1 for huffNode 1 path
            HuffNode * h1 = huffQueue.front();
            huffQueue.pop();
            
            cout << "h1 frequency" << h1->frequency << endl
                 << "size " << huffQueue.size() << endl;
            
            
            // hr for huffNode root
            HuffNode * hr = new HuffNode("",  h0->frequency + h1->frequency);
            
            //hr->frequency = fSum;
            
            cout << "h0 and h1 frequencies are " << h0->frequency << " and "
                 << h1->frequency << " added they are "
                 << (h0->frequency + h1->frequency) << endl;
            
            cout << "hr frequency" << hr->frequency << endl;
            
            addLeft(hr->pHuff, h0->pHuff);
            addRight(hr->pHuff, h1->pHuff);
            
            cout << "hr node has been assigned" << endl;
            
            
            newQueue.push(hr);
            
            cout << "and is back in the queue for the next time" << endl;
            

         }
         
        
         

   }

      return newQueue;

   
}

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
    

    cout << "ordered pairs in the node" << endl << endl;

    queue <HuffNode * > newQueue = huffQueue;
    
    for (int i = 0; i < pairs.size(); i++)
    {
       
       cout << newQueue.front()->frequency << " "
            << newQueue.front()->pHuff->data << endl;
       newQueue.pop();
       
    }
    
    
    //Push Huffman queue into a single tree
    while (huffQueue.front()->frequency < (1.0))
    {
       queue <HuffNode * > newQueue = sortQueue(huffQueue);

       huffQueue = newQueue;
       
       
    }
    



    
    
}


