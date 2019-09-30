/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Helfrich, CS 235
* Author:
*    Ali Cope & Ashleigh Walter
* Summary: 
*    This is all the functions necessary to play Go Fish!
*
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
// create a hand of cards
   Hand myHand;
   //call readHand() to upload cards into hand
   myHand.readHand();
   //Instructions to player
   cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand\n";

   Card cardName;
   //play 5 rounds and check each round if it matches a card in the hand.
   for(int round = 1; round <= 5; round++)
   {
      cout << "round " << round << ": ";
      cin >> cardName;
      myHand.matchCheck(cardName);
   }
   //display the results of the game.
   myHand.display();
   }
