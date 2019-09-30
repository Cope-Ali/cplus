/***********************************************************************
* Program:
*    Assignment 14, Functions        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*   This assignment will have two functions. The first will display a message
*   the second will display an answer.

*    Estimated:  0.75 hrs   
*    Actual:     0.25 hrs
*      Things went really well with this assignment. I didn't really have
*   complications with it passing testbed beyond adjusting my linebreaks.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Display "Lord how oft shall my brother sin against me, and I forgive
 * him? Till seven times?"
 ***********************************************************************/

void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me, "
        << "and I forgive him?\n"
        << "Till seven times?\n";

   return;
}

/*******************************************************************
 * Calculate the Lord's response 7 * 70
*********************************************************************/

int responseLord()
{
   int value = 7 * 70;
   return value ;
}


/********************************************************************
 * Man will not do much here. First it will display Peter's question,
 * then it will display the Lord's answer
 *******************************************************************/

int main()
{
   //ask Peter's question
   questionPeter();

   //the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord()  << ".\n";
   
   return 0;
}
