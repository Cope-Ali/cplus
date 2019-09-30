/***********************************************************************
 * Header:
 *    Hand
 * Summary:
 *    This will contain the class definition of:
 *       hand            : a hand of cards
 * Author
 *    Ashleigh Walter & Ali Cope
 ************************************************************************/

#ifndef HAND_H
#define HAND_H
#include <string>
#include "card.h"
#include "set.h"
#include <fstream>
#include <iostream>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;

namespace custom
{
   class Hand
   {
     public:
      //create a set of cards for our hand, and an iterator to move through
      set <Card> hand;
      set <Card> :: iterator it;
 
      int match;
      int size() { return hand.size(); }

      //create our standard hand and set matches to 0
      Hand(){match = 0;}

      // read our hand of cards in from the file
      bool readHand()
      {
         char fileName[] = "/home/cs235/week05/hand.txt";
         ifstream fin(fileName);
         //check to make sure we can read the file
         if (fin.fail())
         {
            cout << "Unable to open file " << fileName << endl;
            return false;
         }
         //file is good so import as a card and insert into our <set>hand
         while (!fin.eof())
         {
            Card fish;
            fin >> fish;
            hand.insert(fish);
         }
         //close file, and return that it worked
         fin.close();
         return true;
      } 

      //check to see if the card matches a card in the hand
      void matchCheck(Card cardName)
      {
         set <Card> :: iterator itEmpty = hand.end();
         set <Card> :: iterator itFind = hand.find(cardName);
         //see if the card is in the set and not invalid
         if(itFind != itEmpty && cardName != "-INVALID-")
         {
            cout << "\tYou got a match!\n";
            match++;
            hand.erase(itFind); 
         }
         else
         {
            cout << "\tGo Fish!\n";
         }
      } 

      //display the remaining cards and the number of matches
      void display()
      {
         cout << "You have " << match << " matches!\n"
              << "The remaining cards: " ;
         
         for (it = hand.begin(); it != hand.end();)
         {
            //we dont want to display an invalid card
            if (*it != "-INVALID-")
            {
               cout << *it;
               it++;
               if (it != hand.end())
                  cout << ", ";
               else
                  cout << endl;
            }
            else
               it++;
         }
      };
   };
};
#endif // HAND_H
