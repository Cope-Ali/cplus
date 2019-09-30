/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This program will prompt the user for the number of characters in
*    a sting, allocate a string of sufficient length (including end char)
*    Prompt and get the string from the user, display it back, then
*    release the memory and check for failures.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.75 hrs
*      Program went well. Just a few formatting issues for test bed but
*    I was able to get it working without much trouble
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

char *allocate (int numChar);
void getWords (char *text, int numChar);
void displayWords (const char *text, int numItems);

/**********************************************************************
 * get 
 ***********************************************************************/
int main()
{
//get number of characters from user
   int numChar;
   cout << "Number of characters: ";
   cin >> numChar;

   char *text = allocate(numChar);
   getWords(text, numChar);
   displayWords(text, numChar);

   delete [] text;
   text = NULL;

   return 0;
}

/******************************************************
* allocate memory for incoming string using the numChar
******************************************************/
char * allocate (int numChar)
{
   if (numChar < 0)
   {
      cout << "Allocation failure!\n";
      return 0;
   }

   char *p = new(nothrow) char[numChar + 1];
   if (!p)
      cout << "Allocation failure!\n";
   return p;
}


/***********************************************************
 * get line of text from user
 *************************************************************/
void getWords( char *text, int numChar)
{
   assert (text != NULL);
   assert(numChar > 0);

   cout << "Enter Text: ";
   cin.ignore();
   cin.getline(text, numChar + 1);
}

/*********************************************************
 * Display text to user
 *******************************************************/
void displayWords(const char *text, int numChar)
{
   cout << "Text: " << text << endl;
}
