/***********************************************************************
* Program:
*    Assignment 16, If Statements        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This program will have two functions. The first will receive the
*    the users income and will output their tax bracket. The second
*    will evaluate the income to determine the tax bracket using if
*    statements.

*    Estimated:  0.75 hrs   
*    Actual:     0.5 hrs
*      This assignment went really well. I knew just what to do and I had
*    only one minor compiling issue (a missing ; ) It took me a few tries
*    to get the correct spaces for testBed, but no real issues on styleChecker
*    either. It is wonderful to feel like I am really grasping what we are
*    learning.
************************************************************************/

#include <iostream>
using namespace std;

int computeTax(int income);

/**********************************************************************
 * Ask the user for their income and display their tax bracket
 ***********************************************************************/
int main()
{
   cout << "Income: ";
   int income;
   cin >> income;

// runs the computeTax function to determine tax percentage
   int tax = computeTax(income);
   cout << "Your tax bracket is "
        << tax
        << "%\n";
   return 0;
}

/***************************************************************
 * Calculates tax bracket using income
 **************************************************************/
int computeTax(int income)
{
   int tax = 0;
   if (income <= 15100)
      tax = 10;

   else if (income <= 61300)
      tax = 15;

   else if (income <= 123700)
      tax = 25;
   
   else if (income <= 188450)
      tax = 28;
   
   else if (income <= 336550)
      tax = 33;
   
   else
      tax = 35;
   return tax;
}
