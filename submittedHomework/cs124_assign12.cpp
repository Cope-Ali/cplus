/***********************************************************************
* Program:
*    Assignment 12, Get Income and Display
*    Brother Honeycutt, CS 124: 13
* Author:
*    Ali Cope
* Summary: 
*    This program will ask the user o input their monthly income, and then
*    will output the income to the user.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.50 hrs
*      This assignment wasn't too bad. I think I am starting to get the hang
*    of how Linux and C++ work. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * ask user to input income and display their inputted income
 ***********************************************************************/
int main()
{
   
// set number formatting to display money with two digits after decimal
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

// declare variable
   float income;

// get income from user and assign it to "income" variable   
   cout << "\tYour monthly income: ";
   cin >> income;

// display the inputted income
   cout << "Your income is: $"
        << setw(9)
        << income
        << "\n";

   return 0;
}
