/***********************************************************************
* Program:
*    Checkpoint 01b, Arrays  
*    Brother Alvey, CS165
* Author:
*    Ali Cope
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

int getSize();
int getList(int list[], int size);
void displayMultiples(int list[], int size);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int size = getSize();
   int list[20];
   getList(list, size);
   displayMultiples(list, size);
   return 0;
}

/**********************************************************************
 * Function: getSize
 * Purpose: get size of list from user
 *********************************************************************/
int getSize()
{
   cout << "Enter the size of the list: ";
   int size;
   cin >> size;
   return size;
}

/**********************************************************************
 * Function: getList
 * Purpose: get numbers for each index in the list from the user
 *********************************************************************/
int getList(int list [], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin >> list[i];
   }
   
   return 0;
}

/**********************************************************************
 * Function: displayMultiples
 * Purpose: divide each item on list by 3, if it is evenly divided,
 *          output number to user.
 *********************************************************************/
void displayMultiples(int list [], int size)
{
   cout << "\nThe following are divisible by 3:\n";
   for (int i = 0; i < size; i++)
   {
      if (list[i] % 3 == 0)
         cout << list[i] << endl;
   }
   
   return;
}
