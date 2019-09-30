/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions 
*    Brother Alvey, CS165
* Author:
*    Ali Cope
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * Function: prompt
 * Purpose: prompt the user for a number and returns it
 ***********************************************************************/
int prompt() throw(string)
{
   int number;
   cout << "Enter a number: ";
   cin >> number;
   if(number < 0)
      throw string("The number cannot be negative.");
   if(number > 100)
      throw string("The number cannot be greater than 100.");
   if(number % 2 == 1)
      throw string("The number cannot be odd.");
return number;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   try
   {
      int number = prompt();
      cout << "The number is " << number << ".\n";
   }
   catch (string message)
   {
      cout << "Error: " <<  message << endl;
   }

   return 0;
}
