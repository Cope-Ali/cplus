/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    Write a program to calculate that all multiples of a certain number
*    that fall between 1 and 100 are added. This is used to validate
*    Sue's brother's homework assignment.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.3 hrs
*      This was a great assignment. I felt really confident. I had one error
*    that I had to fix for it to compile. I tried to concat the response with
*    " + " instead of <<. Then I had one small error where I started my count
*    at 1 instead of zero. 
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Prompt user for which multiple we are adding, calculate and return
 * the result.
 ***********************************************************************/
int main()
{
//Receive multiple information from user
   cout << "What multiples are we adding? ";
   int multiple;
   cin >> multiple;

// create sum variable
   int sum = 0;
   
// calculate sum of multiples between 1 and 100
   for (int count = 0; count < 100; count += multiple)
      sum += count;
      
//
   cout << "The sum of multiples of " <<  multiple << " less than 100 are: "
        << sum << endl;

   return 0;
}
