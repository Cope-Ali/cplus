/***********************************************************************
* Program:
*    Project 02, Monthly Budget
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This is a project to manage personal finances for a month. This first
*    version of this program will accept user input and display in an
*    easy to read format. Future versions of this program will include
*    calculations
*
*    Estimated:  2.0 hrs   
*    Actual:     3.0 hrs
*      I ran into some errors compiling and i couldn't understand what
*      the error was. I looked at the book, I looked at examples and I
*      couldn't understand what I was missing. I finally figured it out
*      watching the class videos. Then my only problem was missing spaces
*      at the end of each : 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * User inputs budget and actual numbers. Program outputs an easy to read
 * report utilizing the user input.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed); //no scientific notation
   cout.setf(ios::showpoint); // show decimal
   cout.precision(2); // show cents or 2 digits after decimal

   // define variables

   float income;
   float bliving; // budgeted living expenses
   float aliving; // actual living expenses
   float ataxes; // actual taxes
   float atithing; // actual tithing
   float aother; // actual other expenses

   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";

   // prompt for monthly income
   cout << "\tYour monthly income: ";
   cin >> income;

   // prompt for budgeted living expenses
   cout << "\tYour budgeted living expenses: ";
   cin >> bliving;

  // prompt for actual living expenses
   cout << "\tYour actual living expenses: ";
   cin >> aliving;

   // prompt for actual taxes
   cout << "\tYour actual taxes withheld: ";
   cin >> ataxes;

   // prompt for actual tithing
   cout << "\tYour actual tithe offerings: ";
   cin >> atithing;

   // prompt for actual other expenses
   cout << "\tYour actual other expenses: ";
   cin >> aother;

   // display monthly expense report title
   cout << "\nThe following is a report on your monthly expenses\n";

   // display column headings
   cout << "\tItem"
        << setw(24) << "Budget"
        << setw(17) << "Actual\n";

   // display  line
   cout << "\t=============== =============== ===============\n";

   // display income line
   cout << "\tIncome"
        << setw(11) << "$"
        << setw(11) << income
        << setw(5) << "$"
        << setw(11) << income
        << endl;

  // display taxes line
   cout << "\tTaxes"
        << setw(12) << "$"
        << setw(11) << 0.00
        << setw(5) << "$"
        << setw(11) << ataxes
        << endl;

   // display tithing line
   cout << "\tTithing"
        << setw(10) << "$"
        << setw(11) << 0.00
        << setw(5) << "$"
        << setw(11) << atithing
        << endl;
      
   // display living line
   cout << "\tLiving"
        << setw(11) << "$"
        << setw(11) << bliving
        << setw(5) << "$"
        << setw(11) << aliving
        << endl;

   // display other line
   cout << "\tOther"
        << setw(12) << "$"
        << setw(11) << 0.00
        << setw(5) << "$"
        << setw(11) << aother
        << endl;

   // display  line
   cout << "\t=============== =============== ===============\n";
       
   // display difference line
   cout << "\tDifference"
        << setw(7) << "$"
        << setw(11) << 0.00
        << setw(5) << "$"
        << setw(11) << 0.00
        << endl;

   return 0;
}
