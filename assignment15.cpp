/***********************************************************************
* Program:
*    Assignment 15, Full Tithe Payer
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This program will compute if a user is a full tithe payer using
*    the complicated formula provided in the scriptures:
*        And after that, those who have thus been tithed shall 
*        pay one-tenth of all their interest annually; and this 
*        shall be a standard law unto them forever, for my holy 
*        priesthood, saith the Lord.  D&C 119:4
*
*    Estimated:  0.75 hrs   
*    Actual:     0.15 hrs
*      At first I thought I needed to convert the money into cents
*   once I discovered that was unnecessary it was not very difficult.
*   I was also expecting to have to use an if/then type statement to
*   evaluate, like you do in JS, but instead I could evaluate in the
*   return statement because it was a bool function.
************************************************************************/

#include <iostream>
using namespace std;

/*****************************************************
 * determines if tithe is >= to 10 percent of income
 *****************************************************/
bool isFullTithePayer(float income, float tithe)
{
   return ((income / 10 ) <= tithe);

}


/**********************************************************************
 * Main will call isFullTithePayer() and display an appropriate message
 * to the user based on the results
 ***********************************************************************/
int main()
{
   float income;
   float tithe;

   // prompt user for income
   cout << "Income: ";
   cin  >> income;

   // prompt user for tithe
   cout << "Tithe: ";
   cin  >> tithe;

   // give the user his tithing report
   if (isFullTithePayer(income, tithe))
      cout << "You are a full tithe payer.\n";
   else
      cout << "Will a man rob God?  Yet ye have robbed me.\n"
           << "But ye say, Wherein have we robbed thee?\n"
           << "In tithes and offerings.  Malachi 3:8\n";

   return 0;
}
