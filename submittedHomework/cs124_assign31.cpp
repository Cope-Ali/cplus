/***********************************************************************
* Program:
*    Assignment 31, Array Design        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    Modify assignment 30 so that it does not take into account grades with
*    the value of -1. Handle the condition where there are no grades and no
*    average to output.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.25 hrs
*      I had a little trouble figuring out how to do the if statement
*    to check for all -1 grades. I wanted to pass back a string but couldn't
*    because the function was an int. So instead I passed back a 0 and
*    changed the string in the main function.
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
   int numGrades = 0;
   for (int i = 0; i < 10; i++)
   {
      if (grades[i] >= 0)
      {
         average += grades[i];
         numGrades += 1;
      }
   }
   if (numGrades > 0)
      return average / numGrades;
   else
      return 0;
}

/**********************************************************************
 * Call all functions and display average to user
 ***********************************************************************/
int main()
{
   int grades[10];
   getGrades(grades);
   int average = averageGrades(grades);
   if (average > 0)
      cout << "Average Grade: " << average << "%\n";
   else
      cout << "Average Grade: ---%\n";
   return 0;
}
