/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Alvey, CS165
* Author:
*    Ali Cope
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/

#include <vector>
#include <iostream>
#include <string>
using namespace std;



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
    // vector of ints
vector <int> items;

int number;
cout << "Enter int: ";
cin >> number;

do
{
    items.push_back(number);
    cout << "Enter int: ";
    cin >> number;
    
}
while(number !=0);

// output the list of numbers
cout << "Your list is: " << endl;
for (vector <int> :: iterator it = items.begin();
it < items.end(); it++)
cout << *it << endl;

// vector of strings
vector <string> words;

string word;
cout << "Enter string: ";
cin >> word;

do
{
    words.push_back(word);
    cout << "Enter string: ";
    cin >> word;
    
}
while(word !="quit");

// output the list of strings
cout << "Your list is: " << endl;
for (vector <string> :: iterator it = words.begin();
it < words.end(); it++)
cout << *it << endl;

   return 0;
}


