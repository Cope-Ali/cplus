/***********************************************************************
* Program:
*    Checkpoint 01a, C++ Basics  
*    Brother Alvey, CS165
* Author:
*    Ali Cope
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   cout << "Hello CS 165 World!\n";

   string name;
   int age;

   cout << "Please enter your first name: ";
   cin >> name;

   cout << "Please enter your age: ";
   cin >> age;

   cout << "\nHello " << name << ", you are " << age << " years old.\n"; 
   return 0;
}
