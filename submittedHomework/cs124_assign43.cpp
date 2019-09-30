/***********************************************************************
* Program:
*    Assignment 43, Command Line        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This program will accept input from the command line and convert
*    feet (user input) to meters
*
*    Estimated:  0.75 hrs   
*    Actual:     0.0 hrs
*      I had a difficult time figuring out how to convert the input string
*    into something I could actually do math with. Once I figured that out
*    the rest of the program went really fast.
************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

/**********************************************************************
 * accept parameters from command line and convert into meters
 ***********************************************************************/
int main(int argc, char ** argv)
{
// Set display
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);

   //output conversions from input to meters
   double meters = 0.0;
   double feet = 0.0;
   for (int i = 1; i < argc; i++)
   {
      feet = atof(argv[i]);
      cout << feet << " feet is ";
      meters = feet * 0.3048;
      cout << meters << " meters\n";
   }
   return 0;
}
