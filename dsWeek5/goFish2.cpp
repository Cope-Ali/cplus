/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Helfrich, CS 235
* Author:
*    <your names here>
* Summary: 
*    This is all the functions necessary to play Go Fish!
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "set.h"
#include "card.h"
#include "goFish.h"
#include "hand.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;

/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/
void goFish()
{
   // Hand myHand;
   set <Card> hand;
   set <Card> :: iterator it;
   char fileName[] = "/home/cs235/week05/hand.txt";
//   myHand.readHand("/home/cs/week05/hand.txt");

   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Unable to open file " << fileName << endl;
   }
   while (!fin.eof())
   {
      Card fish;
      fin >> fish;
      hand.insert(fish);
   }
   fin.close();
   
   cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand\n";

   //string cardName;
   Card cardName;
   int match = 0;

   for(int round = 1; round <= 5; round++)
   {
      cout << "round " << round << ": ";
      cin >> cardName;
      //set <string> :: iterator itEmpty = myHand.hand.end();
      //set <string> :: iterator itFind = myHand.hand.find(cardName);
      set <Card> :: iterator itEmpty = hand.end();
      set <Card> :: iterator itFind = hand.find(cardName);
    
      if (itFind != itEmpty)
      {   cout << "\tYou got a match!\n";
         match++;
         //myHand.hand.erase(itFind); 
         hand.erase(itFind);
         }
      else
      {
         cout << "\tGo Fish!\n";
      }
   }
   cout << "You have " << match << " matches!\n" << "The remaining cards: " ;

   // iterator to go through the cards and output each
   // one until finished
   for (it = hand.begin(); it != hand.end();)
   {
      cout << *it;
      it++;

      if (it != hand.end())
         cout << ", ";
      else
         cout << endl;
   }
}
