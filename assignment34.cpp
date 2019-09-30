/***********************************************************************
* Program:
*    Assignment 34, Pointer Arithmetic        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This program will count the number of times a user chosen letter
*    appears in a user provided string using pointers.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.75 hrs
*     The most difficult part of this assignmet was dealing with the pointer
*     syntax and understanding when to use the * and when not to. 
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* counts the number of times a letter appears in a string
**********************************************************************/
int countLetters(char letter, char text[])
{
   char * pLetter;
   char * pText;
   int numLetter = 0;
   for (pLetter = &letter, pText = text; *pText; pText++)
      if (*pText == *pLetter)
         numLetter++ ;
   return numLetter;
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
   int letterCount = countLetters(letter, text);
   cout << "Number of '" << letter << "'s: " << letterCount << endl;
   return 0;
}
