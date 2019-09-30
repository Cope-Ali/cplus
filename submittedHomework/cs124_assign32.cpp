/***********************************************************************
* Program:
*    Assignment 32, Strings        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This program will count the number of times a user chosen letter
*    appears in a user provided string.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.5 hrs
*      This assignment was pretty straight forward. No major issues just
*     reviewing the developers forum for better understanding of cin.ignore
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* counts the number of times a letter appears in a string
**********************************************************************/
int countLetters(char letter, char text[])
{
   int numLetters = 0;
   for (int i = 0; text[i]; i++)
      if (text[i] == letter)
         numLetters ++ ;
   return numLetters;
}


/**********************************************************************
 * prompts user for a letter and a line of input and calls countLetters()
 ***********************************************************************/
int main()
{
   char letter;
   char text[256];
   cout << "Enter a letter: ";
   cin >> letter;
   cin.ignore();
   cout << "Enter text: ";
   cin.getline(text, 256);
   int numLetters = countLetters(letter, text);
   cout << "Number of '" << letter << "'s: " << numLetters << endl;
   return 0;
}
