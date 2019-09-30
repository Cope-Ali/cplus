/***********************************************************************
* Program:
*    Checkpoint 03b, Errors 
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
int prompt()
{
   int number;
   bool done = false;
do
{
   cout << "Enter a number: ";
   cin >> number;
   if (cin.fail())
   {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Invalid input." << endl;
   }
   else
      done = true;
}
while (!done);

return number;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int num = prompt();
   cout << "The number is " << num << ".\n";
   return 0;
}
