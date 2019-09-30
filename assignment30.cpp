/***********************************************************************
* Program:
*    Assignment 30, Array Syntax        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    Prompt user for ten grades, average them together and return the average
*    This will use an array and three functions getGrades(), averageGrades()
*    and a main function.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.3 hrs
*      I had a few syntax errors, but for the most part after referencing the
*    text and examples during the process I was able to complete the project
*    without much trouble. The weekly announcement video helped also.
************************************************************************/

#include <iostream>
using namespace std;

void getGrades();
int averageGrades();

/*******************************************************************
 * get grades from user
 ******************************************************************/
void getGrades(int grades[])
{
   for (int i = 0; i < 10; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grades[i];
   }
}

/*********************************************************************
 * average grades together
 ******************************************************************/
int averageGrades(int grades[])
{
   int average = 0;
   for (int i = 0; i < 10; i++)
   {
      average += grades[i];
   }
   return average / 10;
}

/**********************************************************************
 * Call all functions and display average to user
 ***********************************************************************/
int main()
{
   int grades[10];
   getGrades(grades);
   int average = averageGrades(grades);
   cout << "Average Grade: " << average << "%\n";
   return 0;
}
