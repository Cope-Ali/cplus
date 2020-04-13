/***********************************************************************
* Program:
*    Lab 11, name
*    Brother Wilson, CS470
* Author:
*    Ali Cope
* Summary: 
*    Please include a detailed description of:
*    1. This program will determine how many guesses it would
*       take to guess a password
*    2. Passwords will be checked char by char to see if they 
*        contain upper, lower, numerical and symbol characters
*    3. The user will provide a password to be checked
*    4. Citations if the algorithm was borrowed or inspired from any source
************************************************************************/

#include <cmath>
#include <string>
#include <iostream>
using namespace std;

/******************************************************
 * LOWER
 * This function will check if a string contains a 
 * lowercase letter
 *****************************************************/
int lower(string text)
{
   for (int i = 0; i < text.length(); i++)
   {
      if (islower(text[i]))
      {
         return 26;
      }
   }
   return 0;
}

/******************************************************
 * UPPER
 * This function will check if a string contains an upper
 * case letter
 *****************************************************/
int upper(string text)
{
   for (int i = 0; i < text.length(); i++)
   {
      if (isupper(text[i]))
      {
         return 26;
      }
   }
   return 0;
}

/******************************************************
 * NUMBER
 * This function will check if a string contains a number
 *****************************************************/
int number(string text)
{
   for (int i = 0; i < text.length(); i++)
   {
      if (isdigit(text[i]))
      {
         return 10;
      }
   }
   return 0;
}

/******************************************************
 * SYMBOL
 * This function will check if a string contains a symbol
 *****************************************************/
int symbol(string text)
{
   char symbols [] = {'!','\\','"','#','$','%','&',',','\'',
      '(',')','*','+','-','.','/',':',';','<','=','>','?','@',
      '[','\\',']','^','_','`','{','|','}','~',};
   for (int i = 0; i < text.length(); i++)
   {
      for (int j = 0; j < sizeof (symbols); j++)
      {
         if (text[i] == symbols[j])
         {
            return 32;
         }
      }
   }
   return 0;
}

/******************************************************
 * BITS
 * This function will determine how many bits for a long
 * number 
 *****************************************************/
int getBits(long combo)
{
   for (int i = 1; i < 100; i++)
   {
      if (pow(2,i) < combo && pow(2, i + 1) > combo)
         return i;
   }
   return 0;
}

/******************************************************
 * MAIN
 * This function will receive a password (string) from
 * the user, call each function, and return how many 
 * guesses it would take to guess the password
 *****************************************************/
int main()
{
   string text;
   cout << "Please enter the password: ";
   cin >> text;

   long guesses = 0;
   guesses = lower(text) + upper(text) + number(text) + symbol(text);
   long total;
   total = pow(guesses, text.length());
   cout << "There are " << total << " combinations\n";
   int bits;
   bits = getBits(total);

   cout << "That is equivalent to a key of " << bits << " bits\n";

}