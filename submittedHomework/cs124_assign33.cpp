/***********************************************************************
* Program:
*    Assignment 33, Pointers        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This program will ask for account balances for both Sue and Sam.
*    The program will then determine which account has a larger balance
*    using pointers the program will deduct the cost of the date and return
*    the new account balance
*
*    Estimated:  0.75 hrs   
*    Actual:     0.5 hrs
*      This assignment went pretty well. I had to refer to the book a few
*      time to determine when to use * and when to use &
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* Get cost of date from user and subtract from account balance
**********************************************************************/
void date(float * pAccount)
{
//create variables
   float dinner;
   float movie;
   float iceCream;
   cout << "Cost of the date:\n"
        << "\tDinner:    ";
   cin >> dinner;
   cout << "\tMovie:     ";
   cin >> movie;
   cout << "\tIce cream: ";
   cin >> iceCream;

//subtract date from account balance
   *pAccount -= (dinner + movie + iceCream);
}

/*************************************************************************
* get account balance, create pointers  call function and return balance
***********************************************************************/
int main()
{

//create variables
   float samBalance;
   float sueBalance;

//get user input
   cout << "What is Sam's balance? ";
   cin >> samBalance;
   cout << "What is Sue's balance? ";
   cin >> sueBalance;

// create pointer
   float * pAccount;

// determine which balance is higher and assign to pointer
   if (samBalance > sueBalance)
      pAccount = &samBalance;
   else
      pAccount = &sueBalance;
   
// call function
   date(pAccount);

// display final account balance
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "Sam's balance: $" << samBalance << endl
        << "Sue's balance: $" << sueBalance << endl;
   
   return 0;
}
