/***********************************************************************
* Program:
*    Assignment 13, Expressions        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This program will convert Fahrenheit to Celsius using the following
*   equation C=5/9(F-32)
*
*    Estimated:  0.5 hrs   
*    Actual:     1.0 hrs
*      I had a difficult time getting the number to display without a decimal
*   i tried converting it to an integer several different ways but then
*   it wouldn't round correctly. I discovered that when I formatted my
*   numbers I was requiring that a decimal point always be included.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Convert inputted Fahrenheit into Celsius 
 ***********************************************************************/
int main()
{
// configure output
   cout.setf(ios::fixed);
   cout.precision(0);

// collect input of degrees fahrenheit and store as float
   cout << "Please enter Fahrenheit degrees: ";
   float degrees;
   cin >> degrees;
// convert degrees into celsius
   float c = 5.0 / 9.0 * (degrees - 32);
//display degrees in celsius
   cout  << "Celsius: " << c <<endl; 
   
   return 0;
}
