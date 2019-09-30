/***********************************************************************
* Program:
*    Assignment 25, Loop Design        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*   This assignment creates a calendar for the user, using the supplied
*   offset and number of days. 
*
*    Estimated:  2.0 hrs   
*    Actual:     0.25 hrs
*     I had already completed Project 07 to test my pseudocode from last
*     week so it took very little time to adjust that code for this
*     assignment. Last week however I spent probably about 6 hours total
*     on the entire code for the project. Thanks to the pseudocode
*     assignment I was able to find a more effective loop to output the
*     days.
*
*
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// declare all functions
int getNumDays();
int getOffset();
void displayTable(int offset, int numDays);

/**********************************************************
 * Get number of days from user
*********************************************************/
int getNumDays()
{
   int numDays = 0;
   cout << "Number of days: ";
   cin >> numDays;
   return numDays;
}

/**************************************************************
 * Get offset from user
 ************************************************************/
int getOffset()
{
   int offset = 0;
   cout << "Offset: ";
   cin >> offset;
   if (offset == 6)
      offset = 0;
   else
      offset ++ ;
   return offset;
}

/**************************************************************
* Table display with day heading and number of days
*************************************************************/
void tableDisplay(int offset, int numDays)
{
// header row
   cout << setw(4) << "Su" << setw(4) << "Mo" << setw(4) << "Tu"
         << setw(4) << "We" << setw(4) << "Th" << setw(4) << "Fr"
       << setw(4) << "Sa" << endl;
//main body
   cout << setw((offset * 4) + 4) << "1";
   int day = 2;
   int count = offset + 1; 
   do
   {
      if (count < 7)
      {
         cout << setw(4) << day;
         day ++ ;
         count ++ ;
      }
      else
      {
         cout << endl;
         count = 0;
      }
   }
   while (day <= numDays);
   cout << endl;
}

/**************************************************************
 * call functions to run
 ************************************************************/
int main()
{
   int numDays = getNumDays();
   int offset = getOffset();
   tableDisplay(offset, numDays);
   return 0;
}

