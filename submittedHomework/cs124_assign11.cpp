/***********************************************************************
* Program:
*    Assignment 11, Output Monthly Budget        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This assignment is to output a monthly budget. Its focus is on the
*    correct formatting of numbers and alignment of text.
*
*    Estimated:  0.75 hrs   
*    Actual:     2.O hrs
*
*    This assignment took me much longer to complete. In part because I
*    am still getting used to this program, but mostly I had a hard time
*    getting the second column to line up without using the \t command
*    then I had a really hard time getting it to pass the styleChecker
************************************************************************/

#include <iostream>  //required for COUT
#include <iomanip>   //required for setw()
using namespace std;

/********************************************************************
*   The main function will display the budget in the correct format
*   and laid out in an easy to read way
******************************************************************/
int main () 
{
   //format the output for money
   cout.setf(ios::fixed); // no scientific notation
   cout.setf(ios::showpoint); //always show decimal
   cout.precision(2); //number formatted to two decimal places

/**********************************************************************
 * numbers displayed in columns
 *********************************************************************/

   cout << "\tItem" << setw(21) << "Projected\n";
   cout << "\t=============  ==========\n";
   cout << "\tIncome" << setw(10) << "$"  << setw(9) << 1000.00 << endl;
   cout << "\tTaxes" << setw(11) << "$" << setw(9) << 100.00 << endl; 
   cout << "\tTithing" << setw(9) << "$" << setw(9) << 100.00 << endl;
   cout << "\tLiving" << setw(10) << "$" << setw(9) << 650.00 << endl;
   cout << "\tOther" << setw(11) << "$" << setw(9) << 90.00 << endl;
   cout << "\t=============  ==========\n";
   cout << "\tDelta" << setw(11) << "$" << setw(9) << 60.00 << endl;
   return 0;
}
